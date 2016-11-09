/*
** ennemy.c for  in /home/nileeda/Documents/C/My_FTL/patin_a
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 15:19:29 2016 PATIN Adeline
** Last update Wed Nov  9 16:56:11 2016 PATIN Adeline
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
