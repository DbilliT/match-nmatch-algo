/*
** match4.c for match in /home/bechad_p/rendu/Piscine_C_match-nmatch
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sun Oct 12 22:06:15 2014 Pierre Bechade
** Last update Sun Oct 12 22:07:38 2014 Pierre Bechade
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int     my_match_algo(char *s1, char *s2, int i, int x)
{
  if (s1[i] == s2[x])
    {
      if (s1[i])
        {
          my_match_algo(s1, s2, i + 1, x + 1);
        }
      else
        {
	  return (1);
        }
    }
  else if (s2[x] == '*')
    {
      return ((my_match_algo(s1, s2, i + 1, x)
	       + my_match_algo(s1, s2, i, x + 1) > 0) ? 1 : 0);
    }
  else
    return (0);
}

int     match(char *s1, char *s2)
{
  int   i;
  int   x;

  i = 0;
  x = 0;
  return (my_match_algo(s1, s2, i, x));
}
