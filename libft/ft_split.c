/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:22:04 by uwettasi          #+#    #+#             */
/*   Updated: 2025/01/06 14:36:00 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char *s, char c)
{
	size_t	count;
	int		word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (count);
}

static int	get_wordlen(const char *s, char delimiter)
{
	int	len;

	len = 0;
	while (s[len] != delimiter && s[len] != '\0')
		len++;
	return (len);
}

static void	free_mem(char **arr, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
		free (arr[i++]);
	free (arr);
}

static char	**arr_generator(char **buffer, int i, const char *s, int w_len)
{
	buffer[i] = ft_substr(s, 0, w_len);
	if (!buffer[i])
	{
		free_mem(buffer, i);
		return (NULL);
	}
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		i;
	int		word_len;

	if (!s)
		return (NULL);
	buffer = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		word_len = get_wordlen(s, c);
		if (word_len > 0)
		{
			if (!arr_generator(buffer, i, s, word_len))
				return (NULL);
			i++;
		}
		s = s + word_len;
	}
	buffer[i] = NULL;
	return (buffer);
}
