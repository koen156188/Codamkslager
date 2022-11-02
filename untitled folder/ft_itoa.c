/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 18:29:54 by kslager       #+#    #+#                 */
/*   Updated: 2022/10/24 20:56:02 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

int	countn(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	int		min;
	char	*str;

	min = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = countn(n);
	str = (char *) malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	if (n < 0)
	{
		n = n * -1;
		min = 1;
	}
	while (i-- != 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
	}
	if (min == 1)
		str[++i] = '-';
	return (str);
}

// int	main(void)
// {
// 	printf("%s", ft_itoa(-123456));
// }
