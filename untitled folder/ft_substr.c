/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 16:42:54 by kslager       #+#    #+#                 */
/*   Updated: 2022/10/31 19:04:56 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start + 1;
	else
		len += 1;
	substr = (char *) malloc(len);
	if (substr == 0)
		return (NULL);
	ft_strlcpy(substr, s + start, len);
	return (substr);
}

// int main()
// {
//     char *s = "hello my name is koen";
//     size_t len = 5;
//     unsigned int i = 5;
//     printf("%s", ft_substr(s, i, len));
//     return (0);
// }