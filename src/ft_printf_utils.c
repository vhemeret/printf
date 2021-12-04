/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:13:35 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/04 15:50:40 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    while (*str++)
        write(1, &str, 1);
}

void    ft_putnbr(int nb)
{
    if (nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);
}

void    ft_putnbr_base(long nb, char *base, int base_size)
{
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if (nb > base_size)
        ft_putnbr_base((nb / base_size), base, base_size);
    ft_putchar(base[nb % base_size]);
}