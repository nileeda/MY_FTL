/*
** ennemy.c for  in /home/nileeda/Documents/C/My_FTL/patin_a
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 15:19:29 2016 PATIN Adeline
** Last update Wed Nov  9 19:43:53 2016 PATIN Adeline
*/
#include "ftl.h"
#include <stdlib.h>
#include <time.h>

t_enemy	*appear(t_enemy *enemy)
{
  int	random;

  srand(time (NULL));
  random = (rand()%10) + 1;
  if (random >= 1 && random <= 3)
    {
      my_putstr_color("cyan", "Un ennemi apparaît !\n");
      enemy = malloc(sizeof(*enemy));
      enemy->damage = 10;
      enemy->lifepoint = 20;
      return (enemy);
    }
  else
    return (NULL);
}

void	lifepoint_ia(t_enemy *enemy)
{
  my_putstr("Dommages : ");
  my_put_nbr(enemy->damage);
  my_putstr("\nPV : ");
  my_put_nbr(enemy->lifepoint);
  my_putchar('\n');
}

int	attack_ia(t_ship *ship, t_enemy *enemy)
{
  int	random;

  srand(time (NULL));
  random = (rand()%100) + 1;
  if (random >= ship->nav_tools->evade && random <= 100)
    {
      my_putstr_color("cyan", "L'ennemi attaque ! Cachez-vous !\n");
      random = (rand()%100) + 1;
      if (random >= 1 && random <= 20)
	{
	  random = (rand()%3) + 1;
	  if (random == 1)
	    ship->nav_tools->system_state = my_strdup("offline");
	  else if (random == 2)
	    ship->weapon->system_state = my_strdup("offline");
	  else
	    ship->drive->system_state = my_strdup("offline");
	}
      ship->hull = ship->hull - enemy->damage;
    }
  else
    my_putstr_color("magenta", "L'ennemi n'attaque pas. Bouuuuh\n");
  return (ship->nav_tools->sector);
}
