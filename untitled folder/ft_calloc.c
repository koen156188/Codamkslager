/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:43:38 by kslager       #+#    #+#                 */
/*   Updated: 2022/10/27 01:48:30 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*i;

	i = (void *) malloc(count * size);
	if (i == 0)
		return (0);
	ft_bzero(i, count * size);
	return (i);
}
