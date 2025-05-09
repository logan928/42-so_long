/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:52:49 by uwettasi          #+#    #+#             */
/*   Updated: 2025/03/14 22:32:13 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int			length;
	uintptr_t	int_value;

	length = 0;
	if (ptr == NULL)
	{
		length += ft_print_str("(nil)");
		return (length);
	}
	length += ft_print_str("0x");
	int_value = (uintptr_t)ptr;
	length += ft_print_hex(int_value, 0);
	return (length);
}
