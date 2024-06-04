// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"
using namespace std;

vector<char> getPerm(const tree& tr, int n) {
    return tr.getConst(n - 1);
}
