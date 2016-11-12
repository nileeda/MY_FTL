/*
** gameloop.c for  in /home/nileeda/Documents/C/My_FTL/patin_a
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 11:41:05 2016 PATIN Adeline
** Last update Sat Nov 12 10:16:06 2016 PATIN Adeline
*/

#include "ftl.h"

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

  my_putstr("BIENVENUE ! NOUS ALLONS CREER VOTRE VAISSEAU...\n");
  my_putstr("Vaisseau en cours de construction...\n");
  ship = create_ship();
  if (ship != NULL)
    {
      add_weapon_to_ship(ship);
      add_ftl_drive_to_ship(ship);
      add_navigation_tools_to_ship(ship);
      add_container_to_ship(ship);
      return (ship);
    }
  else
    {
      my_putstr("Vous ne pouvez pas parcourir l'univers sans vaisseau\n");
      return (NULL);
    }
}

int		start_test(t_ship *ship)
{
  if (ship->container == NULL || ship->drive == NULL || ship->weapon == NULL
      || ship->nav_tools == NULL)
    {
      my_putstr("Le vaisseau a explosé.\n");
      my_putstr("Vous ne pouvez pas parcourir l'univers sans vaisseau\n");
      return (1);
    }
  else
    {
      my_putstr("Vaisseau terminé ! Nous sommes prêts, commandant.\n");
      my_putstr("Si vous avez un trou de mémoire, tapez \"help\"\n");
      return (0);
    }
}

void		gameloop(t_ship *ship)
{
  char		*command;
  t_enemy	*ia;
  int		alive;

  alive = 1;
  command = NULL;
  ia = malloc(sizeof(*ia));
  if (ia == NULL)
    my_putstr("ERROR MALLOC IA\n");
  ia = NULL;
  my_putstr("Pour commencer, taper sur une touche différente d'entrée\n");
  command = readline();
  while ((ship->nav_tools->sector != 10) && (alive == 1) &&
	 (command != NULL))
    {
      my_putstr_color("blue", "[A VOS ORDRES COMMANDANT] >");
      command = readline();
      if (my_strcmp(command, "") == 0 || command == NULL)
	  command = NULL;
      ia = test_opt(ship, ia, command);
      if (ia != NULL)
	ia = actions_ia(ia, ship);
      alive = player_alive(ship);
    }
  if (my_strcmp(command, "") != 0 && command != NULL)
    endgame(ship, ia, alive);
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

  void		endgame(t_ship *ship, t_enemy *enemy, int alive)
  {
    if (alive == 0)
      my_putstr_color("red", "Vous avez perdu\n");
    else
      my_putstr_color("green", "YEAH ! Gagné ! Bien joué :)\n");
    free(ship->weapon->system_state);
    free(ship->weapon);
    free(ship->nav_tools->system_state);
    free(ship->nav_tools);
    free(ship->drive->system_state);
    free(ship->drive);
    free(ship->container);
    free(ship);
    free(enemy);
    my_putstr_color("green", "[GAME OVER]\n");
  }
