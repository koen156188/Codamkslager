/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 16:41:41 by kslager       #+#    #+#                 */
/*   Updated: 2022/11/03 00:12:44 by koenslager    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char a, int printlen, char *s)
{
	if (a)
		return (write(1, &a, 1));
	while (s[printlen] != '\0')
		write(1, &s[printlen++], 1);
	return (printlen);
}

int	ft_putnbr(int n, int printlen, unsigned int num)
{
	if (num != 0)
	{
		if (num >= 10)
			printlen += ft_putnbr((num / 10), 0, 0);
		return (printlen += ft_putchar((num % 10 + '0'), 0, NULL));
	}
	if (n == -2147483648)
		return (ft_putchar(0, 0, "-2147483648"));
	if (n < 0)
	{
		printlen += ft_putchar('-', 0, NULL);
		n = n * -1;
	}
	if (n >= 10)
		printlen += ft_putnbr((n / 10), 0, 0);
	n = n % 10;
	if (n < 10)
		printlen += (ft_putchar(n += '0', 0, NULL));
	return (printlen);
}

int	ft_hexa(unsigned long int n, int prilen, int factor)
{
	if (factor == 2)
		return (prilen += ft_putchar(0, 0, "0x") + ft_hexa(n, 0, 0));
	if (n >= 16)
	{
		prilen += ft_hexa((n / 16), 0, factor);
		prilen += ft_hexa((n % 16), 0, factor);
	}
	else if (n < 10)
		prilen += ft_putchar(n + '0', 0, NULL);
	else
	{
		if (factor == 0)
			prilen += ft_putchar((n % 10) + 'a', 0, NULL);
		if (factor == 1)
			prilen += ft_putchar((n % 10) + 'A', 0, NULL);
	}
	return (prilen);
}

int	printer(const char *format, int i, va_list ar, int prilen)
{
	char	temp;
	char	*temp2;

	if (format[i] == 'c')
	{
		temp = va_arg(ar, int);
		prilen += write(1, &temp, 1);
	}
	if (format[i] == 'i' || format[i] == 'd')
		prilen += ft_putnbr(va_arg(ar, int), 0, 0);
	if (format[i] == 's')
	{
		temp2 = va_arg(ar, char *);
		if (!temp2)
			prilen += write(1, "(null)", 6);
		else
			prilen += ft_putchar(0, 0, temp2);
	}
	if (format[i] == 'u')
		prilen += ft_putnbr(0, 0, va_arg(ar, unsigned int));
	if (format[i] == '%')
		prilen += ft_putchar('%', 0, NULL);
	if (format[i] == 'x')
		prilen += ft_hexa(va_arg(ar, unsigned int), 0, 0);
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
			if (format[i] == 'X')
				printlen += ft_hexa(va_arg(ar, unsigned int), 0, 1);
			if (format[i] == 'p')
				printlen += ft_hexa(va_arg(ar, unsigned long int), 0, 2);
			printlen += printer(format, i, ar, 0);
		}
		else
			printlen += ft_putchar((char)format[i], 0, NULL);
		i++;
	}
	va_end(ar);
	return (printlen);
}
