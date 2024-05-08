/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:37:46 by rmarquar          #+#    #+#             */
/*   Updated: 2024/01/30 08:49:27 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function converts an integer into a string.
// If the integer is negative, the string
// will have a leading minus sign.
// regards from Robin Marquardt

static	char	*convert_int_to_str(int d)
{
	if (d < 0)
		return (ft_itoa(-d));
	else
		return (ft_itoa(d));
}

// This function writes a string to the output.
// regards from Robin Marquardt

static	int	write_with_sign(char *str, char sign)
{
	int	l;

	l = 0;
	if (sign != 0)
		l = l + write(1, &sign, 1);
	l = l + write(1, str, ft_strlen(str));
	return (l);
}

// this function writes a decimal number.
// If d < 0, the number is written with a leading minus sign.
// regards from Robin Marquardt

int	ft_d(int d)
{
	int		result;
	char	*str;
	char	sign;

	str = convert_int_to_str(d);
	sign = 0;
	result = 0;
	if (d < 0)
		sign = '-';
	result = write_with_sign(str, sign);
	free(str);
	return (result);
}
