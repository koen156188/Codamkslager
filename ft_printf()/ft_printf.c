/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 16:41:41 by kslager       #+#    #+#                 */
/*   Updated: 2022/11/02 20:26:58 by koenslager    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int	ft_putchar(char a)
{
	return (write(1, &a, 1));
}

int	ft_putstr(char *s, int printlen)
{
	if (s == NULL)
		return (ft_putstr("(null)", 0));
	while (*s)
		printlen += ft_putchar(*s++);
	return (printlen);
}

int	ft_putnbr(int n, int printlen)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648", 0));
	if (n < 0)
	{
		printlen += ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
		printlen += ft_putnbr((n / 10), 0) + ft_putnbr((n % 10), 0);
	if (n < 10)
		printlen += (ft_putchar(n + '0'));
	return (printlen);
}

int	ft_putunint(unsigned int n, int printlen)
{
	if (n >= 10)
		printlen += ft_putnbr((n / 10), 0);
	n = n % 10;
	if (n < 10)
		printlen += (ft_putchar(n += '0'));
	return (printlen);
}

int	ft_hexa(unsigned long int n, int prilen, int factor)
{
	if (factor == 2)
		return (prilen += ft_putstr("0x", 0) + ft_hexa(n, 0, 0));
	if (n >= 16)
	{
		prilen += ft_hexa((n / 16), 0, factor);
		prilen += ft_hexa((n % 16), 0, factor);
	}
	else if (n < 10)
		prilen += ft_putchar(n + '0');
	else
	{
		if (factor == 0)
			prilen += ft_putchar((n % 10) + 'a');
		if (factor == 1)
			prilen += ft_putchar((n % 10) + 'A');
	}
	return (prilen);
}

int	printer(const char *format, int i, va_list ar, int prilen)
{
	if (format[i] == 'c')
		prilen += ft_putchar(va_arg(ar, int));
	if (format[i] == 'i' || format[i] == 'd')
		prilen += ft_putnbr(va_arg(ar, int), 0);
	if (format[i] == 's')
		prilen += ft_putstr(va_arg(ar, char *), 0);
	if (format[i] == 'u')
		prilen += ft_putunint(va_arg(ar, unsigned long int), 0);
	if (format[i] == '%')
		prilen += ft_putchar('%');
	if (format[i] == 'x')
		prilen += ft_hexa(va_arg(ar, unsigned int), 0, 0);
	if (format[i] == 'X')
		prilen += ft_hexa(va_arg(ar, unsigned int), 0, 1);
	if (format[i] == 'p')
		prilen += ft_hexa(va_arg(ar, unsigned long int), 0, 2);
	return (prilen);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printlen;
	va_list	ar;

	va_start (ar, format);
	printlen = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			printlen += printer(format, i, ar, 0);
		}
		else
			printlen += ft_putchar((char)format[i]);
		i++;
	}
	va_end(ar);
	return (printlen);
}
