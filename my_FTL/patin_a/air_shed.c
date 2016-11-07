/*
** air_shed.c for  in /home/nileeda/Documents/C/My_FTL
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:29:13 2016 PATIN Adeline
** Last update Mon Nov  7 13:43:27 2016 PATIN Adeline
*/
#include "ftl.h"
#include <stdlib.h>

t_ship		*create_ship()
{
  t_ship	*ship;

  my_putstr("construction du vaisseau en cours...\n");
  ship = malloc(sizeof(*ship));
  if (ship == NULL)
    {
      my_putstr("le vaisseau n'a pas pu être construit par");
      my_putstr(" manque de materiaux\n");
      return (NULL);
    }
  ship->hull = 50;
  ship->weapon = NULL;
  ship->drive = NULL;
  ship->nav_tools = NULL;
  my_putstr("amélioration du vaisseau termine !\n");
  return (ship);
}

int		add_weapon_to_ship(t_ship *ship)
{
  t_weapon	*weapon;

  my_putstr("ajout des armes en cours...\n");
  weapon = malloc(sizeof(*weapon));
  if (weapon == NULL)
    {
      my_putstr("votre vaisseau a explose quand vous avez tente");
      my_putstr(" d'ajouter les armes\n");
      return (0);
    }
  weapon->damage = 10;
  weapon->system_state = my_strdup("online");
  ship->weapon = weapon;
  my_putstr("les armes ont ete ajoutees avec succes !\n");
  return (1);
}

int		add_ftl_drive_to_ship(t_ship *ship)
{
  t_ftl_drive	*drive;

  my_putstr("ajout du reacteur en cours...\n");
  drive = malloc(sizeof(*drive));
  if (drive == NULL)
    {
      my_putstr("votre vaisseau a explose lorsque vous");
      my_putstr(" avez pose le reacteur\n");
      return (0);
    }
  drive->energy = 10;
  drive->system_state = my_strdup("online");
  ship->drive = drive;
  my_putstr("le reacteur a ete ajout avec succes!\n");
  return (1);
}

int			add_navigation_tools_to_ship(t_ship *ship)
{
  t_navigation_tools	*nav_tools;

  my_putstr("ajout des outils de navigations...\n");
  nav_tools = malloc(sizeof(*nav_tools));
  if (nav_tools == NULL)
    {
      my_putstr("votre vaisseau a explose lorsque vous avez pose les ");
      my_putstr("outils de navigations\n");
      return (0);
    }
  nav_tools->sector = 0;
  nav_tools->evade = 25;
  nav_tools->system_state = my_strdup("online");
  ship->nav_tools = nav_tools;
  my_putstr("les outils de navigations ont ete ajoutes avec succes\n");
  return (1);
}
