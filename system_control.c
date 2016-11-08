/*
** system_control.c for  in /home/nileeda/Documents/C/My_FTL/patin_a
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 19:13:23 2016 PATIN Adeline
** Last update Tue Nov  8 09:04:14 2016 PATIN Adeline
*/
#include "ftl.h"

void	ftl_drive_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du reacteur en cours...\n");
  if (my_strcmp(ship->drive->system_state, "online") != 0)
    my_putstr_color("red", "reacteur hors service!\n");
  else
    my_putstr_color("green", "reacteur OK!\n");
}

void	navigation_tools_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du systeme de navigation ");
  my_putstr_color("yellow", "en cours...\n");
  if (my_strcmp(ship->nav_tools->system_state, "online") != 0)
    my_putstr_color("red", "systeme de navigation hors service!\n");
  else
    my_putstr_color("green", "systeme de navigation OK!\n");
}

void	weapon_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du systeme d'armement en cours\n");
  if (my_strcmp(ship->weapon->system_state, "online") != 0)
    my_putstr_color("red", "systeme d'armement hors service!\n");
  else
    my_putstr_color("green", "systeme d'armement OK!\n");
}

void	system_control(t_ship *ship)
{
  weapon_system_check(ship);
  navigation_tools_system_check(ship);
  ftl_drive_system_check(ship);
}
