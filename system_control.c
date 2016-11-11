/*
** system_control.c for  in /home/nileeda/Documents/C/My_FTL/patin_a
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 19:13:23 2016 PATIN Adeline
** Last update Fri Nov 11 15:22:26 2016 PATIN Adeline
*/

#include "ftl.h"

void	ftl_drive_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du reacteur en cours...\n");
  if (my_strcmp(ship->drive->system_state, "online") != 0)
    my_putstr_color("red", "REACTEUR : HS\n");
  else
    my_putstr_color("green", "REACTEUR : OK\n");
}

void	navigation_tools_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du systeme de navigation ");
  my_putstr_color("yellow", "en cours...\n");
  if (my_strcmp(ship->nav_tools->system_state, "online") != 0)
    my_putstr_color("red", "SYSTEME DE NAVIGATION : HS\n");
  else
    my_putstr_color("green", "SYSTEME DE NAVIGATION : OK\n");
}

void	weapon_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du systeme d'armement en cours\n");
  if (my_strcmp(ship->weapon->system_state, "online") != 0)
    my_putstr_color("red", "SYSTEME D'ARMEMENT : HS\n");
  else
    my_putstr_color("green", "SYSTEME D'ARMEMENT : OK!\n");
}

int	system_control(t_ship *ship)
{
  weapon_system_check(ship);
  navigation_tools_system_check(ship);
  ftl_drive_system_check(ship);
  return (0);
}
