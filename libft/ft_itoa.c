/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:48:09 by uwettasi          #+#    #+#             */
/*   Updated: 2025/01/07 12:14:15 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_length_counter(int n)
{
	int	length;

	if (n <= 0)
		length = 1;
	else
		length = 0;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		count;
	long	num;

	num = (long) n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = ft_length_counter(n);
	s = (char *)malloc((count + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[count] = '\0';
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
	}
	while (--count >= 0)
	{
		if (s[count] == '-')
			break ;
		s[count] = (num % 10) + '0';
		num /= 10;
	}
	return (s);
}
