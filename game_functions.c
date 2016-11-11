/*
** game_functions.c for  in /home/nileeda/Documents/C/My_FTL/patin_a
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 10:02:51 2016 PATIN Adeline
** Last update Fri Nov 11 15:21:50 2016 PATIN Adeline
*/

#include "ftl.h"

static int	detect = -1;

char	*select_bonus()
{
  int	random;
  char	*bonus;

  random = (rand()%10) + 1;
  if (random > 7)
    {
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
      my_putstr_color("blue", "Bienvenue dans le secteur ");
      my_put_nbr(ship->nav_tools->sector);
      my_putstr_color("blue", "/10.\n");
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
  my_putstr("\n|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
  my_putstr("| Dommage : ");
  my_put_nbr(ship->weapon->damage);
  my_putstr("\n|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
  my_putstr("| Energy : ");
  my_put_nbr(ship->drive->energy);
  my_putstr("\n|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
  my_putstr("| Esquive : ");
  my_put_nbr(ship->nav_tools->evade);
  my_putstr("\n|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
  my_putstr("| Secteur : ");
  my_put_nbr(ship->nav_tools->sector);
  my_putstr("\n ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯ \n");
  return (0);
}

int	help()
{
  my_putstr("Voici les commandes possibles dans ce vaisseau :\n");
  my_putstr("attack\ndetect\njump\ngetbonus\ncontrolsystem\n");
  my_putstr("repairsystem\nstat\nhelp\n");
  return (0);
}

int		detect_freight(t_ship *ship)
{
  char		*bonus;
  int		i;
  t_freight	*fret;

  i = 0;
  if (detect < ship->nav_tools->sector)
    {
      while (i < 10)
	{
	  fret = malloc(sizeof(*fret));
	  if (fret == NULL)
	    return (42);
	  bonus = select_bonus();
	  fret->item = my_strdup(bonus);
	  add_freight_to_container(ship, fret);
	  i++;
	}
      detect = ship->nav_tools->sector;
      my_putstr_color("blue", "Ajout du fret réussi\n");
      return (0);
    }
  else
    my_putstr_color("blue", "Plus de fret sur cette zone\n");
  return (1);
}
