# include "../include/so_long.h"

void ft_throw_error (char *str)
{
   ft_putstr(str);
   exit (0);
}

void ft_throw_map_error(t_lay **map, int err_num)
{
   ft_free_map_struct(map);
   if (err_num == 10)
      ft_throw_error("ERROR : Malloc map error ");
   else if (err_num == 20)
      ft_throw_error("ERROR : Malloc map error *map size\n");
   else if (err_num == 30)
      ft_throw_error("ERROR : Map isn't rectangle\n");
   else if (err_num == 90)
      ft_throw_error("ERROR : Not allowed char in the map!\n");
   else if (err_num == 100)
      ft_throw_error("ERROR : Wall is open\n");
   else if (err_num == 210)
      ft_throw_error("ERROR : Player less than 1\n");
   else if (err_num == 220)
      ft_throw_error("ERROR : Collectabel less than 1\n");
   else if (err_num == 230)
      ft_throw_error("ERROR : Exit less than 1\n");
   else if (err_num == 240)
      ft_throw_error("ERROR : Player more than 1\n");
   else if (err_num == 250)
      ft_throw_error("ERROR : Exit more than 1\n");
   else if (err_num == 300)
      ft_throw_error("ERROR : Not playable code not reach all collects or the exit\n");
   else if (err_num == 310)
      ft_throw_error("ERROR : Not playable map is to big for the screen! Please resize the width!\n");
   else if (err_num == 320)
      ft_throw_error("ERROR : Not playable map is to big for the screen! Please resize the hight!\n");
   else
      ft_throw_error("!!!THROW A MAP ERROR WITHOUT A CORRECT NUMMBER!!!");
}

void ft_error_map_data(t_lay **map, int err_num, t_mlx_data **data)
{
   ft_free_map_struct(map);
   ft_destoy_screen_free_data(data);
   if (err_num == 410)
      ft_throw_error("ERROR : Could not init windows or display ptr!\n");
   if (err_num == 410)
      ft_throw_error("ERROR : Could not load images!\n");

}

void ft_destoy_screen_free_data(t_mlx_data **data)
{
   ft_destroy_image(data);
   mlx_destroy_window((*data)->mlx_ptr, (*data)->win_ptr);
   mlx_destroy_display((*data)->mlx_ptr);
   free((*data)->mlx_ptr);
   free(*data);
}

void ft_free_map_struct(t_lay **map)
{
    int i_count = 0;
    if ((*map)->map != NULL)
    {
      while ((*map)->map[i_count] != NULL)
      {
         free((*map)->map[i_count]);
         (*map)->map[i_count] = NULL;
         i_count++;
      }
    }
    free((*map)->map);
    (*map)->map = NULL;
    free((*map));
    map = NULL;
}

