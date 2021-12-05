/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:50:03 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/05 13:28:48 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *src, ...);
int		ft_type(va_list arg, char type);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_b(unsigned long nb, char *base, int base_size);
int		ft_putnbr(long nb);

#endif
