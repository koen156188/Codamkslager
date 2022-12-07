/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 20:47:22 by kslager       #+#    #+#                 */
/*   Updated: 2022/12/07 16:32:40 by koenslager    ########   odam.nl         */
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

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	j;

	j = (char)c;
	i = 0;
	while (s[i] != j)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
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
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[j] != '\0')
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}

char	*ft_substr(char *s, int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start + 1;
	else
		len += 1;
	substr = (char *) ft_calloc(len, sizeof(char));
	if (!substr)
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
	i++;
	return (i);
}

char  *ft_readline(int fd, char *str)
{
	int		readvalue;
	char	*temp;

	temp = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!temp)
		return (NULL);
	readvalue = BUFFER_SIZE;
	while (!ft_strchr(str, '\n') && readvalue > 0)
	{
		readvalue = read(fd, temp, BUFFER_SIZE);
		str = ft_strjoin(str, temp);
		if (!str)
		{
			free(str);
			return (NULL);
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;

	if (buffer)
	{
		if (strchr(buffer, '\n'))
		{
			buffer = ft_substr(buffer, findn(buffer), strlen(buffer) + 1);
			str = ft_substr(buffer, 0, findn(buffer));
			return (str);
		}
	}
	str = ft_strjoin(buffer, ft_readline(fd, str));
	if (!str)
		return (NULL);
	// printf("line : [%s]\n", str);
	buffer = ft_substr(str, findn(str), strlen(str) + 1);
	str = ft_substr(str, 0, findn(str));
	return (str);
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i <= 9)
	{
		printf("%d :||[%s]||\n", i, get_next_line(fd));
		printf("---------------------------\n");
		i++;
	}
	close (fd);
}
