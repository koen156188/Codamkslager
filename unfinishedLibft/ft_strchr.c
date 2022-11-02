/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 15:03:17 by kslager       #+#    #+#                 */
/*   Updated: 2022/10/13 20:52:22 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	j;

	j = (char)c;
	i = 0;
	while (s[i] != j)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}
// int main()
// {
//     printf("%s", ft_strchr("helo my name is koen", 'e'));
// }
