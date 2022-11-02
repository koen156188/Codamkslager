/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 17:48:42 by kslager       #+#    #+#                 */
/*   Updated: 2022/10/17 18:45:05 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[j + i] == needle[j] && (j + i) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
// int main(void)
// {
// 	char *s1 = "oh no not the empty string !";
// 	char *s2 = "not";
// 	printf("%s\n", ft_strnstr(s1, s2, 0));
// 	printf("%s\n", strnstr(s1, s2, 0));
// }