/*
** parser.c for parser in /home/VSridhar78/dante
** 
** Made by Sridhar Vengadesan
** Login   <VSridhar78@epitech.net>
** 
** Started on  Wed May 10 10:47:51 2017 Sridhar Vengadesan
** Last update Sun May 14 19:03:33 2017 jeremy elkaim
*/

#include "my.h"

void	show_maze(char **maze, int height)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (y != height)
    {
      while (maze[y][x] != '\0')
        {
          if (maze[y][x] == '1')
            my_putchar('X');
          else
            my_putchar('*');
          ++x;
          if (maze[y][x] == '\0' && y != height - 1)
            my_putchar('\n');
        }
      ++y;
      x = 0;
    }
}

t_pos	check_path(char **maze, t_pos pos, int width, int height)
{
  pos.tmp2 = 84;
  if (pos.x == 0 && pos.x2 == - 1)
    return (pos);
  if (pos.y == 0 && pos.y2 == - 1)
    return (pos);
  if (pos.x == (width - 1) && pos.x2 == 1)
    return (pos);
  if (pos.y == (height - 1) && pos.y2 == 1)
    return (pos);
  pos.y = pos.y + pos.y2;
  pos.x = pos.x + pos.x2;
  if (maze[pos.y][pos.x] == '1')
    maze[pos.y][pos.x] = '0';
  pos.tmp2 = 0;
  return (pos);
}

static int	check_argv(char **av, int ac, int tmp, int nb)
{
  while (nb != ac)
    {
      while (av[nb][tmp] != '\0')
        {
          if (nb == 1 || nb == 2)
            if (check_str_is_numb(av[nb]) == 84)
              return (84);
          if (nb == 3)
            if (my_strcmp(PERFECT, av[nb]) == 84)
              return (84);
          ++tmp;
        }
      tmp = 0;
      ++nb;
    }
  return (0);
}

int	parser(char **av, int ac)
{
  int   tmp;
  int   nb;

  tmp = 0;
  nb = 1;
  if ((check_argv(av, ac, tmp, nb)) == 84)
    return (84);
  if (ac == 4)
    {
      if ((position(av[1], av[2], 1)) == 84)
	return (84);
    }
  else
    if ((position(av[1], av[2], 0)) == 84)
      return (84);
  return (0);
}
