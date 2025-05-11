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

void parse_map(char **map, t_map_size mz, t_map_details *md)
{
    int     row;
    int     col;
    int     rect;
    int     wall;

    row = 0;
    wall = 1;
    rect = 1;
    while (row < mz.rows)
    {
        col = 0;
        rect = rect && (mz.cols == (int)ft_strlen(map[row]));
        while (col < mz.cols)
        {
            if (row == 0 || row == mz.rows - 1 || col == 0 || col == mz.cols - 1)
                wall = wall && map[row][col] == '1';
            update_map_details(md, (char)(map[row][col]));
            update_start_pos(md, (char)(map[row][col]), row, col );
            update_exit_pos(md, (char)(map[row][col]), row, col );
            col++;
        }
        row++;
    }
    md->is_enclosed = wall;
    md->is_rect = rect;
}

static void read_map(char **new_line, char **line_map, int fd, int *row_count)
{   
    char    *temp;

    temp = ft_strdup(*new_line);
    while (*new_line)
    {
        (*row_count) += 1;
        free(*new_line);
        *new_line = get_next_line(fd);
        if (!(*new_line))
            break;
        if (*line_map)
            free(*line_map);
        *line_map = ft_strjoin(temp, *new_line);
        free(temp);
        if(!(*line_map))
        {
            free(*new_line);
            print_error("Error reading map");
        }
        temp = ft_strdup(*line_map);
    }
    free(temp);
}

void    build_map(int fd, char ***map, char **f_line, t_map_size *mz)
{
    char    *line_map;
    char    *new_line;
    int     row_count;

    row_count = 0;
    new_line = *f_line;
    mz->cols = ft_strlen(*f_line) - 1; 
    line_map = NULL;
    read_map(&new_line, &line_map, fd, &row_count);
    mz->rows = row_count;
    printf("%s \n", line_map);//remove this when done. 
    if (new_line)
        free(new_line);
    validate_empty_lines(&line_map);
    *map = ft_split(line_map, '\n');
    if (!(*map))
        print_error("Error reading map");
    if(line_map)
        free(line_map);
}

void    init_map(char   *f_name, char ***map, t_map_size *mz, t_map_details *md)
{
    int     fd;
    char    *line;
    char    *path;
    
    line = NULL;
    validate_file_name(f_name);
    path = ft_strjoin("./maps/" , f_name);
    fd = open( path, O_RDONLY);
    free(path);
    if (fd == -1)
        print_error("Invalid file descriptor");
    validate_f_empty(fd, &line);
    build_map(fd, map, &line, mz);
    parse_map(*map, *mz, md);
    parse_validate(*map, *mz, *md);
    check_playability(*map, *mz, *md);
    close(fd);

}
