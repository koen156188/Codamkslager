/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 13:46:07 by kslager       #+#    #+#                 */
/*   Updated: 2022/10/31 18:17:16 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

// int main(void)
// {
//     printf("%d", ft_strlen("hello"));
//     return (0);
// }