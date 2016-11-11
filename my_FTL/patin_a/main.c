/*
** main.c for  in /home/nileeda/Documents/C/My_FTL
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:52:56 2016 PATIN Adeline
** Last update Fri Nov 11 15:20:39 2016 PATIN Adeline
*/

#include "ftl.h"

int		main()
{
  t_ship	*ship;
  int		loop;

  loop = 0;
  srand(time (NULL));
  while (loop == 0)
    {
      my_putstr_color("clear", "\n");
      ship = start();
      gameloop(ship);
      loop = restart();
    }
  return (0);
}

int	restart()
{
  char  *str;

  str = NULL;
  my_putstr("Voulez-vous rejouer ?(o/n)\n");
  while (my_strcmp("O", str) != 0 && my_strcmp("o", str) != 0 &&
	 my_strcmp("n", str) != 0 && my_strcmp("N", str) != 0)
    str = readline();
  if (my_strcmp("O", str) == 0 || my_strcmp("o", str) == 0)
    return (0);
  else if (my_strcmp("N", str) == 0 || my_strcmp("n", str) == 0)
    return (1);
  return (1);
}
