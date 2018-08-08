/*
** main.c for main in /home/jeremy.elkaim/dante/breadth
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Thu Apr 13 16:02:46 2017 jeremy elkaim
** Last update Sun May 14 23:48:52 2017 jeremy elkaim
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../include/my.h"

void	show_maze(char **maze)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (maze[y] != NULL)
    {
      while (maze[y][x] != '\0')
        {
          if (maze[y][x] == 'X')
            my_putchar('X');
          else if (maze[y][x] == 'o')
	    my_putchar('o');
	  else
            my_putchar('*');
          ++x;
        }
      ++y;
      x = 0;
      if (maze[y] != NULL)
	my_putchar('\n');
    }
}

char	**my_parser(int fd)
{
  int	i;
  char	*cur_string;
  char	**tab;

  i = 0;
  if ((tab = malloc(sizeof(*tab) * SIZE)) == NULL)
    return (NULL);
  while ((cur_string = get_next_line(fd)) != NULL)
    {
      tab[i] = cur_string;
      ++i;
    }
  tab[i] = NULL;
  return (tab);
}

void	my_algo(char **maze)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (maze[y] != NULL)
    {
      while (maze[y][x] != '\0')
	{
	  if (maze[y][x] == '*')
	    maze[y][x] = 'o';
	  ++x;
	}
      ++y;
      x = 0;
    }
}

int	my_open(char *str)
{
  int		fd;
  char**	buf;
  int		i;

  i = 0;
  if ((buf = malloc(sizeof(*buf) * SIZE)) == NULL)
    return (FALSE);
  if ((fd = open(str, O_RDONLY)) == - 1 || ((buf = my_parser(fd)) == NULL))
    return (FALSE);
  fd = 0;
  while (buf[i] != NULL)
    {
      while (buf[i][fd] != '\0')
	{
	  if (buf[i][fd] != 'X' && buf[i][fd] != '*' && buf[i][fd] != '\n')
	    return (FALSE);
	  ++fd;
	}
      fd = 0;
      ++i;
    }
  my_algo(buf);
  show_maze(buf);
  return (TRUE);
}

int		main(int ac, char **av)
{
  if (ac != 2)
    return (84);
  if (my_open(av[1]) == FALSE)
    return (84);
  return (0);
}
