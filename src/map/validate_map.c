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

void	validate_file_name(char *f_name)
{
	char	*ext;
	char	*last;
	int		len;
	int		s_len;

	ext = ".ber";
	len = (int)ft_strlen(f_name);
	s_len = (int)ft_strlen(ext);
	last = ft_substr(f_name, len - s_len, s_len);
	if (!(len > s_len && \
		(!ft_strnstr(f_name, ext, len - s_len)) && \
		ft_strncmp(last, ext, s_len) == 0))
	{
		free(last);
		print_error("Invalid file name");
	}
	free(last);
}

void	validate_f_empty(int fd, char **line)
{
	*line = get_next_line(fd);
	if (!(*line))
	{
		if (*line)
			free(*line);
		close(fd);
		print_error("Empty file");
	}
}

void	validate_empty_lines(char **map_line)
{
	if (*map_line[0] == '\n')
	{
		free(*map_line);
		print_error("New line at the top");
	}
	if ((ft_strnstr(*map_line, "\n\n", ft_strlen(*map_line) - 1)))
	{
		free(*map_line);
		print_error("Empty line in map");
	}
}

void	parse_validate(char **map, t_map_size mz, t_map_details md)
{
	if (md.is_rect != 1)
		free_print(map, mz, "Invalid map: Map is not rectangular");
	if (md.is_enclosed != 1)
		free_print(map, mz, "Invalid map: Map is not enclosed");
	if (md.collects == 0)
		free_print(map, mz, "Invalid map: No collectibles");
	if (md.exits != 1)
		free_print(map, mz, "Invalid map: Zero or too many exits");
	if (md.players != 1)
		free_print(map, mz, "Invalid map: Zero or too many players");
	if (md.invalid != 0 || md.f_count != 0)
		free_print(map, mz, "Invalid map: Invalid elements");
}

int	check_exit(char **map, int e_row, int e_col, t_map_size mz)
{
	int	i;

	i = 0; 
	if (e_row > 0)
		i = i || (ft_toupper(map[e_row - 1][e_col]) == 'F');
	if (e_row < mz.rows - 1)
		i = i || (ft_toupper(map[e_row + 1][e_col]) == 'F');
	if (e_col > 0)
		i = i || (ft_toupper(map[e_row][e_col - 1]) == 'F');
	if (e_col < mz.cols - 1)
		i = i || (ft_toupper(map[e_row][e_col + 1]) == 'F');
	return (i);
}
