/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 17:48:43 by kslager       #+#    #+#                 */
/*   Updated: 2022/10/28 19:19:22 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	j = ft_strlen((char *)s1);
	while (j >= 0 && ft_strchr(set, s1[j]))
		j--;
	str = ft_substr((char *)s1, 0, j + 1);
	return (str);
}

// int main()
// {
// 	const char *s1 = "hello my name is koen";
// 	const char *s2 = "hen";
// 	printf("%s", ft_strtrim(s1, s2));
// 	return (0);
// }
