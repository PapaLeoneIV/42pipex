/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:43:30 by rileone           #+#    #+#             */
/*   Updated: 2024/03/10 17:14:11 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_return_cmd(t_pipex *var, char **argv)
{
	int		i;
	char	*tmpcmd;

	i = 0;
	var->cmd = ft_split(argv[var->counter + 2], ' ');
	if (var->cmd == NULL)
		return (0);
	while (var->env && var->env[i] != NULL)
	{
		tmpcmd = ft_strjoin(var->env[i], var->cmd[0]);
		if (access(tmpcmd, 0) == 0)
			return (tmpcmd);
		i++;
		free(tmpcmd);
		tmpcmd = NULL;
	}
	ft_clear_mtx(&var->cmd, mtx_count_rows(var->cmd));
	return (NULL);
}

void	ft_free_ever(t_pipex *var, t_state state)
{
	ft_clear_mtx(&var->env, mtx_count_rows(var->env));
	ft_clear_mtx(&var->cmd, mtx_count_rows(var->cmd));
	ft_clear_mtx(&var->envmtx, mtx_count_rows(var->envmtx));
	free(var->infile);
	free(var->outfile);
	free(var->tmpcmd);
	if (state == 0 || state == 1)
		exit(state);
}

char	*getenv_string(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

int	ft_initialize(t_pipex *var, int argc, char **argv, char **envp)
{
	int	i;

	i = -1;
	if (pipe(var->pipe) == -1)
		return (0);
	var->envstring = getenv_string(envp);
	if (!var->envstring)
		return (0);
	var->envmtx = ft_split(var->envstring, ':');
	if (var->envmtx == NULL)
		ft_free_ever(var, FAILURE);
	var->env = ft_calloc(mtx_count_rows(var->envmtx) + 1, sizeof(char *));
	if (var->env == NULL)
		ft_free_ever(var, FAILURE);
	while (var->envmtx[++i] != NULL)
		var->env[i] = ft_strjoin(var->envmtx[i], "/");
	var->fd = open(argv[1], O_RDONLY);
	var->fd2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_clear_mtx(&var->envmtx, mtx_count_rows(var->envmtx));
	if (var->fd == -1 || var->fd2 == -1)
		ft_free_ever(var, FAILURE);
	return (1);
}

int	ft_execute_son(t_pipex *var)
{
	if (var->counter == 0)
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
