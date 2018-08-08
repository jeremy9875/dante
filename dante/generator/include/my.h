/*
** my.h for my in /home/jeremy.elkaim/dante/generator/include
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Fri May  5 11:11:35 2017 jeremy elkaim
** Last update Sun May 14 22:09:27 2017 Sridhar Vengadesan
*/

#ifndef MY_H_
# define MY_H_

#include <string.h>

#define PERFECT "perfect"

typedef struct	s_position
{
  int		x;
  int		y;
  int		x2;
  int		y2;
  int		tmp;
  int		count;
  int		tmp2;
}		t_pos;

char	**malloc_maze(int width, int height);
void	change_maze(char **maze, int x, int y);
int	position(char *xb, char *yb, int perfect);
int	check_perfect(char **maze, int width, int height);
int	check_str_is_numb(char *str);
t_pos	check_next_pos(t_pos pos);
void	init_path(char **maze, int width, int height);
t_pos	check_path(char **maze, t_pos pos, int width, int height);
int	parser(char **av, int ac);
void	show_maze(char **maze, int height);
int	complete_maze(int x, int y, char **maze, int perfect);
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
int	my_strcmp(char *cmp, char *str);
int	my_getnbr(char *str);

#endif /* !MY_H_ */
