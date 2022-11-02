/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 16:12:08 by kslager       #+#    #+#                 */
/*   Updated: 2022/10/31 15:08:07 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{	
	char	*s1;
	char	*s2;
	size_t	i;

	i = 0;
	s1 = (char *)src;
	s2 = (char *)dst;
	if (s1 == 0 && s2 == 0)
		return (0);
	if (s2 > s1)
	{
		while (len > 0)
		{
			len--;
			s2[len] = s1[len];
		}
	}
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	return (dst);
}

// int main()
// {
// 	// char dst[6] = "hello";
// 	char src[9] = "worldasdw";
// 	printf("%s\n", ft_memmove(((void*)0),((void*)0), 0));
// 	printf("%s\n", memmove(((void*)0),((void*)0), 0));
// 	return (0);
// }