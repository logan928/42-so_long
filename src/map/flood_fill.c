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

void flood_fill(char **tab, t_map_size size, t_map_size begin)
{
	char target = tab[begin.rows][begin.cols]; 
       	fill (tab, size, begin.cols, begin.rows, target);	//change begin as per px py
}


void fill(char **tab, t_map_size size,  int x, int y,char target)
{

	if(x >= size.cols || y >= size.rows || x < 0 || y < 0 || tab [y][x] != target)//replace target by other characters w, p, e
		return; 	
	if (tab[y][x] == target)
		tab[y][x]= 'F';

	fill(tab, size, x+1, y, target);
	fill(tab, size, x-1, y, target);
	fill(tab, size, x, y+1, target);
	fill(tab, size, x, y-1, target);
}

static char    **copy_matrix(char **matrix, t_map_size mz)
{
    char    **temp;
    int     i;

    i = 0;
    temp = (char *)malloc(sizeof(char));
    while (i < mz.rows)
    {
        temp[i] = ft_strdup(matrix[i]);
    }
    return temp;
}
