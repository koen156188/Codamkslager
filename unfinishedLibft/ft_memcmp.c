/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 15:29:16 by kslager       #+#    #+#                 */
/*   Updated: 2022/10/28 18:31:42 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < n -1)
		i++;
	return (str1[i] - str2[i]);
}
// int main()
// {
// 	char s1[] = "hello world";
// 	char s2[] = "hello World";
// 	printf("%d\n", ft_memcmp(s1, s2, 5));
// 	printf("%d\n", memcmp(s1, s2, 5));
// 	return (0);
// }