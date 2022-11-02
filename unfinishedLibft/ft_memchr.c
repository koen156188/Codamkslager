/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 15:05:40 by kslager       #+#    #+#                 */
/*   Updated: 2022/10/31 18:44:50 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;
	char	j;

	i = 0;
	j = (char)c;
	str = (char *) s;
	while (i < n)
	{
		if (str[i] == j)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	char s1[21] = "hello my name is koen";
// 	printf("%s\n", ft_memchr(s1, 'z', 50));
// 	printf("%s\n", memchr(s1, 'z', 50));
// 	return (0);
// }