/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 17:29:48 by kslager       #+#    #+#                 */
/*   Updated: 2022/10/27 01:31:03 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

// int main()
// {
// 	char str[21] = "hello my name is koen";
// 	ft_bzero(str, 5);
// 	printf("%s", str);
// 	return (0);
// }