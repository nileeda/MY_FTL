/*
** main.c for  in /home/nileeda/Documents/C/My_FTL
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:52:56 2016 PATIN Adeline
** Last update Wed Nov  9 11:55:37 2016 PATIN Adeline
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
  freight2 = malloc(sizeof(*freight2));
  if (freight2 == NULL)
    return (0);
  freight3 = malloc(sizeof(*freight3));
  if (freight3 == NULL)
    return (0);
  ship = start();
  gameloop(ship);
  add_freight_to_container(ship, freight);
  /* get_bonus(ship); */
  /* /\* add_freight_to_container(ship, freight3); *\/ */
  /* /\* get_bonus(ship); *\/ */
  /* ship->weapon->system_state = my_strdup("offline"); */
  /* system_control(ship); */
  /* system_repair(ship); */
  /* add_freight_to_container(ship, freight2); */
  /* get_bonus(ship); */
  //repair_com[0].funct_point(ship);
  //weapon_system_repair(ship);
  //system_control(ship);
  //my_putstr(freight->item);
  //my_putstr(freight2->item);
  //my_putstr(freight3->item);
  //my_put_nbr(ship->container->nb_elem);
  return (0);
}
