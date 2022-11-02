/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 14:09:26 by kslager       #+#    #+#                 */
/*   Updated: 2022/10/27 01:35:13 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)b;
	while (i < len)
	{
		str[i++] = c;
	}
	return (b);
}

// int main()
// {
// 	char str[21] = "hello my name is koen";
// 	printf("%s\n", ft_memset(str +13, '&', 5));
// 	printf("%s", memset(str +13, '&', 5));
// 	return (0);
// }