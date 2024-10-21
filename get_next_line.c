/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:50:10 by ego               #+#    #+#             */
/*   Updated: 2024/10/22 00:55:35 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[FD_MAX + 1];

	buffer[FD_MAX + 1] = 0;
	if (fd < 0 || fd > FD_MAX || read(fd, 0, 0) == -1)
		return (NULL);
	line = 0;
	return (line);
}
