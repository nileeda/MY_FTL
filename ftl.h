/*
** ftl.h for  in /home/nileeda/Documents/C/My_FTL
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:17:43 2016 PATIN Adeline
** Last update Mon Nov  7 16:23:45 2016 PATIN Adeline
*/

#ifndef __FTL_H__
# define	__FTL_H__

typedef struct			s_ship
{
  int				hull;
  struct s_weapon		*weapon;
  struct s_ftl_drive		*drive;
  struct s_navigation_tools	*nav_tools;
  struct s_container		*container;
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

typedef struct		s_freight
{
  char			*item;
  struct s_freight	*next;
  struct s_freight	*prev;
}			t_freight;

typedef struct	s_container
{
  int		nb_elem;
  t_freight	*first;
  t_freight	*last;
}		t_container;

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
#endif
