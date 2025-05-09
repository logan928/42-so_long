/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:44:28 by uwettasi          #+#    #+#             */
/*   Updated: 2025/03/14 22:37:03 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		length += ft_print_char((int)str[i]);
		i++;
	}
	return (length);
}
