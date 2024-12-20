/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:50:10 by ego               #+#    #+#             */
/*   Updated: 2024/12/20 11:49:42 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_free(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
	return (1);
}

static int	ft_get_to_next_nl(int fd, char **stash)
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
		temp = ft_strjoin(*stash, buf);
		ft_free(stash);
		*stash = temp;
		if (!*stash)
			return (1 - ft_free(&buf));
		if (ft_char_in_str('\n', *stash))
			return (ft_free(&buf));
	}
	return (ft_free(&buf));
}

static char	*ft_split_content(char **stash)
{
	char	*temp;
	char	*line;
	size_t	i;

	temp = ft_strdup(*stash);
	if (!temp)
		return (NULL);
	ft_free(stash);
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	line = ft_strndup(temp, i);
	if (line)
		*stash = ft_strdup(temp + i);
	ft_free(&temp);
	if (!line || !*stash)
	{
		ft_free(&line);
		ft_free(stash);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[FD_MAX];
	char		*line;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
	{
		ft_free(&stash[fd]);
		return (NULL);
	}
	line = NULL;
	if (ft_get_to_next_nl(fd, &stash[fd]) == 0)
	{
		ft_free(&stash[fd]);
		return (NULL);
	}
	if (stash[fd] && *stash[fd])
		line = ft_split_content(&stash[fd]);
	if (!line || !(*line))
	{
		ft_free(&stash[fd]);
		ft_free(&line);
		return (NULL);
	}
	return (line);
}
