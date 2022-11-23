/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 20:47:22 by kslager       #+#    #+#                 */
/*   Updated: 2022/11/23 21:19:36 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

#include <string.h>
#include <fcntl.h> 
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s1[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*i;

	i = (void *) malloc(count * size);
	if (i == 0)
		return (0);
	ft_bzero(i, count * size);
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (s1[len] != '\0')
		len++;
	str = ft_calloc(len + BUFFER_SIZE + 1, sizeof(char));
	if (str == 0)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}

int	findn(char *temp)
{
	int	i;

	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
			return (i);
		else
			i++;
	}
	return (i);
}

char	*ft_strmake(char *temp, char *str)
{
	int	i; 

	i = 0;
	i = findn(temp);
}

char  *ft_readline(int fd, char *temp, char *str)
{
	int	readvalue;

	readvalue = 0;
	while (/*n not found*/)
	{
		readvalue = read(fd, temp, BUFFER_SIZE);
		str = ft_strmake(temp, str);
		if (findn(temp) < BUFFER_SIZE)
			break ;
		else
		{	
			free (temp);
			
		}	
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	char		*str;
	int			count;

	if (!buffer)
	{
		temp = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
		if (!temp)
			return (NULL);
	}
	else
		temp = strdup(buffer);
	str = ft_readline(fd, temp, str);
	return (str);
}

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	int	i = 0;

	while (i < 2)
	{
		printf("%d :[%s]\n", i, get_next_line(fd));
		printf("---------------------------\n");
		i++;
	}
	close (fd);
}

// printf("value : %s\n", &buffer[i]);
// printf("bufferlen : %lu\n", strlen(&buffer[i]));
// printf("linelen : %i\n", linelen);
// 		char	*get_next_line(int fd)
// {
// 	int			buffer_size = BUFFER_SIZE;
// 	static char	*buffer;
// 	char		*temp;
// 	int			i = 0;
// 	int			linelen = 0;

// 	buffer = malloc((buffer_size) * sizeof (char));
// 	if (!buffer)
// 		return (NULL);
// 	while (i != 3)
// 	{
// 		read(fd, buffer, buffer_size);
// 		linelen = find_nterm(fd, buffer);
// 		printf("buffer : [%s]\n", buffer);
// 		printf("linelen : %i\n", linelen);
// 		if (linelen < buffer_size)
// 		{
// 			temp = ft_makeline(buffer, linelen);
// 			printf("after i : %i\n", i);
// 			buffer -= 10;
// 			printf("%zu\n", strlen(buffer));
// 			return (temp);
// 		}
// 		i = 3;
// 	}
// 	return (NULL);
// }