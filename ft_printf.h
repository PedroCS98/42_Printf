/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimoes <psimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:39:26 by psimoes           #+#    #+#             */
/*   Updated: 2024/10/02 20:42:38 by psimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(char x);
int	ft_putstr(const char *s);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int u);
int	ft_puthex(unsigned long n, const char *format);
int	ft_putptr(unsigned long ptr, const char *format);
int	ft_print_format_specifier(va_list ap, const char *s, int i);

#endif
