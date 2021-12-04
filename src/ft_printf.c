/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:47:19 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/04 23:22:30 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list arg, char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_putchar(va_arg(arg, char));
	else if (type == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (type == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putnbr_base(va_arg(arg, unsigned long),
				"0123456789abcdef", 16);
	}
	else if (type == 'd')
		len += ft_putnbr_base(va_arg(arg, int), "0123456789", 10);
	else if (type == 'i')
		len += ft_putnbr_base(va_arg(arg, int), "0123456789", 10);
	else if (type == 'u')
		len += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789", 10);
	else if (type == 'x')
		len += ft_putnbr_base(va_arg(arg, long), "0123456789abcdef", 16);
	else if (type == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *src, ...)
{
	va_list		arg;
	static int	len;

	len = 0;
	va_start(arg, src);
	while (*src)
	{
		if (*src == '%')
			len += ft_type(arg, *src++);
		else
		{
			ft_putchar(*src);
			len++;
		}
		src++;
	}
	va_end(arg);
	return (len);
}
