/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:03:43 by rileone           #+#    #+#             */
/*   Updated: 2023/11/17 19:03:51 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*return_last_line(char **buffer)
{
	char	*out;

	out = ft_substr_gnl(*buffer, 0, ft_strlen_gnl(*buffer));
	free(*buffer);
	*buffer = NULL;
	return (out);
}

void	*free_everything(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*read_until_newline(int fd, char *tmp)
{
	char	*str;
	int		bytes;
	char	*buffer;

	bytes = 1;
	str = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (fd == -1 || !BUFFER_SIZE)
		return (NULL);
	while (ft_strchri_gnl(str, '\n') == -1 && bytes > 0)
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(str);
			return (NULL);
		}
		if (bytes > 0)
		{
			buffer = ft_strjoin_gnl(tmp, str, bytes);
			free(tmp);
			tmp = buffer;
		}
	}
	free(str);
	return (tmp);
}

char	*return_line(char **buffer, int bytes, char **tmp)
{
	char	*out;

	out = ft_substr_gnl(*buffer, 0, bytes + 1);
	*buffer = ft_substr_gnl(*tmp, bytes + 1, ft_strlen_gnl(*buffer));
	free(*tmp);
	return (out);
}

char	*get_next_line(int fd)
{
	static char		*buffer[4096];
	char			*tmp;
	int				bytes;

	if (fd == -42)
		return (free_everything(buffer));
	if (fd < 0 || BUFFER_SIZE < 1 || fd > 4096)
		return (NULL);
	tmp = read_until_newline(fd, buffer[fd]);
	buffer[fd] = tmp;
	if (!tmp)
		return (free_everything(&buffer[fd]));
	if (ft_strlen_gnl(buffer[fd]) == 0)
	{
		free(tmp);
		buffer[fd] = NULL;
		return (NULL);
	}
	bytes = ft_strchri_gnl(buffer[fd], '\n');
	if (bytes != -1)
		return (return_line(&buffer[fd], bytes, &tmp));
	else if (bytes == -1)
		return (return_last_line(&buffer[fd]));
	return (NULL);
}
