/*
** get_next_line.c for gnl in /home/VSridhar78/dante
** 
** Made by Sridhar Vengadesan
** Login   <VSridhar78@epitech.net>
** 
** Started on  Sun May 14 22:33:41 2017 Sridhar Vengadesan
** Last update Sun May 14 23:42:06 2017 jeremy elkaim
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

char		*my_strdup(char *str)
{
  int		i;
  int		len;
  char		*dup;

  i = 0;
  if (str == NULL)
    return (NULL);
  len = my_strlen(str);
  if ((dup = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      dup[i] = str[i];
      ++i;
    }
  dup[i] = '\0';
  return (dup);
}

char		*malloc_line(int fd)
{
  char		*buf;
  int		ret;
  int		count;

  count = 10000000;
  if ((buf = malloc(sizeof(char) * count)) == NULL)
    return (NULL);
  if ((ret = read(fd, buf, count)) == - 1)
    return (NULL);
  buf[ret] = '\0';
  return (buf);
}

char		*get_line(char *dup)
{
  int		count;

  count = 0;
  while ((dup[count] != '\n') && (dup[count] != '\0'))
    ++count;
  dup[count] = '\0';
  return (dup);
}

char		*get_next_line(int fd)
{
  static char	*buf = NULL;
  char		*dup;
  int		count;

  if (buf == NULL)
    {
      if ((buf = malloc_line(fd)) == NULL)
        return (NULL);
      count = my_strlen(buf);
      if (count == 0)
        return (NULL);
    }
  else if (my_strlen(buf) == 0)
    return (NULL);
  if ((dup = my_strdup(buf)) == NULL)
    return (NULL);
  if ((dup = get_line(dup)) == NULL)
    return (NULL);
  buf = buf + my_strlen(dup) + 1;
  return (dup);
}
