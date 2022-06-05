// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <iostream>
#include <string>
class Tree {
private:
	struct  Branch {
		char Data;
		std::vector<Branch*> subsidiary;
	};
	Branch* root;

	std::vector <char> val;
	std::string element;
	std::vector<char> trunsf;
	std::vector <std::vector<char>> res;

public:
	explicit Branch(std::vector <char> a) {
		Data = a;
		element.resize(a.size());
		transf.resize(a.size());
		Branch* root = new Branch;
		root->Data = '*';
		transform(a, -1, 0, root);
	}

	Branch* Create_Tree(char val) {
		Branch* temp = new Branch;
		temp->Data = val;
		return temp;
	}
	void Transform(std::vector <char> a, int b, int num, Branch* root) {
		if (a.size() == 1) {
			res.push_back(tras);
			return;
		}
		auto c = a.cbegin();
		if (d >= 0) {
			num++;
			a.erase(c + d);
		}
		for (int i = 0; i < a.size(); i++) {
			root->subsidiary.push_back(Create_Tree(a[i]));
			transf[num] = a[i];
			transform(a, i, num, root->subsidiary[i]);
		}
	}
	std::vector<char> getPerm(Tree tree, int num) {
		if (num > res.size())return{};
		return res[num - 1];
	}
};

#endif  // INCLUDE_TREE_H_
