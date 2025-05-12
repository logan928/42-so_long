#include	"so_long.h"




void    init_game(t_game *tg, char  **map, t_map_details *md, t_map_size mz)
{
    /*
    tg->mlx = mlx_init();
    if(!(tg->mlx))
    {
        free_map(map, mz.rows);
        print_error("Error creating game handle");
    }
    */
   void *mlx = mlx_init();
    if(!(mlx))
    {
        free_map(map, mz.rows);
        print_error("Error creating game handle");
    }
    tg->height = mz.rows;
    tg->width = mz.cols;
    void *win = mlx_new_window(mlx, (tg->width) * TILE_SIZE, (tg->height) * TILE_SIZE, "Pac 42");
    //tg->win = mlx_new_window(tg->mlx, (tg->width) * TILE_SIZE, (tg->height) * TILE_SIZE, "Pac 42");
    (void)md;
    //(void)map;
    (void)win;
}