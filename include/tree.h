#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

struct TreeNode {
    char value;
    bool isRoot = false;
    std::vector<TreeNode*> children;

    ~TreeNode() {
        for (auto child : children)
            delete child;
        children.clear();
    }
};

class Tree {
private:
    std::vector<std::vector<char>> permutations;
    TreeNode* root;

    TreeNode* createNode(char value) {
        TreeNode* node = new TreeNode;
        node->value = value;
        return node;
    }

    void addChildren(TreeNode* current, const std::vector<char>& remainingChars) {
        for (char ch : remainingChars) {
            TreeNode* newNode = createNode(ch);
            current->children.push_back(newNode);
            std::vector<char> nextChars;
            for (char nextCh : remainingChars)
                if (nextCh != ch)
                    nextChars.push_back(nextCh);
            addChildren(newNode, nextChars);
        }
    }

    void pullPermutations(TreeNode* currentN, std::vector<char> currentPermut) {
        if (currentN->isRoot == false)
            currentPermut.push_back(currentN->value);
        if (currentN->children.empty())
            permutations.push_back(currentPermut);
        else
            for (TreeNode* child : currentN->children)
                pullPermutations(child, currentPermut);
    }

public:
    explicit Tree(const std::vector<char>& initialChars) {
        root = createNode('\0');
        root->isRoot = true;
        addChildren(root, initialChars);
        std::vector<char> currentPermut;
        pullPermutations(root, currentPermut);
    }   

    ~Tree() {
        delete root;
    }

    std::vector<std::vector<char>> getAllPermutations() const {
        return permutations;
    }
};

#endif  // INCLUDE_TREE_H_
