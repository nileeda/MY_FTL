/*
** ftl.h for  in /home/nileeda/Documents/C/My_FTL
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:17:43 2016 PATIN Adeline
** Last update Mon Nov  7 13:42:32 2016 PATIN Adeline
*/

#ifndef __FTL_H__
# define	__FTL_H__

typedef struct			s_ship
{
  int				hull;
  struct s_weapon		*weapon;
  struct s_ftl_drive		*drive;
  struct s_navigation_tools	*nav_tools;
}				t_ship;

typedef struct	s_weapon
{
  char		*system_state;
  int		damage;
}		t_weapon;

typedef struct	s_ftl_drive
{
  char		*system_state;
  int		energy;
}		t_ftl_drive;

typedef struct	s_navigation_tools
{
  char		*system_state;
  int		sector;
  int		evade;
}		t_navigation_tools;

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_put_nbr(int nb);
char		*my_strdup(char *str);
t_ship		*create_ship();
int		add_weapon_to_ship(t_ship *ship);
int		add_ftl_drive_to_ship(t_ship *ship);
int		add_navigation_tools_to_ship(t_ship *ship);
#endif
