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

#include	"so_long.h"

void print_map(char **map, t_map_size mz)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	for (i = 0; i < mz.rows; i++)
	{
		for (j = 0; j < mz.cols; j++)
			printf("%c ", map[i][j]);
		
		printf("\n");
	}
	

}

void free_map(char **map, t_map_size mz)
{
	int	i; 

	i = 0;
	printf("%d...%d \n", mz.rows, mz.cols);
	while (i <= mz.rows)//update with array size
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(int	argc, char	**argv)
{
	char	*f_name;
	char	**map;
	t_map_size	map_size;

	if(argc != 2)
		return (write(2, "Error\n", 6), 1);
	f_name = argv[1];
	//init_map_size(&map_size); ?? refactor this function to update map_size based on rows and colounms
	init_map(f_name, &map, &map_size);
	print_map(map, map_size);//only for testing purposes. 
	
	free_map(map, map_size);//update with array size
	return (0);
}
