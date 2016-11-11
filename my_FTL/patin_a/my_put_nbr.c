/*
** my_put_nbr.c for  in /home/nileeda/Documents
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Sat Oct 22 15:00:49 2016 PATIN Adeline
** Last update Fri Nov 11 15:48:50 2016 PATIN Adeline
*/
#include "ftl.h"
#include <stdlib.h>
#include <unistd.h>

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

void	my_putchar(const char c)
{
  write(1, &c, 1);
}
