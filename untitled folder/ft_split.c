/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 19:35:27 by kslager       #+#    #+#                 */
/*   Updated: 2022/11/01 12:51:25 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	countwords(char const *s, char c)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (s[i] != c)
		k++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			k++;
		i++;
	}
	return (k);
}

static int	findwordlen(const char *s, char c, int start)
{
	int	wordlen;

	wordlen = 0;
	while (s[start] != '\0' && s[start] != c)
	{
		wordlen++;
		start++;
	}
	return (wordlen);
}

static void	ft_freemalloc(char **str, size_t j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
}

static size_t	ft_strmake(char **str, char const *s, char c, size_t i)
{
	size_t	j;
	size_t	wordlen;

	j = 0;
	wordlen = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			wordlen = findwordlen(s, c, i);
			str[j] = ft_substr(s, i, wordlen);
			if (!str[j])
			{
				ft_freemalloc(str, j);
				return (0);
			}
			j++;
			i = i + wordlen;
		}
		else
			i++;
	}
	str[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char **) malloc((countwords(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	if (!ft_strmake(str, s, c, i))
		return (NULL);
	return (str);
}

// int main(void)
// {
//     char **ptr = ft_split("  tripouille  42  ", ' ');
//     for(int i = 0; i < 2; i++)
//         printf("%s\n", ptr[i]);
//     return (0);
// }
