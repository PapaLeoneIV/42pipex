/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:15:31 by rileone           #+#    #+#             */
/*   Updated: 2024/03/10 17:13:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void exec_cmd(t_pipex *var)
{
	var->pid = fork();
	if (var->pid == -1)
		ft_free_ever(var, FAILURE);
	if (var->pid == 0)
	{
		if (var->counter == 0)
		{
			dup2(var->pipe[1], STDOUT_FILENO);
			dup2(var->fd, STDIN_FILENO);
			close(var->pipe[0]);
		}
		else
		{
			dup2(var->pipe[0], STDIN_FILENO);
			dup2(var->fd2, STDOUT_FILENO);
			close(var->pipe[1]);
		}
		execve(var->tmpcmd, var->cmd, var->env);
		return;
	}
	return;
}

int main(int argc, char **argv, char **envp)
{
	t_pipex var;

	var = (t_pipex){0};
	if (argc < 5 || !argv || !(*argv) || argc > 6)
		return (EXIT_FAILURE);
	if (ft_initialize(&var, argc, argv, envp) == 0)
		ft_free_ever(&var, FAILURE);
	while (var.counter < argc - 3)
	{
		var.tmpcmd = ft_return_cmd(&var, argv);
		exec_cmd(&var);
		ft_clear_mtx(&var.cmd, mtx_count_rows(var.cmd));
		close(var.pipe[1]);
		free(var.tmpcmd);
		var.tmpcmd = NULL;
		var.counter++;
	}
	waitpid(-1, NULL, 0);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	ft_free_ever(&var, SUCCESS);
}
