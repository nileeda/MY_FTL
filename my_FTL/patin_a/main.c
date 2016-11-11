/*
** main.c for  in /home/nileeda/Documents/C/My_FTL
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:52:56 2016 PATIN Adeline
** Last update Fri Nov 11 09:34:58 2016 PATIN Adeline
*/
#include "ftl.h"
#include <time.h>
#include <stdlib.h>

int		main()
{
  t_ship	*ship;
  srand(time (NULL));

  my_putstr_color("clear", "\n");
  ship = start();
  gameloop(ship);
  return (0);
}

void		endgame(t_ship *ship, t_enemy *enemy)
{
  free(ship);
  free(enemy);
  my_putstr_color("green", "[GAME OVER]\n");
}
