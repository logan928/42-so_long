/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:43:57 by uwettasi          #+#    #+#             */
/*   Updated: 2025/03/14 22:24:54 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(long n)
{
	int	length;

	length = 0;
	if (n == LONG_MIN)
	{
		length += ft_print_char('-');
		n = -(n / 10);
		length += ft_print_digit(n);
		length += ft_print_char('8');
		return (length);
	}
	if (n < 0)
	{
		length += ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
		length += ft_print_digit(n / 10);
	length += ft_print_char((n % 10) + '0');
	return (length); 
}
