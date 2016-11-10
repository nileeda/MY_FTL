/*
** game_functions.c for  in /home/nileeda/Documents/C/My_FTL/patin_a
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 10:02:51 2016 PATIN Adeline
** Last update Thu Nov 10 18:02:36 2016 PATIN Adeline
*/
#include "ftl.h"
#include <stdlib.h>
#include <time.h>

char	*select_bonus()
{
  int	random;
  char	*bonus;

  srand(time (NULL));
  random = (rand()%10) + 1;
  if (random > 7)
    {
      srand(time (NULL));
      random = (rand()%100) + 1;
      if (random >= 1 && random < 34)
	bonus = "attackbonus";
      else if (random >=34 && random < 67)
	bonus = "evadebonus";
      else if (random >=67 && random < 99)
	bonus = "energy";
      else
	bonus = "scrap";
    }
  else
    bonus = "scrap";
  return (bonus);
}

int	jump(t_ship *ship, t_enemy *enemy)
{
  if (enemy == NULL)
    {
      my_putstr_color("blue", "Préparation du super saut... 3... 2... 1...\n");
      ship->nav_tools->sector++;
      ship->drive->energy--;
      my_putstr_color("blue", "Bienvenue dans la dimention suivante.\n");
      return (1);
    }
  else
    {
      my_putstr("Les ressorts sont morts, chef...\n");
      return (0);
    }
}

int	stat(t_ship *ship)
{
  my_putstr("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
  my_putstr_color("blue", "|        LE VAISSEAU         \n");
  my_putstr("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
  my_putstr("| Coque : ");
  my_put_nbr(ship->hull);
  my_putstr("                 \n");
  my_putstr("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
  my_putstr("| Dommage : ");
  my_put_nbr(ship->weapon->damage);
  my_putstr("               \n");
  my_putstr("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
  my_putstr("| Energy : ");
  my_put_nbr(ship->drive->energy);
  my_putstr("                \n");
  my_putstr("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
  my_putstr("| Esquive : ");
  my_put_nbr(ship->nav_tools->evade);
  my_putstr("               \n");
  my_putstr(" ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯ \n");
  return (0);
}

int	help(t_ship *ship)
{
  my_putstr("Voici les commandes possibles dans ce vaisseau :\n");
  my_putstr("attack\ndetect\njump\ngetbonus\ncontrolsystem\n");
  my_putstr("repairsystem\nstat\nhelp\n");
  return (ship->nav_tools->sector);
}

int	detect_freight()
{
  char	*bonus;

  bonus = select_bonus();
  return (0);
}
