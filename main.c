/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:00:45 by ego               #+#    #+#             */
/*   Updated: 2024/10/26 17:43:59 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	char	*nul;
	int		fd;

	nul = NULL;
	fd = open("./b", O_RDONLY); 
	line = get_next_line(fd);
	printf("GNL : [%s]\n-------------\n", line);
	line = get_next_line(fd);
	printf("GNL : [%s]\n-------------\n", line);
	line = get_next_line(fd);
	printf("GNL : [%s]\n-------------\n", line);
	close(fd);
	return (0);
}
