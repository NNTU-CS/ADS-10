// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>
class Tree {
private:
  struct Node {
    char v;
    std::vector<Node*> nodes;
    explicit Node(char val) : v(val) {}
  };
  Node* root;
  std::vector<std::vector<char>> perestanovki;
  void newTreeee(const std::vector<char>& counter, Node* ancestors) {
    for (char c : counter) {
      Node* descendants = new Node(c);
      ancestors->nodes.push_back(descendants);
      std::vector<char> c_counter(counter);
      c_counter.erase(std::find(c_counter.begin(), c_counter.end(), c));
      newTreeee(c_counter, descendants);
    }
  }
  void GenaBukin(Node* root, std::vector<char> p) {
    p.push_back(root->v);
    if (root->nodes.empty()) {
      perestanovki.push_back(p);
    }
    for (Node* descendants : root->nodes) {
      GenaBukin(descendants, p);
    }
    p.pop_back();
  }

public:
  explicit Tree(const std::vector<char>& counter) {
    root = new Node('^');
    newTreeee(counter, root);
    GenaBukin(root, {});
  }
  const int Razmer() const {
    return root->nodes.size();
  }
  std::vector<char> GetPerm(int n) const {
    return perestanovki[n];
  }
};
#endif  // INCLUDE_TREE_H_
