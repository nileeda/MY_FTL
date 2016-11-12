/*
** container.c for  in /home/nileeda/Documents/C/My_FTL/patin_a
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 13:56:33 2016 PATIN Adeline
** Last update Sat Nov 12 10:26:17 2016 PATIN Adeline
*/

#include "ftl.h"

int		add_container_to_ship(t_ship *ship)
{
  t_container	*container;

  my_putstr_color("yellow", "ajout du container en cours...\n");
  container = malloc(sizeof(*container));
  if (container == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque vous avez pose");
      my_putstr_color("red", " le container\n");
      return (0);
    }
  container->first = NULL;
  container->last = NULL;
  container->nb_elem = 0;
  ship->container = container;
  my_putstr_color("green", "le container a ete ajoute avec succes\n");
  return (1);
}

void	add_freight_to_container(t_ship *ship, t_freight *freight)
{
  char	*my_bonus;

  my_bonus = select_bonus();
  if (ship->container->last == NULL && ship->container->first == NULL)
    {
      freight->prev = NULL;
      freight->next = NULL;
      ship->container->first = freight;
      ship->container->last = freight;
    }
  else
    {
      ship->container->last->next = freight;
      freight->prev = ship->container->last;
      ship->container->last = freight;
      freight->next = NULL;
    }
  ship->container->nb_elem++;
  freight->item = my_bonus;
}

void	del_freight_from_container(t_ship *ship, t_freight *freight)
{
  if (freight != NULL)
    {
      if (freight->prev == NULL && freight->next != NULL)
	{
	  freight->next->prev = freight->prev;
	  ship->container->first = freight->next;
	}
      else if (freight->next == NULL && freight->prev != NULL)
	{
	  freight->prev->next = freight->next;
	  ship->container->last = freight->prev;
	}
      else if (freight->next != NULL && freight->prev != NULL)
	{
	  freight->prev->next = freight->next;
	  freight->next->prev = freight->prev;
	}
      else if (freight->next == NULL && freight->prev == NULL)
	{
	  ship->container->first = NULL;
	  ship->container->last = NULL;
	}
      ship->container->nb_elem--;
    }
}

int		get_bonus(t_ship *ship)
{
  t_freight	*pointeur;

  pointeur = malloc(sizeof(*pointeur));
  pointeur = ship->container->first;
  while (pointeur != NULL)
    {
      if (my_strcmp(pointeur->item, "scrap") != 0)
	{
	  if (my_strcmp(pointeur->item, "attackbonus") == 0)
	    ship->weapon->damage = ship->weapon->damage + 5;
	  else if (my_strcmp(pointeur->item, "evadebonus") == 0)
	    ship->nav_tools->evade = ship->nav_tools->evade + 3;
	  else if (my_strcmp(pointeur->item, "energy") == 0)
	    ship->drive->energy = ship->drive->energy + 1;
	  my_putstr_color("blue", "Bonus ajoutés.\n");
	}
      del_freight_from_container(ship, pointeur);
      pointeur = pointeur->next;
    }
  free(pointeur);
  return (0);
}
