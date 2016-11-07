/*
** my_strlen.c for  in /home/nileeda/Documents/C-Jour03/patin_a/my_strlen
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Thu Oct 20 10:31:40 2016 PATIN Adeline
** Last update Thu Oct 20 11:49:18 2016 PATIN Adeline
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
