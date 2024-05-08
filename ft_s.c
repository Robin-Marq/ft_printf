/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:40:32 by rmarquar          #+#    #+#             */
/*   Updated: 2024/01/29 14:23:00 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// The handle_null function is used to handle
// the case when the string is NULL.
// We use a double pointer to change the value
// inside of the pointer.
// many regards from Robin Marquardt

static	void	handle_null(char **s)
{
	if (!(*s))
		*s = "(null)";
}

// This function writes a string to the standard output.
// If the string is NULL, it is handled by the function handle_null.
// regards from Robin Marquardt

int	ft_s(char *s)
{
	size_t	len;
	ssize_t	b;

	handle_null(&s);
	len = 0;
	b = 0;
	len = ft_strlen(s);
	b = write(1, s, len);
	return ((int)b);
}
