/*
** main.c for main in /home/jeremy.elkaim/dante/tournament
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Thu Apr 13 16:03:53 2017 jeremy elkaim
** Last update Sun May 14 23:16:56 2017 Sridhar Vengadesan
*/
#include <unistd.h>

void	my_putchar(char c)
{
  write (1, &c, 1);
}

void	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
}

int	main()
{
  return (84);
}
