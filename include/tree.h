// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
struct TreeNode {
    vector<TreeNode*> children;
    int value;
};

void buildTree(TreeNode* root, vector<int> elements) {
    if (elements.empty()) {
        return;
    }

    int numChildren = elements.size();
    root->value = elements[0];

    for (int i = 1; i < numChildren; ++i) {
        TreeNode* child = new TreeNode();
        child->value = elements[i];
        root->children.push_back(child);
        buildTree(child, {elements[i + 1], elements[i + 2]});
        ++i;
    }
}

void generatePermutations(TreeNode* root, vector<string>& permutations, string current) {
    if (!root) {
        permutations.push_back(current);
        return;
    }

    current += to_string(root->value);

    for (TreeNode* child : root->children) {
        generatePermutations(child, permutations, current);
    }
}

string getPermutationByNumber(TreeNode* root, int number) {
    vector<string> permutations;
    generatePermutations(root, permutations, "");

    if (number <= permutations.size()) {
        return permutations[number - 1];
    }

    return "";
}
#endif  // INCLUDE_TREE_H_
