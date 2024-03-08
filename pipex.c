/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:15:31 by rileone           #+#    #+#             */
/*   Updated: 2024/03/06 15:05:38 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int ft_initialize(t_pipex *var, int argc, char **argv)
{
	char *envstring;
	char **envmtx;
	int i;
	
	i = -1;
	if(pipe(var->pipe) == -1)
		return (0);
	envstring = getenv("PATH");
	if(!envstring)
		return (0);
	envmtx = ft_split(envstring, ':');
	if(envmtx == NULL)
	{
		free(envstring);
		ft_clear_mtx(&var->env, mtx_count_rows(var->env));
		ft_clear_mtx(&envmtx, mtx_count_rows(envmtx));
		return (0);
	}
	var->env = ft_calloc(mtx_count_rows(envmtx) + 1, sizeof(char *));
	if (var->env == NULL)
		return (0);
	while(envmtx[++i] != NULL)
		var->env[i] = ft_strjoin(envmtx[i], "/");
	var->fd = open(argv[1], O_RDONLY);
	var->fd2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_clear_mtx(&envmtx, mtx_count_rows(envmtx));
	if (var->fd == -1 || var->fd2 == -1)
		return (0);
		ft_printf("sonoqui");
	return (1);
}

char *ft_return_cmd(t_pipex *var, char **argv)
{
	int i;
	char	*tmpcmd;

	i = 0;
	var->cmd = ft_split(argv[var->counter + 2], ' ');
	if(var->cmd == NULL)
		return (0);
	while(var->env && var->env[i] != NULL)
	{
		tmpcmd = ft_strjoin(var->env[i], var->cmd[0]);
		if(access(tmpcmd, 0) == 0)
		{
			ft_clear_mtx(&var->cmd, mtx_count_rows(var->cmd));
			return (tmpcmd);
		}
		i++;
		free(tmpcmd);
		tmpcmd = NULL;
	}
	ft_clear_mtx(&var->cmd, mtx_count_rows(var->cmd));
	return (NULL);
}
int ft_execute_son(t_pipex *var)
{
	if(var->counter == 0)
	{
		dup2(var->fd, STDIN_FILENO);
		dup2(var->pipe[1], STDOUT_FILENO);
		close(var->pipe[0]);
	}
	else 
	{
		dup2(var->pipe[0], STDIN_FILENO);
		dup2(var->fd2, STDOUT_FILENO);
		close(var->pipe[1]);
	}
	execve(var->tmpcmd, var->cmd, var->env);
	return (0);
}
void ft_free_ever(t_pipex *var)
{
	ft_clear_mtx(&var->env, mtx_count_rows(var->env));
	ft_clear_mtx(&var->cmd, mtx_count_rows(var->cmd));
	free(var->infile);
	free(var->outfile);
	free(var->tmpcmd);
}
int main(int argc, char **argv)
{
	t_pipex var;
	int error;

	var = (t_pipex){0};
	if (argc < 5 || !argv || !(*argv))
		return (0);
	if(ft_initialize(&var, argc, argv) == 0)
	{
		ft_free_ever(&var);
		error_fn(INITIALIZATION_ERROR);
	}	
	while(var.counter < argc - 3)
	{
		var.tmpcmd = ft_return_cmd(&var, argv);
		if(var.tmpcmd == NULL)
		{
			ft_free_ever(&var);
			error_fn(INITIALIZATION_ERROR);
		}
		var.pid = fork();
		if(var.pid == -1)
		{
			ft_free_ever(&var);
			error_fn(EXEC_ERROR);
		}
		if(var.pid == 0)
		{
			if (ft_execute_son(&var) == 0)
			{
				ft_free_ever(&var);
				error_fn(EXEC_ERROR);
			}	
		}
		waitpid(var.pid, &error, 0);
		free(var.tmpcmd);
		var.tmpcmd = NULL;
		var.counter++;
		close(var.pipe[1]);
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	ft_free_ever(&var);
}
