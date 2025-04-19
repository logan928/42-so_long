/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:31:44 by uwettasi          #+#    #+#             */
/*   Updated: 2025/01/06 20:24:59 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	if (little[0] == '\0')
		return ((char *)big);
	b = 0;
	while (big[b] != '\0' && b < len)
	{
		l = 0;
		while (little[l] != '\0' && b + l < len && big[b + l] == little[l])
			l++;
		if (little[l] == '\0')
			return ((char *)big + b);
		b++;
	}
	return (NULL);
}
