/*
** my_getnbr.c for  in /home/nileeda/Documents/C-Jour05
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Sat Oct 22 17:38:29 2016 PATIN Adeline
** Last update Sat Oct 22 19:37:48 2016 PATIN Adeline
*/

int	my_getnbr(char *str)
{
  int	result;
  int	neg;

  result = 0;
  neg = 1;
  while (*str == '+' || *str == '-')
    {
      if (*str == '-')
	neg = neg * (-1);
      str = str + 1;
    }
  while (*str != '\0')
    {
      if (*str >= '0' && *str <= '9')
	{
	  result = (result * 10) + *str - 48;
	  str = str + 1;
	}
      else if (*str < 47 || *str > 35)
	{
	  return (result * neg);
	}
    }
  result = result * neg;
  return (result);
}
