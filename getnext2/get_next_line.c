/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: koenslager <koenslager@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 01:01:35 by koenslager    #+#    #+#                 */
/*   Updated: 2022/12/09 16:57:33 by koenslager    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

#include <string.h>
#include <fcntl.h> 
#include <stdio.h>

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
	str = malloc((len + BUFFER_SIZE + 1) * sizeof(char));
	if (str == 0)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
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

char	*ft_joinline(char *dest, char *src)
{
	int		i;
	int		j;
	char	*newline;

	i = 0;
	j = 0;
	if (!dest)
		return (ft_strdup(src));
	if (!src)
		return (ft_strdup(dest));
	newline = malloc((ft_strlen(dest) + ft_strlen(src) + 1) * sizeof(char));
	if (!newline)
		return (NULL);
	while (dest[i] != '\0' && dest[i] != '\n')
	{
		newline[i] = dest[i];
		i++;
	}
	while (src[j] != '\0' && src[j] != '\n')
	{
		newline[i] = src[j];
		i++;
		j++;
	}
	newline[i] = '\0';
	return (newline);
}

char	*leftoverline(char *line)
{
	char	*leftover;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	leftover = malloc((i + 2) * sizeof(char));
	if (!leftover)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		leftover[i] = line[i];
		i++;
	}
	leftover[i++] = '\n';
	leftover[i] = '\0';
	return (leftover);
}

char	*ft_readline(int fd, char *line)
{
	char	*temp;
	int		readvalue;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	readvalue = BUFFER_SIZE;
	while (!ft_strchr(temp, '\n') && readvalue > 0)
	{
		readvalue = read(fd, temp, BUFFER_SIZE);
		if (!temp)
		{
			free (temp);
			return (NULL);
		}
		// printf("temp : [%s]\n", temp);
		line = ft_strjoin(line, temp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	// if (!fd || read(fd, 0, 0) <= 0)
	// 	return (NULL);
	line = ft_readline(fd, line);
	printf("line : {%s}\n", buffer);
	buffer = leftoverline(line);
	line = ft_joinline(buffer, line);
	return (line);
}

int	main(void)
{
	int		fd;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i <= 9)
	{
		printf("%d : [%s]\n", i, get_next_line(fd));
		printf("---------------------------\n");
		i++;
	}
	close (fd);
}