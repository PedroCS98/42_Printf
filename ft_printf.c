/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimoes <psimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:39:02 by psimoes           #+#    #+#             */
/*   Updated: 2024/10/02 20:42:13 by psimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, const char *format)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_puthex(n / 16, format);
	ft_putchar(format[n % 16]);
	return (i + 1);
}

int	ft_putptr(unsigned long ptr, const char *format)
{
	int	i;

	i = write(1, "0x", 2);
	if (ptr == 0)
	{
		ft_putchar('0');
		return (i + 1);
	}
	i += ft_puthex(ptr, format);
	return (i);
}

int	ft_print_format_specifier(va_list ap, const char *s, int i)
{
	int	size;

	size = 0;
	if (s[i] == 'c')
		size += ft_putchar(va_arg(ap, int));
	else if (s[i] == 's')
		size += ft_putstr(va_arg(ap, const char *));
	else if (s[i] == 'p')
		size += ft_putptr(va_arg(ap, unsigned long), "0123456789abcdef");
	else if (s[i] == 'd' || s[i] == 'i')
		size += ft_putnbr(va_arg(ap, int));
	else if (s[i] == 'u')
		size += ft_putunbr(va_arg(ap, unsigned int));
	else if (s[i] == 'x')
		size += ft_puthex(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (s[i] == 'X')
		size += ft_puthex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else
		size += ft_putchar('%');
	return (size);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		buffer_size;

	i = 0;
	buffer_size = 0;
	va_start(ap, s);
	if (!s)
		return (-1);
	while (s[i] != 0)
	{
		if (s[i] == '%' && ++i)
		{
			if (!s[i])
				break ;
			buffer_size += ft_print_format_specifier(ap, s, i++);
		}
		else
			buffer_size += ft_putchar(s[i++]);
	}
	va_end(ap);
	return (buffer_size);
}

/*
int main()
{
	int x = ft_printf("This is a test! = %h is correct");
	write(1, "\n", 1);
	ft_putnbr(x);
}
*/
// c s p d i u x X %
/*
%c - Character
%s - String
%p - void pointer
%d - Integer
%i - Integer
%u - Unsigned integer
%x - Lowercase hexadecimal integer
%X - Uppercase hexadecimal integer
%% - Print a single percent sign '%'
*/