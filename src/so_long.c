/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:21:37 by uwettasi          #+#    #+#             */
/*   Updated: 2025/05/07 12:21:41 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int row_count)
{
	int	i; 

	i = 0;
	while (i <= row_count)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(int argc, char	**argv)
{
	char			*f_name;
	char			**map;
	t_map_size		map_size;
	t_map_details	map_details;
	t_game			tg;

	if (argc != 2)
		return (write(2, "Error\n", 6), 1);
	f_name = argv[1];
	init_map_details(&map_details);
	init_map(f_name, &map, &map_size, &map_details);
	init_game(&tg, &map, &map_details, map_size);
	init_images(&tg);
	render_game_area(&tg);
	mlx_hook(tg.win, 17, 0 << 1, handle_destroy, &tg);
	mlx_hook(tg.win, 3, 1L << 1, handle_keyrelease, &tg);
	mlx_loop(tg.mlx);
	return (0);
}
