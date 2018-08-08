/*
** main.c for generator in /home/jeremy.elkaim/dante/generator
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Thu Apr 13 16:03:28 2017 jeremy elkaim
** Last update Mon May 22 15:28:58 2017 jeremy elkaim
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int	check_perfect(char **maze, int width, int height)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (y != height)
    {
      while (maze[y][x] != '\0')
	{
	  if (y != 0 && y != height - 1)
	    {
	      if (x != 0 && x != (width -1))
		if (maze[y][x] == '1')
		  if (maze[y][x + 1] == '0' && maze[y][x - 1] == '0' &&
		      maze[y + 1][x] == '0' && maze[y - 1][x] == '0' &&
		      maze[y + 1][x + 1] == '0' && maze[y + 1][x - 1] == '0' &&
		      maze[y - 1][x + 1] == '0' && maze[y - 1][x - 1] == '0')
		    return (84);
	    }
	  ++x;
	}
      x = 0;
      ++y;
    }
  return (0);
}

int	add_imperfection(char **maze, int width, int height)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (y != height)
    {
      while (x != width)
	{
	  if (x != 0 && x != (width - 1) && y != 0 && y != (height - 1))
	    if (maze[y][x] == '1')
	      {
		change_maze(maze, x, y);
		return (0);
	      }
	  ++x;
	}
      x = 0;
      ++y;
    }
  return (0);
}

int	maze_check(char **maze, int x, int y, int perfect)
{
  if (perfect == 1)
    if (check_perfect(maze, x, y) == 84)
      {
	show_maze(maze, y);
	free(maze);
      }
    else
      {
	show_maze(maze, y);
	free(maze);
      }
  else
    if (check_perfect(maze, x, y) != 0)
      {
	show_maze(maze, y);
	free(maze);
      }
    else
      {
	add_imperfection(maze, x, y);
	show_maze(maze, y);
	free(maze);	
      }
  return (0);
}

int	complete_maze(int x, int y, char **maze, int perfect)
{
  int	pos;
  int	nb;

  nb = 0;
  pos = 1;
  maze[nb][0] = '0';
  while (nb != y)
    {
      while (pos != x)
	{
	  maze[nb][pos] = '1';
	  ++pos;
	}
      ++nb;
      pos = 0;
    }
  maze[y - 1][x - 1] = '0';
  init_path(maze, x, y);
  maze_check(maze, x, y, perfect);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac >= 3 && ac <= 4)
    {
      if (parser(av, ac) == 84)
	return (84);
    }
  else
    return (84);
  return (0);
}
