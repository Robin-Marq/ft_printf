/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:36:04 by rmarquar          #+#    #+#             */
/*   Updated: 2024/01/29 14:03:15 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function belongs to ft_convert_base
// and calculates how many digits
// regards from Robin Marquardt

static	size_t	calc_nr(size_t n, size_t base_length)
{
	size_t	num_digits;

	if (n == 0)
		num_digits = 1;
	else
	{
		num_digits = 0;
		while (n > 0)
		{
			n = n / base_length;
			num_digits++;
		}
	}
	return (num_digits);
}

// this function converts a decimal nr. into
// a string depending on the given base
// and returns the string.
// regards from Robin Marquardt

char	*ft_convert_base(size_t n, char *base)
{
	size_t	l;
	size_t	num_digits;
	char	*result;

	result = NULL;
	l = ft_strlen(base);
	num_digits = calc_nr(n, l);
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

// This function belongs to ft_itoa
// and returns the number of digits from
// the given unsigned int n / how much
// regards from Robin Marquardt

static	int	calc_nr_2(unsigned int n)
{
	int	num_digits;

	if (n == 0)
		num_digits = 1;
	else
	{
		num_digits = 0;
		while (n != 0)
		{
			n = n / 10;
			num_digits++;
		}
	}
	return (num_digits);
}

// this function calculates the number of
// digits of an unsigned int into a string
// and returns the string
// regards from Robin Marquardt

char	*ft_itoa(unsigned int n)
{
	int		num_digits;
	int		i;
	char	*str;

	num_digits = 0;
	i = 0;
	str = NULL;
	num_digits = calc_nr_2(n);
	str = (char *)malloc(num_digits + 1);
	if (str == NULL)
		return (NULL);
	i = num_digits;
	str[i] = '\0';
	while (i > 0)
	{
		i--;
		str[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

// This function call the correct argument and goes
// to the function who is called.
// Regards from Robin Marquardt :-)

int	ft_check_argument(va_list args, char ch)
{
	int	result;

	result = 0;
	if (ch == 'c')
		result = ft_c(va_arg(args, int));
	else if (ch == 's')
		result = ft_s(va_arg(args, char *));
	else if (ch == 'p')
		result = ft_p(va_arg(args, unsigned long));
	else if (ch == 'd' || ch == 'i')
		result = ft_d(va_arg(args, int));
	else if (ch == 'u')
		result = ft_ux(va_arg(args, unsigned int), "0123456789");
	else if (ch == 'x')
		result = ft_ux(va_arg(args, unsigned int), "0123456789abcdef");
	else if (ch == 'X')
		result = ft_ux(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (ch == '%')
		result = write(1, "%", 1);
	return (result);
}
