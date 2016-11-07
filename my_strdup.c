/*
** my_strdup.c for  in /home/nileeda/Documents/C-Jour07/my_strdup
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Oct 24 14:43:07 2016 PATIN Adeline
** Last update Mon Oct 24 14:52:33 2016 PATIN Adeline
*/

#include <stdlib.h>

int	my_strlen(char *str);
void	my_strcpy(char *dest, char *src);

char	*my_strdup(char *str)
{
  char	*new_str;

  new_str = malloc((my_strlen(str) + 1) * sizeof(*str));
  my_strcpy(new_str, str);
  return (new_str);
}
