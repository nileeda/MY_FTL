/*
** player.c for  in /home/nileeda/Documents/C/My_FTL/patin_a
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Thu Nov 10 11:56:23 2016 PATIN Adeline
** Last update Sat Nov 12 10:19:16 2016 PATIN Adeline
*/

#include "ftl.h"

int	attack_ship(t_ship *ship, t_enemy *enemy)
{
  if (enemy != NULL && my_strcmp("offline", ship->weapon->system_state) != 0)
    {
      my_putstr_color("blue", "A L'ATTAQUE !\n");
      enemy->lifepoint = enemy->lifepoint - ship->weapon->damage;
      my_putstr_color("blue", "Nous avons attaqué l'ennemi. Il y a laissé ");
      my_put_nbr(ship->weapon->damage);
      my_putstr_color("blue", " PV !\n");
    }
  else
    my_putstr("Nous rencontrons un problème...\n");
  return (0);
}

int	player_alive(t_ship *ship)
{
  if (ship->hull <= 0)
    {
      my_putstr_color("red", "La coque du vaisseau est foutue.\n");
      my_putstr_color("red", "Nous devons nous replier.\n");
      return (0);
    }
  else if (ship->drive->energy <= 0 && ship->nav_tools->sector < 10)
    {
      my_putstr_color("red", "Sans energie, nous sombrons dans les ");
      my_putstr_color("red", "tenebres.\nAdieu.\n");
      return (0);
    }
  return (1);
}
