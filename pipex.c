/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:15:31 by rileone           #+#    #+#             */
/*   Updated: 2024/03/05 14:23:02 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int ft_initialize(t_pipex *var, int argc, char **argv)
{
	char *envstring;
	char **envmtx;
	int i;
	
	i = 0;
	var->pipe = ft_create_pipes(argc);
	envstring = getenv("PATH");
	if(!envstring)
		return (0);
	envmtx = ft_split(envstring, ':');
	if(envmtx == NULL)
	{
		free(envstring);
		ft_clear_mtx(&var->env, mtx_count_rows(var->env));
		return (0);
	}
	var->env = ft_calloc(mtx_count_rows(envmtx) + 1, sizeof(char *));
	while(envmtx[i] != NULL)
	{
		var->env[i] = ft_strjoin(envmtx[i], "/");
		i++;
	}
	var->infile = argv[1];
	var->outfile = argv[argc - 1];
	var->fd = open(var->infile, O_RDONLY);
	var->fd2 = open(var->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_clear_mtx(&envmtx, mtx_count_rows(envmtx));
	return (1);
}




char *ft_return_cmd(t_pipex *var, char **argv)
{
	int i;
	char	*tmpcmd;

	i = 0;
	var->cmd = ft_split(argv[var->counter] , ' ');
	if(var->cmd == NULL)
		ft_free_everything(var);
	while(var->env && var->env[i] != NULL)
	{
		tmpcmd = ft_strjoin(var->env[i], var->cmd[0]);
		if(access(tmpcmd, 0) == 0)
			return (tmpcmd);
		i++;
		free(tmpcmd);
		tmpcmd = NULL;
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	t_pipex var;

	var = (t_pipex){0};
	if (argc < 5 || !argv || !(*argv))
		return (0);
	if(ft_initialize(&var, argc, argv) != 0)
	{
		error_fn(INITIALIZATION_ERROR);
		return (0);
	}
	if(pipe(var.pipe) == -1)
		return (0);
	var.pid = fork();
	if(var.pid == 0)
		ft_execute_son(var);
	
	
	
}
