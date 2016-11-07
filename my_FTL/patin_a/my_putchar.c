/*
** my_putchar.c for  in /home/nileeda/patin_a/my_putchar
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Mon Oct 17 11:07:48 2016 PATIN Adeline
** Last update Mon Oct 17 11:36:54 2016 PATIN Adeline
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
