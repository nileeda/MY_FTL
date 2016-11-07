/*
** main.c for  in /home/nileeda/Documents/C/My_FTL
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:52:56 2016 PATIN Adeline
** Last update Mon Nov  7 16:56:35 2016 PATIN Adeline
*/
#include <stdlib.h>
#include <stdio.h>
#include "ftl.h"

int		main()
{
  t_ship	*ship;
  t_freight	*freight;
  t_freight	*freight2;

  freight = malloc(sizeof(*freight));
  if (freight == NULL)
    return (0);
  freight->item = my_strdup("no item");
  ship = create_ship();
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container_to_ship(ship);
  add_freight_to_container(ship, freight);
  my_put_nbr(ship->container->nb_elem);
  return (0);
}
