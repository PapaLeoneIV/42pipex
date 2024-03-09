/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:08:29 by rileone           #+#    #+#             */
/*   Updated: 2024/03/06 13:40:02 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include "./libft/gnl/get_next_line_bonus.h"
# include "./libft/printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>


typedef struct s_pipex
{
	int		fd;
	int		fd2;
	int		pipe[2];
	int		counter;
	pid_t	pid;
	pid_t	pid2;
	char	*tmpcmd;	
	char	*infile;
	char	*outfile;
	char	*envstring;
	char	**env;
	char	**cmd;
	char	**envmtx;	
}		t_pipex;

int		ft_initialize(t_pipex *var, int argc, char **argv);
char	*ft_return_cmd(t_pipex *var, char **argv);
void	ft_free_ever(t_pipex *var);


#endif