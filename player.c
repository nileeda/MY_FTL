/*
** player.c for  in /home/nileeda/Documents/C/My_FTL/patin_a
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Thu Nov 10 11:56:23 2016 PATIN Adeline
** Last update Thu Nov 10 15:35:49 2016 PATIN Adeline
*/
#include "ftl.h"
#include <stdio.h>

int	attack_ship(t_ship *ship, t_enemy *enemy)
{
  if (enemy != NULL)
    {
      my_putstr_color("blue", "A L'ATTAQUE !\n");
      enemy->lifepoint = enemy->lifepoint - ship->weapon->damage;
      my_putstr_color("blue", "Nous avons attaqué l'ennemi. Il y a laissé ");
      my_put_nbr(ship->weapon->damage);
      my_putstr_color("blue", " PV !\n");
    }
  return (0);
}

int	player_alive(t_ship *ship)
{
  if (ship->hull <= 0)
    {
      my_putstr_color("blue", "La coque du vaisseau est foutue.\n");
      my_putstr_color("red", "Nous devons nous replier.\n");
      return (0);
    }
  else if (ship->drive->energy <= 0 && ship->nav_tools->sector < 10)
    {
      my_putstr_color("blue", "Nous sombrons dans les ténèbres.\n");
      my_putstr_color("red", "Adieu.\n");
      return (0);
    }
  return (1);
}

void	test_opt_select(t_ship *ship, t_enemy *ia, char *command)
{
  if (ia->lifepoint > 0)
    {
      if ((my_strcmp(command, "jump") == 0) &&
	  ((my_strcmp("offline", ship->drive->system_state) == 0) ||
	   (ia->lifepoint > 0)))
	my_putstr("JE PEUX PAS JUMP PLUMES DE CANARD\n");
    }
  /*else if (ia->lifepoint == 0)
    {
      if ((my_strcmp("offline", "attack") == 0) &&
	       ((my_strcmp(command, ship->weapon->system_state) == 0) ||
		(ia != NULL)))
	my_putstr("JE PEUX PAS ATTACK POIL DE COCHON\n");
	}
  else
    {
      if ((my_strcmp(command, "jump") == 0) &&
	  (my_strcmp("offline", ship->drive->system_state) == 0))
	my_putstr("JE PEUX PAS JUMP PLUMES DE CANARD\n");
      else if ((my_strcmp("offline", "detect") == 0) &&
	       (my_strcmp(command, ship->nav_tools->system_state) == 0))
	my_putstr("JE PEUX PAS DETECT TETE DE CHAMPIGNON\n");
	}*/
}
