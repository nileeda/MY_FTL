/*
** ennemy.c for  in /home/nileeda/Documents/C/My_FTL/patin_a
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 15:19:29 2016 PATIN Adeline
** Last update Fri Nov 11 09:59:57 2016 PATIN Adeline
*/
#include "ftl.h"
#include <stdlib.h>
#include <time.h>

int	damage_init = 10;
int	lifepoint_init = 20;

t_enemy		*appear()
{
  int		random;
  t_enemy	*enemy;

  srand(time (NULL));
  random = (rand()%10) + 1;
  if (random >= 1 && random <= 3)
    {
      my_putstr_color("cyan", "Un ennemi apparaît !\n");
      enemy = malloc(sizeof(*enemy));
      enemy->damage = damage_init;
      enemy->lifepoint = lifepoint_init;
      damage_init = damage_init * 1.5;
      lifepoint_init = lifepoint_init * 1.5;
      return (enemy);
    }
  else
    return (NULL);
}

void	lifepoint_ia(t_enemy *enemy)
{
  my_putstr("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
  my_putstr_color("cyan", "|          L'ENNEMI          \n");
  my_putstr("| Dommages : ");
  my_put_nbr(enemy->damage);
  my_putstr("              \n");
  my_putstr("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
  my_putstr("| PV : ");
  my_put_nbr(enemy->lifepoint);
  my_putstr("                    \n");
  my_putstr(" ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
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
    my_putstr_color("cyan", "L'ennemi n'attaque pas. Bouuuuh\n");
  return (ship->nav_tools->sector);
}

int	is_alive(t_enemy *enemy, t_ship *ship)
{
  int	random;

  if (enemy->lifepoint <= 0)
    {
      srand(time (NULL));
      random = (rand()%2) + 1;
      if (random == 1)
	ship->drive->energy--;
      return (0);
    }
  return (1);
}

t_enemy	*actions_ia(t_enemy *enemy, t_ship *ship)
{
  int	alive;

  if (enemy->lifepoint <= 0)
    enemy->lifepoint = 0;
  alive = is_alive(enemy, ship);
  if (alive == 1)
    {
      attack_ia(ship, enemy);
      lifepoint_ia(enemy);
    }
  if (alive == 0)
    {
      my_putstr_color("cyan", "L'ennnemi est ");
      my_putstr_color("red", "mort. ");
      my_putstr_color("cyan", "MOUHAHAHA. Bien joué commandant.\n");
      enemy = NULL;
    }
  return (enemy);
}
