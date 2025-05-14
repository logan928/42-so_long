/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:27:20 by uwettasi          #+#    #+#             */
/*   Updated: 2025/05/10 15:27:27 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_arr(char **arr, size_t rows)
{
	size_t	i;

	i = 0;
	while (i < rows)
		free (arr[i++]);
	free (arr);
}

char	**copy_matrix(char **matrix, t_map_size mz)
{
	char	**temp;
	int		i;

	i = 0;
	temp = (char **)malloc(mz.rows * sizeof(char *));
	if (!temp)
		return (NULL);
	while (i < mz.rows)
	{
		temp[i] = ft_strdup(matrix[i]);
		if (!temp[i])
		{
			free_arr(temp, i);
			return (NULL);
		}
		i++;
	}
	return (temp);
}

void	fill(char **tab, t_map_size size, int x, int y)
{
	if (x >= size.cols || y >= size.rows || x < 0 || y < 0 || \
		tab[y][x] == '1' || ft_tolower(tab[y][x]) == 'e' || tab[y][x] == 'F')
		return ;
	tab[y][x] = 'F';
	fill(tab, size, x + 1, y);
	fill(tab, size, x - 1, y);
	fill(tab, size, x, y + 1);
	fill(tab, size, x, y - 1);
}

void	flood_fill(char **tab, t_map_size size, t_map_details md)
{
	fill (tab, size, md.p_x, md.p_y);
}
