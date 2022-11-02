/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kslager <kslager@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 16:41:41 by kslager       #+#    #+#                 */
/*   Updated: 2022/11/01 22:30:51 by kslager       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
// #include "ft_printf.h"

int	ft_putchar(char a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_putstr(char *s, int printlen)
{
	while (*s)
		printlen += ft_putchar(*s++);
	return (printlen);
}

int	ft_putnbr(int n, int printlen)
{
	if (n < 0)
	{
		printlen += ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
		printlen += ft_putnbr((n / 10), 0);
	n = n % 10;
	if (n < 10)
		printlen += (ft_putchar(n += '0'));
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

int	printer(const char *format, int i, va_list ar, int prilen)
{
	if (format[i] == 'c')
		prilen += ft_putchar(va_arg(ar, int));
	if (format[i] == 'i' || format[i] == 'd')
		prilen += ft_putnbr(va_arg(ar, int), 0);
	if (format[i] == 's')
		prilen += ft_putstr(va_arg(ar, char *), 0);
	if (format[i] == 'u')
		prilen += ft_putunint(va_arg(ar, unsigned int), 0);
	if (format[i] == '%')
		prilen += ft_putchar('%');
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

int main ()
{
	char *adress = malloc(strlen(k) * sizeof(char))
	if (!adress)
		return (NULL);
	char *k = "hallo";
	void *ptr = &k;
	printf("%lu\n", strlen(ptr));
	write(1, (&ptr), 5);
	// int j = printf("%p\n", kk);

	// printf("mine   : \n%i\n", l); 
	// printf("printf : %i\n", j);
	
}
