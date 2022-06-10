// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <algorithm>
#include <vector>
#include <string>

struct Node {
    char symbol;
    Node *parent;
    std::vector<Node> variants;
};

class Tree {
 private:
    Node *root = new Node;
    std::vector<Node> permutations;
    void makeTree(std::vector<char> array) {
        createNode(root, array);
        link(root);
    }
    void createNode(Node* head, std::vector<char> array) {
        for (int i = 0; i < array.size(); i++) {
            Node *elem = new Node();
            elem->symbol = array[i];
            head->variants.push_back(*elem);
            if (array.size() > 0) {
                createNode(&head->variants[i], expectArray(array, array[i]));
            }
        }
    }
    void link(Node *head) {
        for (Node &child : head->variants) {
            child.parent = head;
            link(&child);
        }
        if (head->variants.size() == 0) {
            permutations.push_back(*head);
        }
    }
    std::vector<char> expectArray(std::vector<char> array, char value) {
        std::vector<char>::iterator position = std::find(array.begin(),
                                                         array.end(), value);
        if (position != array.end())
            array.erase(position);
        return array;
    }

 public:
    explicit Tree(std::vector<char> array) {
        makeTree(array);
    }
    std::vector<char> getPermutationByNumber(Tree tree, int number){
        if (number > permutations.size()) {
            return {};
        }
        std::vector<char> result;
        Node current = permutations[number-1];
        while (current.parent) {
            result.push_back(current.symbol);
            current = *current.parent;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

#endif  // INCLUDE_TREE_H_
