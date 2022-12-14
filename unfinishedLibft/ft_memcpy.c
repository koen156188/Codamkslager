/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 17:44:41 by kslager       #+#    #+#                 */
/*   Updated: 2022/11/02 19:43:43 by koenslager    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *) dst;
	s2 = (unsigned char *) src;
	if (n == 0 || s2 == s1)
		return (dst);
	while (n--)
		*s1++ = *s2++;
	return (dst);
}

// int main()
// {
//     char s1[5] = "whats";
//     char s2[5] = "whats";
//     printf("%s\n", ft_memcpy(s1, s2, 5));
//     printf("%s\n", memcpy(s1, s2, 5));
//     return(0);
// }