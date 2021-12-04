/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:50:03 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/04 15:50:43 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int     ft_printf(const char *, ...);
void    ft_type(va_list arg, char type);
void    ft_putnbr_base(long nb, char *base, int base_size);
void    ft_putnbr_unsigned(unsigned int nb);
void    ft_putnbr(int nb);
void    ft_putchar(char c);

#endif
