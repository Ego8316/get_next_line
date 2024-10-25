/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:50:10 by ego               #+#    #+#             */
/*   Updated: 2024/10/25 19:21:35 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
	return (1);
}

int	ft_get_to_next_nl(int fd, char **buffer)
{
	char		*buf;
	char		*temp;
	ssize_t		r;

	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (0);
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			ft_free(&buf);
			return (0);
		}
		buf[r] = '\0';
		temp = ft_strdup(*buffer);
		ft_free(buffer);
		*buffer = ft_strjoin(temp, buf);
		ft_free(&temp);
		if (ft_char_in_str('\n', *buffer))
			return (ft_free(&buf));
	}
	return (ft_free(&buf));
}

char	*ft_split_content(char **buffer)
{
	char	*temp;
	char	*line;
	size_t	i;
	size_t	j;

	temp = ft_strdup(*buffer);
	ft_free(buffer);
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	j = i + 1;
	while (temp[j])
		j++;
	line = ft_strndup(temp, i + 1);
	*buffer = ft_strdup(temp + i + 1);
	ft_free(&temp);
	if (!*buffer)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_MAX];
	char		*line;

	if (fd < 0 || fd > FD_MAX || read(fd, 0, 0) == -1)
		return (NULL);
	line = NULL;
	if (!ft_get_to_next_nl(fd, &buffer[fd]))
	{
		ft_free(&buffer[fd]);
		ft_free(&line);
		return (NULL);
	}
	if (buffer[fd] && *buffer[fd])
		line = ft_split_content(&buffer[fd]);
	if (!line || !(*line))
	{
		ft_free(&buffer[fd]);
		ft_free(&line);
		return (NULL);
	}
	return (line);
}
