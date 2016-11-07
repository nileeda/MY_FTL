/*
** my_put_nbr.c for  in /home/nileeda/Documents
** 
** Made by PATIN Adeline
** Login   <patin_a@etna-alternance.net>
** 
** Started on  Sat Oct 22 15:00:49 2016 PATIN Adeline
** Last update Wed Oct 26 19:46:07 2016 PATIN Adeline
*/

void	my_putchar(char c);

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
