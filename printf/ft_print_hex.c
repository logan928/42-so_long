/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:52:32 by uwettasi          #+#    #+#             */
/*   Updated: 2025/03/14 22:30:41 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_len(uintptr_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	write_hex(uintptr_t n, int is_uppercase)
{
	static char	upper_digit[] = "0123456789ABCDEF";
	static char	lower_digit[] = "0123456789abcdef";

	if (n >= 16)
		write_hex(n / 16, is_uppercase);
	if (is_uppercase)
		write(1, &upper_digit[n % 16], 1);
	else 
		write(1, &lower_digit[n % 16], 1);
}

int	ft_print_hex(uintptr_t n, int is_uppercase)
{
	int	length;

	length = 0;
	if (n == 0)
		return (write(1, "0", 1));
	write_hex(n, is_uppercase);
	length = count_len(n);
	return (length);
}
