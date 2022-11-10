/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 20:47:22 by kslager       #+#    #+#                 */
/*   Updated: 2022/11/10 22:16:23 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

#include <string.h>
#include <fcntl.h> 
#include <stdio.h>

int		find_nterm(int fd, char *buffer);
void	*ft_calloc(size_t count, size_t size);
void	*ft_strlcat(char *buffer, char *temp, int len);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_strlcat(char *buffer, char *temp, int len)
{
	int		i;
	int		j;
	char	*newstr;

	newstr = ft_calloc((len + ft_strlen(temp)), sizeof (char));
	if (!newstr)
		return (NULL);
	while (i < ft_strlen(temp))
	{
		newstr[i] = temp[i];
		i++;
	}
	while (j < len)
	{
		newstr[i] = buffer[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = (unsigned char *) malloc(count * size);
	if (s == NULL)
		return (NULL);
	while (i < (size * count))
	{
		s[i] = 0;
		i++;
	}
	return (s);
}

int	find_nterm(int fd, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n')
	{
		i++;
	}
	i++;
	return (i);
}

// char	*ft_shortline(char *buffer, char *temp, int count)
// {
	
// }

char	*get_next_line(int fd)
{
	char static	*buffer;
	char		*temp;
	char		*str;
	int			count;
	int			readvalue;

	count = 0;
	readvalue = 0;
	temp = ft_strlcat(temp, buffer, ft_strlen(temp));
	temp = malloc((BUFFER_SIZE + ft_strlen(temp)) * sizeof (char));
	if (!temp)
		return (NULL);
	readvalue = read(fd, temp, BUFFER_SIZE);
	count = find_nterm(fd, temp);
	while (count == BUFFER_SIZE)
	{
		count = find_nterm(fd, temp);
		temp = ft_strlcat(temp, str, count);
		readvalue = read(fd, temp, BUFFER_SIZE);
	}
	if (readvalue == 0)
	{
		buffer = ft_strlcat(buffer, str, ft_strlen(buffer));
		return (ft_strlcat(temp, str, (find_nterm(fd, buffer) - 1)));
	}
	// if (count != BUFFER_SIZE)
	// 	ft_shortline(buffer, temp, count);
	return (temp);
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