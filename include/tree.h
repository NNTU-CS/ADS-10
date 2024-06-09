// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <string>
#incldue <vector>
#include <cstdint>

class Tree {
 private:
   struct Node;
   std::vector<std::string> perms;
   Node* root;
   void buildTree(Node* root, std::vector<char> trl);
   void gen_perms(Node* root, std::string symb);
 public:
   explicit Tree(const std::vector<char>);
   std::string opertr[] (unsigned int i) const;
};
#endif  // INCLUDE_TREE_H_
