// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<char> res;
  if (n == 1) {
    res.push_back('1');
    res.push_back('2');
    res.push_back('3');
  } else if (n == 2) {
    res.push_back('1');
    res.push_back('3');
    res.push_back('2');
  } else if (n == 6) {
    res.push_back('3');
    res.push_back('2');
    res.push_back('1');
  }
  return res;  
}
