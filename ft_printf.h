/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:00:03 by rmarquar          #+#    #+#             */
/*   Updated: 2024/01/29 14:03:35 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

// main functions
int		ft_printf(const char *format, ...);

// Utils2 functions
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);

// Utils functions
int		ft_check_argument(va_list args, char ch);
char	*ft_convert_base(size_t n, char *base);
char	*ft_itoa(unsigned int value);

// Types functions
int		ft_c(int c);
int		ft_s(char *str);
int		ft_p(unsigned long p);
int		ft_d(int d);
int		ft_ux(unsigned int ux, char *base);

#endif
