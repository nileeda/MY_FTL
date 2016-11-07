/*
** my_putstr.c for  in /home/nileeda/Documents/C-Jour03/patin_a/my_putstr
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Thu Oct 20 10:21:16 2016 PATIN Adeline
** Last update Thu Oct 20 10:28:04 2016 PATIN Adeline
*/

void	my_putchar(char c);

void	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}
