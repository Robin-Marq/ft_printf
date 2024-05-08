/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:37:56 by rmarquar          #+#    #+#             */
/*   Updated: 2024/01/30 08:51:11 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function is to convert to hex
// many regards Robin Marquardt

static	char	*convert_to_hex(unsigned long p)
{
	return (ft_convert_base(p, "0123456789abcdef"));
}

// This function is adding the "0x"
// and freeing the hex string
// many regards Robin Marquardt

static	char	*format_and_free(char *hex_str)
{
	char	*result;

	result = ft_strjoin("0x", hex_str);
	free(hex_str);
	return (result);
}

// This function is converting a pointer to
// a hexadecimal string
// many regards Robin Marquardt

int	ft_p(unsigned long p)
{
	char	*hex_str;
	char	*result;
	int		i;

	if (p == 0)
		return (write(1, "0x0", 3));
	hex_str = convert_to_hex(p);
	result = format_and_free(hex_str);
	i = 0;
	i = write(1, result, ft_strlen(result));
	free(result);
	return (i);
}
