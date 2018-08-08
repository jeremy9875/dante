/*
** test.c for test in /home/jeremy.elkaim/dante/breadth/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Sun May 14 18:58:38 2017 jeremy elkaim
** Last update Sun May 14 23:35:44 2017 jeremy elkaim
*/

#include <unistd.h>
#include "../include/my.h"

void	my_putchar(char c)
{
  write (1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
