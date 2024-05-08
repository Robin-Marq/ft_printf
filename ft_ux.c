/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ux.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:31:36 by rmarquar          #+#    #+#             */
/*   Updated: 2024/01/30 08:58:17 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function calculates how many digits
// the number has in the given base.
// regards from Robin Marquardt

static	size_t	calc_nr_ux(size_t n, size_t l)
{
	size_t	result;

	if (n == 0)
		result = 1;
	else
	{
		result = 0;
		while (n > 0)
		{
			n = n / l;
			result++;
		}
	}
	return (result);
}

// this function converts a decimal nr. into
// a string depending on the given base
// and returns the string.
// regards from Robin Marquardt

static	char	*allocate_and_convert_ux(size_t n, char *base)
{
	size_t	l;
	size_t	num_digits;
	char	*result;

	if (base == NULL)
		return (NULL);
	result = NULL;
	l = 0;
	num_digits = 0;
	l = ft_strlen(base);
	num_digits = calc_nr_ux(n, l);
	if (n == 0)
		return (ft_strdup(base));
	result = (char *)malloc(num_digits + 1);
	if (result == NULL)
		return (NULL);
	result[num_digits] = '\0';
	while (num_digits > 0)
	{
		num_digits--;
		result[num_digits] = base[n % l];
		n = n / l;
	}
	return (result);
}

// This function converts a decimal number into a string.
// regards from Robin Marquardt

static	char	*ft_convert_ux(size_t n, char *base)
{
	return (allocate_and_convert_ux(n, base));
}

// This function writes an unsigned decimal number to the standard output.
// If the base is NULL, the function returns -1.
// If the base is not NULL, we call the ft_convert_ux function
// to convert the number into a string.
// regards from Robin Marquardt

int	ft_ux(unsigned int n, char *base)
{
	int		l;
	char	*str;

	if (n == 0)
		return (write(1, "0", 1));
	if (base == NULL)
		return (-1);
	l = 0;
	str = ft_convert_ux(n, base);
	if (str == NULL)
		return (-1);
	l = write(1, str, ft_strlen(str));
	free(str);
	return (l);
}
