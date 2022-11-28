/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 20:47:22 by kslager       #+#    #+#                 */
/*   Updated: 2022/11/28 19:05:05 by kslager       ########   odam.nl         */
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

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(char *str, int c)
{
	int	i;

	i = 0;
	i = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	if (!s1 && !s2)
		return (NULL);
	str = (char *) ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start + 1;
	else
		len += 1;
	substr = (char *) malloc(len);
	if (substr == 0)
		return (NULL);
	ft_strlcpy(substr, s + start, len);
	return (substr);
}

int	findn(char *str)
{
	int	i;
	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char  *ft_readline(int fd, char *str, char *temp)
{
	int		readvalue;

	readvalue = 1;
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (!ft_strrchr(str, '\n') && readvalue > 0)
	{
		readvalue = read(fd, temp, BUFFER_SIZE);
		str = ft_strjoin(str, temp);
		if (!str)
		{
			free(str);
			return (NULL);
		}
		if (ft_strrchr(str, '\n'))
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;
	char		*temp;

	if (buffer)
		temp = ft_strdup(buffer);
	str = ft_readline(fd, str, temp);
	str = ft_substr(str, 0, findn(str));
	buffer = ft_strdup(str);
	return (str);
}

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	int	i = 0;

	while (i < 10)
	{
		printf("%d :||[%s]||\n", i, get_next_line(fd));
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