/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:42:43 by uwettasi          #+#    #+#             */
/*   Updated: 2025/03/14 22:27:33 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(char specifier, va_list *ap)
{
	int	length;

	length = 0;
	if (specifier == 'c')
		length += ft_print_char(va_arg(*ap, int));
	else if (specifier == 's')
		length += ft_print_str(va_arg(*ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		length += ft_print_digit((long)va_arg(*ap, int));
	else if (specifier == 'p')
		length += ft_print_ptr(va_arg(*ap, void *));
	else if (specifier == 'u')
		length += ft_print_udigit((long)va_arg(*ap, unsigned int));
	else if (specifier == 'x')
		length += ft_print_hex((unsigned long)va_arg(*ap, unsigned int), 0);
	else if (specifier == 'X')
		length += ft_print_hex((unsigned long)va_arg(*ap, unsigned int), 1);
	else if (specifier == '%')
		length += ft_print_char('%');
	else
		length += write(1, &specifier, 1);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		length;

	va_start(ap, format);
	length = 0;
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			length += ft_print_format(*format, &ap);
		}
		else
			length += ft_print_char(*format);
		format++;
	}
	va_end(ap);
	return (length);
}
