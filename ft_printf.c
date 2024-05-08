/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:00:28 by rmarquar          #+#    #+#             */
/*   Updated: 2024/01/30 09:01:13 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Read the arguments from char *format and call ft_checker() for each argument.
// ft_checker() will call the correct function for each argument.
// Regards from Robin Marquardt

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		result;

	if (!format)
		return (-1);
	i = 0;
	result = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			result = result + ft_check_argument(args, format[i]);
		}
		else
		{
			result = result + write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (result);
}

// compile with cc ./*.c

// int	main()
// {
// 	ft_printf("Hello %s\n", "World");
// 	ft_printf("Hello %d\n", 42);
// 	ft_printf("Hello %c\n", 'c');
// 	ft_printf("Hello %p\n", &main);
// 	ft_printf("Hello %x\n", 42);
// 	ft_printf("Hello %X\n", 42);
// 	ft_printf("Hello %%\n");

// 	return (0);
// }
