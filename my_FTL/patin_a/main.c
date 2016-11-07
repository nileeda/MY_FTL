/*
** main.c for  in /home/nileeda/Documents/C/My_FTL
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:52:56 2016 PATIN Adeline
** Last update Mon Nov  7 13:21:20 2016 PATIN Adeline
*/
#include "ftl.h"

int		main()
{
  t_ship	*ship;
  int		result;

  result = 15;
  ship = create_ship();
  result = add_weapon_to_ship(ship);
  result = add_ftl_drive_to_ship(ship);
  return (0);
}
