/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:15:31 by rileone           #+#    #+#             */
/*   Updated: 2024/03/10 16:42:19 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_fork(t_pipex *var)
{
	var->pid = fork();
	if (var->pid == -1)
		ft_free_ever(var, FAILURE);
	if (var->pid == 0)
	{
		if (ft_execute_son(var) == 0)
			ft_free_ever(var, FAILURE);
	}
	waitpid(var->pid, NULL, 0);
}

int	main(int argc, char **argv)
{
	t_pipex	var;

	var = (t_pipex){0};
	if (argc < 5 || !argv || !(*argv))
		return (EXIT_FAILURE);
	if (ft_initialize(&var, argc, argv) == 0)
		ft_free_ever(&var, FAILURE);
	while (var.counter < argc - 3)
	{
		var.tmpcmd = ft_return_cmd(&var, argv);
		exec_fork(&var);
		ft_clear_mtx(&var.cmd, mtx_count_rows(var.cmd));
		close(var.pipe[1]);
		free(var.tmpcmd);
		var.tmpcmd = NULL;
		var.counter++;
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	ft_free_ever(&var, SUCCESS);
}
