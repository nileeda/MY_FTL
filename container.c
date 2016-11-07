/*
** container.c for  in /home/nileeda/Documents/C/My_FTL/patin_a
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 13:56:33 2016 PATIN Adeline
** Last update Mon Nov  7 16:43:40 2016 PATIN Adeline
*/
#include "ftl.h"
#include <stdlib.h>

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
}
