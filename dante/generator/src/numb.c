/*
** numb.c for numb in /home/jeremy.elkaim/dante/generator/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Tue May  9 11:34:46 2017 jeremy elkaim
** Last update Wed May 10 11:28:39 2017 Sridhar Vengadesan
*/

#include "my.h"
#include <stdlib.h>
#include <time.h>

int	check_str_is_numb(char *str)
{
  int	tmp;

  tmp = 0;
  while (str[tmp] != '\0')
    {
      if (str[tmp] < '0' || str[tmp] > '9')
        return (84);
      ++tmp;
    }
  return (0);
}

t_pos	check_next_pos(t_pos pos)
{
  pos.x2 = 0;
  pos.y2 = 0;
  if (pos.tmp == 0)
    --pos.y2;
  else if (pos.tmp == 1)
    ++pos.y2;
  else if (pos.tmp == 2)
    ++pos.x2;
  else if (pos.tmp == 3)
    --pos.x2;
  return (pos);
}

void	init_path(char **maze, int width, int height)
{
  t_pos	pos;

  pos.count = 0;
  pos.x = 0;
  pos.y = 0;
  srand(time(NULL));
  while ((pos.x != (width - 1)) && (pos.y != (height - 1)))
    {
      if (pos.x == width - 2)
        pos.tmp = rand() % 2 + 0;
      else if (pos.y == height - 2)
        pos.tmp = rand() % 4 + 2;
      else
        pos.tmp = rand() % 4;
      pos = check_next_pos(pos);
      pos = check_path(maze, pos, width, height);
    }
}

int	position(char *xb, char *yb, int perfect)
{
  int	x;
  int	y;
  char	**maze;

  if (my_getnbr(xb) == 0 || my_getnbr(yb) == 0)
    return (84);
  x = 0;
  y = my_getnbr(yb);
  if ((maze = malloc(sizeof(char *) * y)) == NULL)
    return (84);
  while (x != y)
    {
      if ((maze[x] = malloc(sizeof(char) * my_getnbr(xb))) == NULL)
        return (84);
      ++x;
    }
  if (perfect == 0)
    complete_maze(my_getnbr(xb), my_getnbr(yb), maze, perfect);
  else
    complete_maze(my_getnbr(xb), my_getnbr(yb), maze, perfect);
  return (0);
}
