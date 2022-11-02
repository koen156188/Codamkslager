/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 11:30:14 by kslager       #+#    #+#                 */
/*   Updated: 2022/10/27 01:48:18 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		k = k * 10 + str[i++] - '0';
	if (j == 0)
		return (k);
	return (k * -1);
}

// int main(void)
// {
// 	char str[22] = "   52638junk";
// 	printf("%i\n", atoi(str));
// 	printf("%i\n", ft_atoi(str));
// 	return (0);
// }