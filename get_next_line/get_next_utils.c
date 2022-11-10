/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 20:47:49 by kslager       #+#    #+#                 */
/*   Updated: 2022/11/10 17:38:37 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int hello(void)
{
	int static i;
	int j;
	
	i++;
	j++;
	printf("i = %i\n", i);
	return (j);
}

int main(void)
{
	printf("j = %i", hello());
	printf("j = %i", hello());
	printf("j = %i", hello());
	printf("j = %i", hello());
	printf("j = %i", hello());
	printf("j = %i", hello());
	printf("j = %i", hello());
	printf("j = %i", hello());
}