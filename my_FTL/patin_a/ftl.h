/*
** ftl.h for  in /home/nileeda/Documents/C/My_FTL
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:17:43 2016 PATIN Adeline
** Last update Thu Nov 10 14:17:37 2016 PATIN Adeline
*/

#ifndef __FTL_H__
# define	__FTL_H__

typedef				struct	s_ship
{
  int				hull;
  struct s_weapon		*weapon;
  struct s_ftl_drive		*drive;
  struct s_navigation_tools	*nav_tools;
  struct s_container		*container;
}				t_ship;

typedef		struct s_weapon
{
  char		*system_state;
  int		damage;
}		t_weapon;

typedef		struct s_ftl_drive
{
  char		*system_state;
  int		energy;
}		t_ftl_drive;

typedef		struct s_navigation_tools
{
  char		*system_state;
  int		sector;
  int		evade;
}		t_navigation_tools;

typedef			struct s_freight
{
  char			*item;
  struct s_freight	*next;
  struct s_freight	*prev;
}			t_freight;

typedef		struct s_container
{
  int		nb_elem;
  t_freight	*first;
  t_freight	*last;
}		t_container;

typedef		struct s_repair_command
{
  char		*repair;
  int		(*funct_point)(t_ship *ship);
}		t_repair_command;

typedef		struct s_gamecontrol
{
  char		*control;
  int		(*funct)();
}		t_gamecontrol;

typedef		struct s_enemy
{
  int		damage;
  int		lifepoint;

}		t_enemy;

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_put_nbr(int nb);
char		*my_strdup(char *str);
t_ship		*create_ship();
int		add_weapon_to_ship(t_ship *ship);
int		add_ftl_drive_to_ship(t_ship *ship);
int		add_navigation_tools_to_ship(t_ship *ship);
int		add_container_to_ship(t_ship *ship);
void		my_putstr_color(const char *color, const char *str);
int		my_strcmp(const char *s1, const char *s2);
void		add_freight_to_container(t_ship *ship, t_freight *freight);
void		del_freight_from_container(t_ship *ship, t_freight *freight);
int		get_bonus(t_ship *ship);
int		system_control(t_ship *ship);
char		*readline(void);
int		system_repair(t_ship *ship);
int		navigation_tools_system_repair(t_ship *ship);
int		weapon_system_repair(t_ship *ship);
int		ftl_drive_system_repair(t_ship *ship);
char		*select_bonus();
int		my_getnbr(char *str);
int		jump(t_ship *ship);
t_ship		*start();
void		gameloop(t_ship *ship);
int		stat(t_ship *ship);
int		help(t_ship *ship);
t_enemy		*appear();
void		lifepoint_ia(t_enemy *enemy);
t_enemy		*test_opt(t_ship *ship, t_enemy *ia, char *str);
int		attack_ia(t_ship *ship, t_enemy *enemy);
int		is_alive(t_enemy *enemy, t_ship *ship);
int		attack_ship(t_ship *ship, t_enemy *enemy);
t_enemy		*actions_ia(t_enemy *enemy, t_ship *ship);
int		detect_freight();
int		player_alive(t_ship *ship);
void		test_opt_select(t_ship *ship, t_enemy *ia, char *command);
#endif
