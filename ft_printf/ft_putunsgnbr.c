/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsgnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:15:54 by fmontes           #+#    #+#             */
/*   Updated: 2023/11/06 11:59:34 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putunsgnbr(unsigned int num)
{
	static unsigned int		count;

	count = 0;
	if (num >= 10)
		ft_putunsgnbr(num / 10);
	count += ft_putchar((num % 10) + 48);
	return (count);
}
