/*
** add_imperfection.c for add_imperfection in /home/VSridhar78/dante
** 
** Made by Sridhar Vengadesan
** Login   <VSridhar78@epitech.net>
** 
** Started on  Sun May 14 22:07:00 2017 Sridhar Vengadesan
** Last update Sun May 14 22:08:13 2017 Sridhar Vengadesan
*/

#include "my.h"

void	change_maze(char **maze, int x, int y)
{
  maze[y][x + 1] = '0';
  maze[y][x - 1] = '0';
  maze[y + 1][x] = '0';
  maze[y - 1][x] = '0';
  maze[y + 1][x + 1] = '0';
  maze[y + 1][x - 1] = '0';
  maze[y - 1][x + 1] = '0';
  maze[y - 1][x - 1] = '0';
}
