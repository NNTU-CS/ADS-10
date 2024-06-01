// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
    struct Node {
     char value;
     std::vector<Node *> potomki;
    };
    Node *root;
    std::vector<std::vector<char>> vecPermutations;

    void treeBuild(Node* &root, std::vector<char> initValues) {
     int vecSize = initValues.size();
     for (int i = 0; i < vecSize; i++) {
      Node* potomok = new Node;
      std::vector<char> leftValues = initValues;
      potomok->value = initValues[i];
      root->potomki.push_back(potomok);
      leftValues.erase(leftValues.begin() + i);
      treeBuild(root->potomki.back(), leftValues);
     }
    }
    void createPerms(Node* currentNode, const std::vector<char>& initVal) {
     std::vector<char> leftVal = initVal;
     for (int i = 0; i < currentNode->potomki.size(); i ++) {
      leftVal.push_back(currentNode->potomki[i]->value);
      if (currentNode->potomki[i]->potomki.empty() && leftVal.size() > 1)
       vecPermutations.emplace_back(leftVal);
      createPerms(currentNode->potomki[i], leftVal);
      leftVal.pop_back();
     }
    }

 public:
    explicit Tree(std::vector<char> inputValues): root(nullptr) {
     std::vector<char> newValVec;
     root = new Node;
     treeBuild(root, inputValues);
     createPerms(root, newValVec);
    }
    std::vector<char> getPermByIndex(int i) const {
     if (i < 0 || i >= static_cast<int>(vecPermutations.size())) {
      return std::vector<char>();
     }
      return vecPermutations[i];
    }
};
#endif  // INCLUDE_TREE_H_
