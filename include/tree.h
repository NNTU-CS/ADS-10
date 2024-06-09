// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>
class Tree {
private:
	struct Node {
		std::vector<Node*> nodes;
		char v;
		explicit Node(char value) : v(value) {}
	};
	Node* root;
	std::vector<std::vector<char>>perestanovki;
	void newTree(const std::vector<char>& counter, Node* ancestors) {
		char c;
		for (char c : counter) {
			Node* descendants = new Node(c);
			ancestors->nodes.push_back(descendants);
			std::vector<char>c_counter(counter);
			c_counter.erase(std::find(c_counter.begin(), c_counter.end(), c));
		}
	}
	void Perestanovki(std::vector<char>p, Node* roots) {
		p.push_back(roots->v);
		if (root->nodes.empty()) {
			perestanovki.push_back(p);
		}
		for (Node* descendants : root->nodes) {
			Perestanovki(p, descendants);
		}
		p.pop_back();
	}
public:
	explicit Tree(const std::vector<char>& counter) {
		root = new Node('.');
		newTree(counter, root);
		Perestanovki(root, {});
	}
	const int Size() const {
		return root->nodes.size();
	}
	std::vector<char>Got(int i) const {
		return perestanovki[i];
	}
};
#endif  // INCLUDE_TREE_H_
