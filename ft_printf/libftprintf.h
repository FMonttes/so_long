/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:45:31 by fmontes           #+#    #+#             */
/*   Updated: 2023/11/06 12:02:59 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	check_args(const char *format, int i, va_list ap);
int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putnbr(int num);
int	ft_putstr(char *str);
int	ft_putunsgnbr(unsigned int num);
int	get_lowhex(unsigned int n);
int	get_upphex(unsigned int n);
int	get_mem(unsigned long n);

#endif
