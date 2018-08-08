/*
** malloc_maze.c for malloc_maze in /home/VSridhar78/dante
** 
** Made by Sridhar Vengadesan
** Login   <VSridhar78@epitech.net>
** 
** Started on  Wed May 10 12:53:38 2017 Sridhar Vengadesan
** Last update Wed May 10 13:03:54 2017 Sridhar Vengadesan
*/

#include "my.h"
#include <stdlib.h>

char	**malloc_maze(int width, int height)
{
  char **maze;
  int	x;

  x = 0;
  if ((maze = malloc(sizeof(char *) * height)) == NULL)
    return (NULL);
  while (x != height)
    {
      if ((maze[x] = malloc(sizeof(char) * width)) == NULL)
        return (NULL);
      ++x;
    }
  return (maze);
}
