/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 16:53:58 by kslager       #+#    #+#                 */
/*   Updated: 2022/11/01 13:56:15 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	if (!dst || dstsize == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize - 1 < dstlen)
		return (dstsize + srclen);
	if (dstsize - 1 > dstlen)
	{
		while (src[i] && dstlen + i + 1 < dstsize)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

// int main()
// {
//     // char s1[10] = "hello1234";
//     // char s2 = (char *)NULL;
//     // printf("%lu\n", ft_strlcat(NULL, NULL, 0));
//     printf("%lu\n", strlcat(NULL, NULL, 0));
//     return (0);
// }
