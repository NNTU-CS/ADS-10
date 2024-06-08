// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <string>
#include <vector>

class Tree {
 private:
    struct Node {
      char value = '\0';
      std::vector<Node*> children;
    };
    Node* root;
    std::vector<char> chars;
    mutable std::vector<std::string> permutations;
    void createTree(Node* node, const std::vector<char>& remainingChars) {
        if (remainingChars.empty()) {
            return;
        }
        for (size_t i = 0; i < remainingChars.size(); ++i) {
            Node* child = new Node();
            child->value = remainingChars[i];
            node->children.push_back(child);
            std::vector<char> newRemainingChars(remainingChars.begin(), remainingChars.begin() + i);
            newRemainingChars.insert(newRemainingChars.end(), remainingChars.begin() + i + 1, remainingChars.end());
            createTree(child, newRemainingChars);
        }
    }
    std::vector<std::string> generatePermutations(Node* node, std::string current) const {
        std::vector<std::string> result;
        if (node->children.empty()) {
            result.push_back(current + node->value);
            return result;
        }
        for (Node* child : node->children) {
            auto child_perms = generatePermutations(child, current);
            for (auto& perm : child_perms) {
                result.push_back(node->value + perm);
            }
        }
        return result;
    }

 public:
    explicit Tree(const std::vector<char>& chars) : chars(chars) {
      root = new Node();
      createTree(root, chars);
    };
    std::vector<std::string> getPermutations() const {
      if (permutations.empty()) {
        permutations = generatePermutations(root, std::string());
      }
      return permutations;
    }
};
#endif  // INCLUDE_TREE_H_
