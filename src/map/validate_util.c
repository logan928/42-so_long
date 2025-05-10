/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:21:27 by uwettasi          #+#    #+#             */
/*   Updated: 2025/05/08 11:21:32 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print_error(char    *msg)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(msg, 2);
    ft_putstr_fd("\n", 2);
    exit(EXIT_FAILURE);
}

void    free_print(char **map, t_map_size mz, char *msg)
{
    free_map(map, mz);
    print_error(msg);
}

void    init_map_size(t_map_size *mz, int r, int c)
{
    (*mz).rows = r;
    (*mz).cols = c;
}

void    init_map_details(t_map_details *md)
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
}

void    update_map_details(t_map_details *md, char element)
{
   // init_map_details(md);
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
    else
        (*md).invalid += 1;
}