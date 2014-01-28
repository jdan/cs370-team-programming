/*
* Jack Farzan & Natalie Barillaro & Jordan Scales
* problem 195 in cpp
*/

#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include "stdlib.h"
#include <list>

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
std::list<std::string> permutations(std::string s1) {
  // Permutations
  // Base case: s1 is the empty string

  std::list<std::string> result;
  std::list<std::string> rest;
  std::string first;

  int i, j;

  if (s1.length() == 0) {
    result.push_back("");
  } else {

    for (i = 0; i < s1.length(); i++) {
      first = s1.substr(i, 1);
      rest = permutations(s1.substr(0, i) + s1.substr(i+1));

      for (std::string item : rest) {
        result.push_back(first + item);
      }
    }
  }

  result.sort();
  result.unique();

  return result;
}

int main() {
  int i, rounds;
  std::string input;
  std::list<std::string> perms;

  std::cin >> rounds;
  for (i = 0; i < rounds; i++) {
    std::cin >> input;

    perms = permutations(input);
    for (std::string item : perms) {
      std::cout << item << std::endl;
    }
  }
}
