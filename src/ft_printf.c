/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:47:19 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/04 15:54:32 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_type(va_list arg, char type)
{
    if (type == 'c')
        ft_putchar(va_arg(arg, char));
    else if (type == 's')
        ft_putstr(va_arg(arg, char *));
    else if (type == 'p')
    {
        ft_putstr("0x");
        ft_putnbr_base(va_arg(arg, unsigned long), "0123456789abcdef", 16);
    }
    else if (type == 'd')
        ft_putnbr(va_arg(arg, int));
    else if (type == 'i')
        ft_putnbr_base(va_arg(arg, int), "0123456789", 10);
    else if (type == 'u')
        ft_putnbr_base(va_arg(arg, unsigned int), "0123456789", 10);
    else if (type == 'x')
        ft_putnbr_base(va_arg(arg, long), "0123456789abcdef", 16);
    else if (type == '%')
        ft_putchar('%');
}

int ft_printf(const char *src, ...)
{
    va_list arg;
    int len;

    len = 0;
    va_start(arg, src);
    while (*src)
    {
        if (*src == '%')
        {
            ft_type(arg, *src++);
            len++;
        }
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

int main(int ac, char **av)
{
    (void)ac;
    ft_printf()
}