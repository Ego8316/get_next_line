/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:50:10 by ego               #+#    #+#             */
/*   Updated: 2024/10/26 19:14:49 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_free(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
	return (1);
}

static int	ft_get_to_next_nl(int fd, char **buffer)
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
			return (1 - ft_free(&buf));
		buf[r] = '\0';
		temp = ft_strjoin(*buffer, buf);
		ft_free(buffer);
		*buffer = temp;
		if (!*buffer)
			return (1 - ft_free(&buf));
		if (ft_char_in_str('\n', *buffer))
			return (ft_free(&buf));
	}
	return (ft_free(&buf));
}

static char	*ft_split_content(char **buffer)
{
	char	*temp;
	char	*line;
	size_t	i;

	temp = ft_strdup(*buffer);
	if (!temp)
		return (NULL);
	ft_free(buffer);
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	line = ft_strndup(temp, i);
	if (line)
		*buffer = ft_strdup(temp + i);
	ft_free(&temp);
	if (!line || !*buffer)
	{
		ft_free(&line);
		ft_free(buffer);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_MAX];
	char		*line;

	if (fd < 0 || fd > FD_MAX || read(fd, 0, 0) == -1)
	{
		ft_free(&buffer[fd]);
		return (NULL);
	}
	line = NULL;
	if (ft_get_to_next_nl(fd, &buffer[fd]) == 0)
	{
		ft_free(&buffer[fd]);
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
