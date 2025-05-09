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
    char    *line_map;
    char    *new_line;
    char    *temp;
    int     col_count;

    //line_map = ft_strdup("");
    //*f_line  = get_next_line(fd);
    temp = ft_strdup(*f_line);
    col_count = 0;
    new_line = *f_line;
    mz->cols = 0;
    line_map = NULL;
    while (new_line)
    {
        col_count++;
        free(new_line);
        new_line = get_next_line(fd);
        if (!new_line)
        {
            break;
        }
        if (line_map)
            free(line_map);
        line_map = ft_strjoin(temp, new_line);
        if(!line_map)
        {
            free(*f_line);
            free(new_line);
            free(temp);
            print_error("Error reading map");
        }
        free(temp);
        temp = ft_strdup(line_map);
    }
    free(temp);
    *map = ft_split(line_map, '\n');
    if (!(*map))
    {
            free(*f_line);
            free(new_line);
            print_error("Error reading map");
    }
    if (new_line)
        free(new_line);
    if(line_map)
        free(line_map);

}
