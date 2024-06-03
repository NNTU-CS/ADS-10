// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <string>
#include <algorithm>
#include <vector>

class NodeTree {
 public:
    std::vector<NodeTree*> kids;
    char val;
    explicit NodeTree(char val) : val(val) {}
};

class Tree {
 private:
    NodeTree* root;
    void buildTree(NodeTree* nod, std::vector<char> characters) {
        if (characters.empty()) {
            return;
        }
        for (char character : characters) {
            NodeTree* child = new NodeTree(character);
            nod->kids.push_back(child);
            std::vector<char> remainingCharacters = characters;
            remainingCharacters.erase(std::remove(remainingCharacters.begin(),
                remainingCharacters.end(), character), remainingCharacters.end());
            buildTree(child, remainingCharacters);
        }
    }
public:
    void freeTree(NodeTree* nod) {
        int i = 0;
        while (i < nod->kids.size()) {
            freeTree(nod->kids[i]);
            i++;
        }
        delete nod;
    }
    std::vector<std::string> getPermutations(NodeTree* nod, std::string currentString) const {
        std::vector<std::string> result;
        if (nod->kids.empty()) {
            result.push_back(currentString + nod->val);
            return result;
        }
        int i = 0;
        while (i < nod->kids.size()) {
            std::vector<std::string> childPermutations = getPermutations(nod->kids[i], currentString + nod->val);
            result.insert(result.end(), childPermutations.begin(), childPermutations.end());
            i++;
        }
        return result;
    }
    std::string getPermutation(NodeTree* nod, int ord) const {
        std::vector<std::string> allPermutations = getPermutations(nod, "");
        if (ord < 1 || ord > allPermutations.size()) {
            return "0";
        }
        return allPermutations[ord - 1];
    }
    NodeTree* getRoot() const {
        return root;
    }
    explicit Tree(std::vector<char> characters) {
        root = new NodeTree('\0');
        buildTree(root, characters);
    }
    ~Tree() = default;
};

#endif  // INCLUDE_TREE_H_
