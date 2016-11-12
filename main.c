/*
** main.c for  in /home/nileeda/Documents/C/My_FTL
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:52:56 2016 PATIN Adeline
** Last update Sat Nov 12 12:04:08 2016 PATIN Adeline
*/

#include "ftl.h"

int		main()
{
  t_ship	*ship;
  int		game_start;

  game_start = 1;
  srand(time (NULL));
  my_putstr_color("clear", "\n");
  ship = start();
  if (ship != NULL)
    game_start = start_test(ship);
  if (game_start == 0)
    gameloop(ship);
  return (0);
}
