/*
** main.c for  in /home/nileeda/Documents/C/My_FTL
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:52:56 2016 PATIN Adeline
** Last update Tue Nov  8 09:58:14 2016 PATIN Adeline
*/
#include <stdlib.h>
#include "ftl.h"

int		main()
{
  t_ship	*ship;
  t_freight	*freight;
  t_freight	*freight2;
  t_freight	*freight3;

  freight = malloc(sizeof(*freight));
  if (freight == NULL)
    return (0);
  freight->item = my_strdup("no item");
  freight2 = malloc(sizeof(*freight2));
  if (freight2 == NULL)
    return (0);
  freight2->item = my_strdup("item2");
  freight3 = malloc(sizeof(*freight3));
  if (freight3 == NULL)
    return (0);
  freight3->item = my_strdup("energy");
  ship = create_ship();
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container_to_ship(ship);
  add_freight_to_container(ship, freight);
  add_freight_to_container(ship, freight2);
  add_freight_to_container(ship, freight3);
  freight->item = my_strdup("attackbonus");
  get_bonus(ship);
  ship->weapon->system_state = my_strdup("offline");
  system_control(ship);
  weapon_system_repair(ship);
  //system_control(ship);
  //my_putstr(freight->item);
  //my_putstr(freight2->item);
  //my_putstr(freight3->item);
  //my_put_nbr(ship->container->nb_elem);
  return (0);
}
