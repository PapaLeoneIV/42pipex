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
