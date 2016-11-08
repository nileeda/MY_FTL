/*
** system_repair.c for  in /home/nileeda/Documents/C/My_FTL/patin_a
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Tue Nov  8 09:11:01 2016 PATIN Adeline
** Last update Tue Nov  8 11:50:28 2016 PATIN Adeline
*/
#include "ftl.h"
#include <stdlib.h>

static const t_repair_command	repair_comm[] = {
  {"ftl_drive", &ftl_drive_system_repair},
  {"navigation_tools", &navigation_tools_system_repair},
  {"weapon", &weapon_system_repair},
  {NULL, NULL}
};

void	ftl_drive_system_repair(t_ship *ship)
{
  my_putstr_color("yellow", "reparation du reacteur en cours...\n");
  free(ship->drive->system_state);
  ship->drive->system_state = my_strdup("online");
  if (ship->drive->system_state != NULL)
    my_putstr_color("green", "reparation termine! systeme reacteur OK!\n");
  else
    my_putstr_color("red", "les reparations du reacteur ont echoue\n");
}

void	navigation_tools_system_repair(t_ship *ship)
{
  my_putstr_color("yellow", "reparation du systeme de navigation");
  my_putstr_color("yellow", "en cours...\n");
  free(ship->nav_tools->system_state);
  ship->nav_tools->system_state = my_strdup("online");
  if (ship->drive->system_state != NULL)
    {
      my_putstr_color("green", "reparation termine!");
      my_putstr_color("green", "systeme de navigation OK!\n");
    }
  else
    {
      my_putstr_color("red", "les reparations du systeme de navigation");
      my_putstr_color("red"," ont echoue\n");
    }
}

void	weapon_system_repair(t_ship *ship)
{
  my_putstr_color("yellow", "reparation du systeme d'armement ");
  my_putstr_color("yellow", "en cours...\n");
  free(ship->weapon->system_state);
  ship->weapon->system_state = my_strdup("online");
  if (ship->drive->system_state != NULL)
    {
      my_putstr_color("green", "reparation termine! ");
      my_putstr_color("green", "systeme d'armement OK!\n");
    }
  else
    {
      my_putstr_color("red", "les reparations du systeme d'armement ");
      my_putstr_color("red", "ont echoue\n");
    }
}

void	system_repair(t_ship *ship)
{
  char	*str;
  int	i;
  int	bool;

  i = 0;
  bool = 0;
  my_putstr_color("cyan", "repair_system~>");
  str = readline();
  if (str == NULL)
    {
      my_putstr_color("red", "[SYSTEM FAILURE] : le lecteur de ");
      my_putstr_color("red", "commande est bloque\n");
    }
  while (repair_comm[i].repair != NULL)
    {
      if (my_strcmp(str,repair_comm[i].repair) == 0)
	{
	  repair_comm[i].funct_point(ship);
	  bool = 1;
	}
      i++;
    }
  if (bool == 0)
    my_putstr_color("magenta", "[SYSTEM FAILURE] : commande inconnue\n");
}
