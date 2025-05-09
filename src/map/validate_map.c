/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:45:19 by uwettasi          #+#    #+#             */
/*   Updated: 2025/05/07 12:45:23 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    validate_file_name(char *f_name)
{
    char    *ext;
    char    *last;
    int     len;
    int     s_len;
    
    ext = ".ber";
    len = (int)ft_strlen(f_name);
    s_len = (int)ft_strlen(ext);
    last = ft_substr(f_name, len-s_len, s_len);

    if (!(len > s_len && \
        (!ft_strnstr(f_name, ext, len-s_len)) &&   \
        ft_strncmp(last,ext, s_len) == 0))
        {
            free(last);
            print_error("Invalid file name");
        }
        free(last);            
}


static void    validate_f_line(int fd, char **line)
{
    //if (!(*line) || !ft_strncmp(*line, "\0", 1) || !ft_strncmp(*line, "\n", 1))
    *line  = get_next_line(fd);
    if (!(*line) )
    {
        if(*line)
            free(*line);
        close(fd);
        print_error("Empty file or new line at begin");
    }
}
    

void    init_map(char   *f_name, char ***map, t_map_size *mz)
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
    validate_f_line(fd, &line);
    build_map(fd, map, &line, mz);
    close(fd);

}
