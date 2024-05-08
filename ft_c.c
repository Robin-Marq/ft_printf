/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:37:18 by rmarquar          #+#    #+#             */
/*   Updated: 2024/01/29 13:34:31 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function writes a single character
// to the standard output.
// regards from Robin Marquardt

int	ft_c(int c)
{
	return (write(1, &c, 1));
}
