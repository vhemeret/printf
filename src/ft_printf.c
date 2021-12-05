/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:47:19 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/05 20:21:46 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list arg, char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (type == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (type == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putnbr_b(va_arg(arg, unsigned long),
				"0123456789abcdef", 16);
	}
	else if (type == 'd' || type == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (type == 'u')
		len += ft_putnbr_b(va_arg(arg, unsigned int), "0123456789", 10);
	else if (type == 'x')
		len += ft_putnbr_b(va_arg(arg, unsigned int), "0123456789abcdef", 16);
	else if (type == 'X')
		len += ft_putnbr_b(va_arg(arg, unsigned int), "0123456789ABCDEF", 16);
	else if (type == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *src, ...)
{
	va_list		arg;
	static int	len;
	int			i;

	i = -1;
	len = 0;
	va_start(arg, src);
	while (src[++i])
	{
		if (src[i] == '%')
		{
			len += ft_type(arg, src[i + 1]);
			i += 1;
		}
		else
		{
			ft_putchar(src[i]);
			len++;
		}
	}
	va_end(arg);
	return (len);
}
