// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <cstdint>
#include <string>
#include <vector>

class Tree {
 private:
    struct Nodule;
    std::vector<std::string> repl;
    Nodule* miss;

    void createTree(Nodule* miss, std::vector<char> trail);

    void perms(Nodule* miss, std::string symb);

 public:
    explicit Tree(const std::vector<char>);

    std::string operator[] (unsigned int i) const;
};
#endif  // INCLUDE_TREE_H_
