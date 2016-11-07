/*
** my_strcpy.c for  in /home/nileeda/Documents/C-Jour04
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Fri Oct 21 10:32:08 2016 PATIN Adeline
** Last update Fri Oct 21 10:50:22 2016 PATIN Adeline
*/

int	my_strlen(char *str);

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
