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
    //char    *s_str;
    char    *ext;
    int     len;
    int     s_len;
    
    ext = ".ber";
    len = (int)ft_strlen(f_name);
    s_len = (int)ft_strlen(ext);

    if (!(len > s_len && \
        (!ft_strnstr(f_name, ext, len-s_len)) &&   \
        ft_strncmp(ft_substr(f_name, len-s_len, s_len),ext, s_len) == 0))
        {
            print_error("Invalid file name");
        }
            
}

static void    validate_f_line(int fd, char **line)
{
    *line = get_next_line(fd);
    if (!(*line) || !ft_strncmp(*line, "\0", 1) || !ft_strncmp(*line, "\n", 1))
    {
        free(line);
        print_error("Empty file or new line at begin");
    }
}

void    init_map(char   *f_name, char ***map, t_map_size *mz)
{
    int     fd;
    char    **line;
    
    line = NULL;
    validate_file_name(f_name);
    fd = open(ft_strjoin("./maps/" , f_name), O_RDONLY);
    if (fd == -1)
        print_error("Invalid file descriptor");
    validate_f_line(fd, line);
    

}
