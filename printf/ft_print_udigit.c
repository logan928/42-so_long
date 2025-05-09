/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:52:16 by uwettasi          #+#    #+#             */
/*   Updated: 2025/03/14 22:40:17 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_udigit(unsigned long n)
{
	int	length;

	length = 0;
	if (n == 0)
	{
		return (write(1, "0", 1));
	}
	if (n >= 10)
		length += ft_print_udigit(n / 10);
	length += ft_print_char((n % 10) + '0');
	return (length);
}
