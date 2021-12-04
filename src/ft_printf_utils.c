/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:13:35 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/04 23:04:04 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, str[i], 1);
	return (i);
}

/*int	ft_putnbr(long nb)
{
    static int	len;

    len = 0;
	if (nb > 9)
		ft_putnbr(nb / 10);
	len += ft_putchar((nb % 10) + 48);
    return (len);
}*/

int	ft_putnbr_base(long nb, char *base, int base_size)
{
	static int	len;
	int			sign;

	len = 0;
	sign = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		sign += 1;
	}
	if (nb > base_size)
		ft_putnbr_base((nb / base_size), base, base_size);
	len += ft_putchar(base[nb % base_size]);
	return (len + sign);
}
