/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_upphex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:46:21 by fmontes           #+#    #+#             */
/*   Updated: 2023/11/06 10:35:24 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_upphex(unsigned int n)
{
	int		i;
	int		k;
	char	rem;
	char	str[8];

	i = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		rem = n % 16;
		if (rem < 10)
			str[i] = rem + 48;
		else
			str[i] = rem + 55;
		n = n / 16;
		i++;
	}
	k = i;
	while (i--)
		write(1, &str[i], 1);
	return (k);
}
