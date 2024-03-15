/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:21:15 by fmontes           #+#    #+#             */
/*   Updated: 2023/11/06 12:00:13 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	if_zero(void);

int	get_mem(unsigned long n)
{
	int		i;
	int		k;
	char	rem;
	char	str[16];

	i = 0;
	if (n == 0)
		return (if_zero());
	while (n > 0)
	{
		rem = n % 16;
		if (rem < 10)
			str[i] = rem + 48;
		else
			str[i] = rem + (55 + 32);
		n = n / 16;
		i++;
	}
	str[i++] = 'x';
	str[i++] = '0';
	k = i;
	while (i--)
		write(1, &str[i], 1);
	return (k);
}

static int	if_zero(void)
{
	ft_putstr("(nil)");
	return (5);
}
