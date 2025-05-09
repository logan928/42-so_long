/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:15:43 by uwettasi          #+#    #+#             */
/*   Updated: 2025/05/08 16:15:46 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    build_map(int fd, char ***map, char **f_line, t_map_size *mz)
{
    char    **line_map;
    char    **new_line;
    int     col_count;

    line_map = ft_strdup(*f_line);
    col_count = 0;
    *new_line = *f_line;
    while (*new_line)
    {
        col_count++;
        free(new_line);
        *new_line = get_next_line(fd);
        

    }

}
