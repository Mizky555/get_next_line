/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:34:17 by tsirirak          #+#    #+#             */
/*   Updated: 2022/08/06 15:36:50 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = malloc(sizeof(char *) * 11);
	buffer[11] = '\0';
	while (*fd)
	{
		read(fd, buffer, 1);
	}
	return(buffer);
}

int	main()
{
	int	fd;

	fd = open("opal_i",O_RDONLY);
	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
	return(0);
}
