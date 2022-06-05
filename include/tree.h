// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#pragma once
#include <vector>
#include <string>
#include<iostream>

class Tree {
 private:
  struct list {
    char zn;
    std::vector <list> dl;
  };

  int tekperestn = 0;
  int nperestn = 0;
  list* rt = nullptr;
  std::vector<char> perestn;

  std::vector<char> deleteElem(std::vector<char> arr, char zn) {
    std::vector<char> nVec;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] != zn) {
        nVec.push_back(arr[i]);
      }
    }
    return nVec;
  }

  std::vector<list> createlist(std::vector<char> wk, list* hd) {
    std::vector<list> mtv;
    for (int i = 0; i < wk.size(); i++) {
      list* mt = new list;
      mt->zn = wk[i];
      mt->dl = createlist(deleteElem(wk, wk[i]), mt);
      mtv.push_back(*mt);
    }
    return mtv;
  }

  std::string getElem(list* tek, std::string sl) {
    if (tek->zn != '*') {
      sl = sl + tek->zn;
    }
    for (int k = 0; k < tek->dl.size(); k++) {
      getElem(&tek->dl[k], sl);
    }
    if (sl.length() == rt->dl.size()
       && tekperestn == nperestn - 1 && perestn.empty()) {
      for (int i = 0; i < sl.length(); i++) {
        perestn.push_back(sl[i]);
      }
    } else if (sl.length() == rt->dl.size()) {
      tekperestn++;
    }
    return sl;
  }

 public:
    explicit Tree(std::vector<char> wk) {
    rt = new list;
    rt->zn = '*';
    rt->dl = createlist(wk, rt);
  }

  std::vector<char> getPerm(int c) {
    nperestn = c;
    getElem(rt, "");
    std::vector<char> rslt = perestn;
    perestn.clear();
    tekperestn = 0;
    return rslt;
  }
};

#endif  // INCLUDE_TREE_H_
