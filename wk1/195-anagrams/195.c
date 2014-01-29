/*
* Jack Farzan & Natalie Barillaro & Jordan Scales
* problem 195 in c
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

/**
 * Permutations of a given string
 *
 * Example permutations('abc') => ['abc', 'cba', ...];
 *
 * Methodology
 * Permutation consists of:
 *   Base case: ''
 *     Permutations: ['']
 *   Inductive step:
 *     each character
 *       appended to all of the permutations of the remaining characters
 */

 int comp (const void * elem1, const void * elem2) 
{
    char f = *((char*)elem1);
    char s = *((char*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

std::list<std::string> permutations(char* s1) 
{
  // Permutations
  // Base case: s1 is the empty string

  //std::list<std::string> result;
  //std::list<std::string> rest;
  char* first, new1, new2;

  int i, j;

  if (sizeof(s1) == 0) 
    result.push_back("");
  else 
  {
    for (i = 0; i < sizeof(s1); i++) 
    {
      first = (char*)malloc(1);
      strncpy(first, s1+i, 1);
      first[1] = '\0';
      new1 = (char*)malloc(i);
      strncpy(new1, s1, i);
      new1[i] = '\0';
      new2 = (char*)malloc(sizeof(s1));
      strncpy(new2, s1+i+1, s1);
      rest = permutations(new1 + new2);

      for (std::string item : rest) 
        result.push_back(first + item);
    }
  }
  qsort(result, sizeof(result), sizeof(*result), comp);
  result.unique();
  return result;
}

int main() 
{
  std::list<std::string> perms;

  perms = permutations("fives");

  for (std::string item : perms) 
    std::cout << item << std::endl;
  
  /*  while (scanf("%d %s", &n) > 2)
    {

    for(i=m+1;i<=n;i++) 
    {
        temp = cycle(i);
        if (temp > max)
      max = temp;
    }
    printf("%d %d %d\n",);
    }
    return(0);*/
}

