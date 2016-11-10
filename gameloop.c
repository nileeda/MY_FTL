/*
** gameloop.c for  in /home/nileeda/Documents/C/My_FTL/patin_a
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 11:41:05 2016 PATIN Adeline
** Last update Thu Nov 10 18:21:17 2016 PATIN Adeline
*/
#include "ftl.h"
#include <stdlib.h>

static const t_gamecontrol	my_control[] = {
  {"attack", &attack_ship},
  {"detect", &detect_freight},
  {"jump", &jump},
  {"getbonus", &get_bonus},
  {"controlsystem", &system_control},
  {"repairsystem", &system_repair},
  {"stat", &stat},
  {"help", &help},
  {NULL, NULL}
};

t_ship		*start()
{
  t_ship	*ship;

  ship = create_ship();
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container_to_ship(ship);
  return (ship);
}

void		gameloop(t_ship *ship)
{
  char		*command;
  t_enemy	*ia;
  int		alive;

  alive = 1;
  ia = malloc(sizeof(*ia));
  if (ia == NULL)
    my_putstr("ERROR MALLOC IA\n");
  ia = NULL;
  while (ship->nav_tools->sector != 10 && alive == 1)
    {
      my_putstr_color("blue", "[A VOS ORDRES COMMANDANT] >");
      command = readline();
      ia = test_opt(ship, ia, command);
      if (ia != NULL && ia->lifepoint >= 0)
	ia = actions_ia(ia, ship);
      alive = player_alive(ship);
    }
}

t_enemy	*test_opt(t_ship *ship, t_enemy *ia, char *command)
{
  int	i;
  int	bool;
  int	result;

  i = 0;
  bool = 0;
  while (my_control[i].control != NULL)
    {
      if (my_strcmp(command, my_control[i].control) == 0)
	{
	  if (my_strcmp(command, my_control[2].control) == 0)
	    {
	      result = my_control[2].funct(ship, ia);
	      if (result == 1)
		ia = appear();
	    }
	  else
	    my_control[i].funct(ship, ia);
	  bool = 1;
	}
      i++;
    }
  if (bool == 0)
    my_putstr_color("red", "[COMMANDE INCONNUE]\n");
  return (ia);
}
