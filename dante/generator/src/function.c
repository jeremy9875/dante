/*
** function.c for function in /home/jeremy.elkaim/dante/generator/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Fri May  5 11:17:50 2017 jeremy elkaim
** Last update Wed May 10 10:25:45 2017 Sridhar Vengadesan
*/

#include "my.h"
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

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}

int	my_strcmp(char *cmp, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != cmp[i])
        return (84);
      i++;
    }
  return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	tmp;
  int	result;

  i = my_strlen(str) - 1;
  tmp = 1;
  result = 0;
  while (i >= 0)
    {
      result = ((str[i] - '0') * tmp) + result;
      tmp = tmp * 10;
      i -= 1;
    }
  return (result);
}
