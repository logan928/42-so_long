/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:40:37 by uwettasi          #+#    #+#             */
/*   Updated: 2025/05/07 12:40:44 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#   define  SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "gnl.h"
#include "libft.h"
#include "ft_printf.h"

typedef struct s_map_size
{
    int rows;
    int cols;
}   t_map_size;

typedef struct s_map_details
{
    int walls;
    int floors;
    int exits;
    int collects;
    int players;
    int invalid;
    int is_rect;
    int is_enclosed;
    int p_x;
    int p_y;
}   t_map_details;


void    init_map_size(t_map_size *mz, int r, int c);
void    free_map(char **map, t_map_size mz);
void    init_map(char   *f_name, char ***map, t_map_size *mz, t_map_details *md);
void    init_map_details(t_map_details *md);
void    update_map_details(t_map_details *md, char element);
void    build_map(int fd, char ***map, char **f_line, t_map_size *mz);

void    print_error(char    *msg);
void    free_print(char **map, t_map_size mz, char *msg);
void    validate_file_name(char *f_name);
void    validate_f_empty(int fd, char **line);
void    validate_empty_lines(char **map_line);
void    parse_validate(char **map, t_map_size mz, t_map_details md);



void print_map(char **map, t_map_size mz); //remove before submission

#endif

