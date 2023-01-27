/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 14:49:19 by kslager       #+#    #+#                 */
/*   Updated: 2023/01/27 21:54:40 by kslager       ########   odam.nl         */
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
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
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

char	*ft_strjoin(char *str1, char *str2)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newstr = malloc ((ft_strlen(str1) + ft_strlen(str2) + 1 ) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (str1[i])
		newstr[j++] = str1[i++];
	i = 0;
	while (str2[i])
		newstr[j++] = str2[i++];
	newstr[j] = '\0';
	return (newstr);
}

char	*ft_readline(int fd, char *fullstr)
{
	int		readvalue;
	char	*buffer;

	readvalue = BUFFER_SIZE;
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && readvalue > 0)
	{
		readvalue = read(fd, buffer, BUFFER_SIZE);
		fullstr = ft_strjoin(fullstr, buffer);
		if (!fullstr)
			return (NULL);
		if (readvalue < BUFFER_SIZE)
			printf("\n {{{%s}}}\n", buffer);
	}
	return (fullstr);
}

char	*ft_leftover(char *fullstr)
{
	int		i;
	int		j;
	char	*leftoverstr;

	i = 0;
	j = 0;
	while (fullstr[i] != '\n')
		i++;
	leftoverstr = malloc (((ft_strlen(fullstr) - i) + 2) * sizeof(char));
	if (!leftoverstr)
		return (NULL);
	i++;
	while (fullstr[i] != '\0')
		leftoverstr[j++] = fullstr[i++];
	leftoverstr[j] = '\0';
	return (leftoverstr);
}

char	*ft_trimstring(char *fullstr)
{
	int		i;
	char	*finalstr;

	i = 0;
	while (fullstr[i] != '\n')
		i++;
	finalstr = malloc((i + 1) * sizeof(char));
	if (!finalstr)
		return (NULL);
	i = 0;
	while (fullstr[i] != '\n')
	{
		finalstr[i] = fullstr[i];
		i++;
	}
	finalstr[i] = '\0';
	return (finalstr);
}

char	*get_next_line(int fd)
{
	static char	*leftoverstr;
	char		*fullstr;

	if (!leftoverstr)
		fullstr = ft_readline(fd, fullstr);
	else
		fullstr = ft_strjoin(leftoverstr, ft_readline(fd, fullstr));
	if (!fullstr)
		return (NULL);
	leftoverstr = ft_leftover(fullstr);
	if (!leftoverstr)
		return (NULL);
	fullstr = ft_trimstring(fullstr);
	if (!fullstr)
		return (NULL);
	return (fullstr);
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
