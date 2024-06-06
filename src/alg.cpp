// Copyright 2022 NNTU-CS
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
std::string permString = tree.getPerm(n - 1);
std::vector<char> perm;
for (int i = 0; i < permString.length(); i++) {
perm.push_back(permString[i]);
}
return perm;
}

struct Tree::Node {
char value;
std::vector<Node*> children;
};

void Tree::constructTree(Node* parent, std::vector<char> trail) {
if (trail.empty()) {
return;
}
if (parent->value != '*') {
for (auto it = trail.begin(); it != trail.end(); it++) {
if (it == parent->value) {
trail.erase(it);
break;
}
}
}
for (char c : trail) {
parent->children.push_back(new Node{c});
}
for (Node child : parent->children) {
constructTree(child, trail);
}
}

void Tree::generatePerm(Node* parent, std::string currentPerm) {
if (parent->children.empty()) {
currentPerm += parent->value;
perm.push_back(currentPerm);
}
if (parent->value != '') {
currentPerm += parent->value;
}
for (Node child : parent->children) {
generatePerm(child, currentPerm);
}
}

Tree::Tree(const std::vector<char> values) {
rootNode = new Node{'*'};
constructTree(rootNode, values);
generatePerm(rootNode);
}

std::string Tree::getPerm(unsigned int index) const {
if (index >= perm.size()) {
return "";
}
if (index < 0) {
throw std::string("Неправильный индекс");
}
return perm[index];
}
