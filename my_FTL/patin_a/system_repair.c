/*
** system_repair.c for  in /home/nileeda/Documents/C/My_FTL/patin_a
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Tue Nov  8 09:11:01 2016 PATIN Adeline
** Last update Fri Nov 11 15:22:36 2016 PATIN Adeline
*/

#include "ftl.h"

static const t_repair_command	repair_comm[] = {
  {"ftl_drive", &ftl_drive_system_repair},
  {"navigation_tools", &navigation_tools_system_repair},
  {"weapon", &weapon_system_repair},
  {NULL, NULL}
};

int	ftl_drive_system_repair(t_ship *ship)
{
  my_putstr_color("yellow", "reparation du reacteur en cours...\n");
  free(ship->drive->system_state);
  ship->drive->system_state = my_strdup("online");
  if (ship->drive->system_state != NULL)
    {
      my_putstr_color("green", "reparation termine! REACTEUR : OK\n");
      return (0);
    }
  else
    {
      my_putstr_color("red", "les reparations du reacteur ont echoue\n");
      return (1);
    }
}

int	navigation_tools_system_repair(t_ship *ship)
{
  my_putstr_color("yellow", "reparation du systeme de navigation");
  my_putstr_color("yellow", "en cours...\n");
  free(ship->nav_tools->system_state);
  ship->nav_tools->system_state = my_strdup("online");
  if (ship->drive->system_state != NULL)
    {
      my_putstr_color("green", "reparation termine!");
      my_putstr_color("green", "SYSTEME DE NAVIGATION : OK\n");
      return (0);
    }
  else
    {
      my_putstr_color("red", "les reparations du systeme de navigation");
      my_putstr_color("red"," ont echoue\n");
      return (1);
    }
}

int	weapon_system_repair(t_ship *ship)
{
  my_putstr_color("yellow", "reparation du systeme d'armement ");
  my_putstr_color("yellow", "en cours...\n");
  free(ship->weapon->system_state);
  ship->weapon->system_state = my_strdup("online");
  if (ship->drive->system_state != NULL)
    {
      my_putstr_color("green", "reparation termine! ");
      my_putstr_color("green", "SYSTEME D'ARMEMENT : OK\n");
      return (0);
    }
  else
    {
      my_putstr_color("red", "les reparations du systeme d'armement ");
      my_putstr_color("red", "ont echoue\n");
      return (1);
    }
}

int	system_repair(t_ship *ship)
{
  char	*str;
  int	i;
  int	bool;

  bool = 0;
  i = 0;
  my_putstr_color("blue", "repair_system~>");
  str = readline();
  if (str == NULL)
    my_putstr("[SYSTEM FAILURE] : le lecteur de commande est bloque\n");
  while (repair_comm[i].repair != NULL)
    {
      if (my_strcmp(str,repair_comm[i].repair) == 0)
	{
	  repair_comm[i].funct_point(ship);
	  return (0);
	}
      i++;
    }
  if (bool == 0)
    my_putstr_color("magenta", "[SYSTEM FAILURE] : commande inconnue\n");
  return (1);
}
