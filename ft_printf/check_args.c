/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:26:37 by fmontes           #+#    #+#             */
/*   Updated: 2023/11/06 11:58:39 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_args(const char *format, int i, va_list ap)
{
	if (format[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format[i + 1] == 'p')
		return (get_mem(va_arg(ap, unsigned long)));
	else if ((format[i + 1] == 'd') || (format[i + 1] == 'i'))
		return (ft_putnbr(va_arg(ap, int)));
	else if (format[i + 1] == 'u')
		return (ft_putunsgnbr(va_arg(ap, unsigned int)));
	else if (format[i + 1] == 'x')
		return (get_lowhex(va_arg(ap, unsigned int)));
	else if (format[i + 1] == 'X')
		return (get_upphex(va_arg(ap, unsigned int)));
	else if (format[i + 1] == '%')
		return (ft_putchar('%'));
	return (0);
}
