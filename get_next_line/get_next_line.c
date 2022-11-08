/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 20:47:22 by kslager       #+#    #+#                 */
/*   Updated: 2022/11/08 21:07:11 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

#include <string.h>
#include <fcntl.h> 
#include <stdio.h>

int	ft_nterm(int fd, char *buffer, int buffer_size)
{
	int	i;

	i = 0;
	while (*buffer != '\n')
	{
		read(fd, buffer, 1);
		if (i == buffer_size)
			return (i);
		if (*buffer == '\n')
			return (i);
		buffer++;
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			buffer_size = BUFFER_SIZE;
	int			linelen;
	char static	*buffer;
	int			i;

	i = 1;
	buffer = malloc((buffer_size) * sizeof (char));
	if (!buffer)
		return (NULL);
	while (i != 0)
	{
		i = ft_nterm(fd, buffer, i, buffer_size);
		if (i == 0)
			return (buffer); /*min '\n' chekcen */
		if (i == buffer)
			i = ft_nterm/*vragen of je dan alllen moet lever hvl bytes is gevraag of opnieuw moet mallocen*/
		if (i < buffer_size)
		{
			read(fd, buffer, i); /*redo malloc!*/
			return (buffer);
		}
	}
	return (NULL);
}

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);

	printf("---------------------------\n");
	printf("%s", get_next_line(fd));
	printf("---------------------------\n");
	printf("%s", get_next_line(fd));
	printf("---------------------------\n");
	printf("%s", get_next_line(fd));
	printf("---------------------------\n");
	close (fd);
}

		// printf("value : %s\n", &buffer[i]);
		// printf("bufferlen : %lu\n", strlen(&buffer[i]));
		// printf("linelen : %i\n", linelen);