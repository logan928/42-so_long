/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:15:18 by uwettasi          #+#    #+#             */
/*   Updated: 2025/05/12 14:15:32 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_size(t_map_size *mz, int r, int c)
{
	(*mz).rows = r;
	(*mz).cols = c;
}

void	init_map_details(t_map_details *md)
{
	md->walls = 0;
	md->floors = 0;
	md->collects = 0;
	md->exits = 0;
	md->players = 0;
	md->invalid = 0;
	md->is_enclosed = 0;
	md->is_rect = 0;
	md->p_x = 0;
	md->p_y = 0;
	md->e_x = 0;
	md->e_y = 0;
	md->f_count = 0;
}

void	update_map_details(t_map_details *md, char element)
{
	if (element == '1')
		(*md).walls += 1;
	else if (element == '0')
		(*md).floors += 1;
	else if (ft_tolower(element) == 'c')
		(*md).collects += 1;
	else if (ft_tolower(element) == 'e')
		(*md).exits += 1;
	else if (ft_tolower(element) == 'p')
		(*md).players += 1;
	else if (ft_tolower(element) == 'f')
		(*md).f_count += 1;
	else
		(*md).invalid += 1;
}

void	update_start_pos(t_map_details *md, char element, int row, int col)
{
	if (ft_toupper(element) == 'P')
	{
		md->p_x = col;
		md->p_y = row;
	}
}

void	update_exit_pos(t_map_details *md, char element, int row, int col)
{
	if (ft_toupper(element) == 'E')
	{
		md->e_x = col;
		md->e_y = row;
	}
}
