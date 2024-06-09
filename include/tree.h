// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
class Tree {
 private:
  struct Node {
    char ch;
    std::vector<Node *> nodes;
  };
  Node* root;
  std::vector<std::vector<char>> permutations;

  void buildTree(Node* nodeParam, std::vector<char> charsVectorParam) {
    if (!nodeParam)
      nodeParam = new Node;
    for (int i = 0; i < charsVectorParam.size(); i++) {
      std::vector<char> charsVector = charsVectorParam;
      Node* newNode = new Node;
      newNode->ch = charsVectorParam[i];
      nodeParam->nodes.push_back(newNode);
      charsVector.erase(charsVector.begin() + i);
      buildTree(nodeParam->nodes.back(), charsVector);
    }
  }
  void createPermutations
  (Node* node,  const std::vector<char>& charsVectorParam) {
    std::vector<char> charsVector = charsVectorParam;
    for (int i = 0; i < node->nodes.size(); i++) {
      charsVector.push_back(node->nodes[i]->ch);
      if (node->nodes[i]->nodes.empty())
        if (charsVectorParam.size() != 1)
          permutations.push_back(charsVector);
      createPermutations(node->nodes[i], charsVector);
      charsVector.pop_back();
    }
  }

 public:
  explicit Tree(std::vector<char> charsVectorParam) {
    root = new Node;
    buildTree(root, charsVectorParam);
    createPermutations(root, std::vector<char>());
  }
  std::vector<char> getPerm(int index) const {
    if (index < 0 || index >= permutations.size())
      return std::vector<char>();
    return permutations[index];
  }
};

#endif  // INCLUDE_TREE_H_
