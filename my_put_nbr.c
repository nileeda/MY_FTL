/*
** my_put_nbr.c for  in /home/nileeda/Documents
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Sat Oct 22 15:00:49 2016 PATIN Adeline
** Last update Fri Nov 11 12:44:01 2016 PATIN Adeline
*/
#include "ftl.h"

void	my_put_nbr(int n)
{
  int	temp;
  int	i;
  long	new_n;

  new_n = n;
  temp = 1;
  if (n < 0)
    {
      my_putchar('-');
      new_n = new_n * (-1);
    }
  while ((new_n / temp) >= 10)
      temp = temp * 10;
  while (temp > 0)
    {
      i = (new_n / temp) % 10;
      my_putchar(i + 48);
      temp = temp / 10;
    }
}

char			*my_strdup(const char *str)
{
  int			i;
  char			*copy;

  i = 0;
  copy = NULL;
  if ((copy = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      copy[i] = str[i];
      i++;
    }
  copy[i] = '\0';
  return (copy);
}
