/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 14:52:25 by kslager       #+#    #+#                 */
/*   Updated: 2022/11/02 19:39:39 by koenslager    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);

#endif