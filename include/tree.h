// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>

class Tree {
 public:
    explicit Tree(std::vector<char> x) {
        rt = new Node;
        rt->val = '/';
        BuildT(rt, x);
        PermNumb(rt);
    }
    std::string operator[](int i) const {
        if (i >= prm.size()) {
            return "";
        }
    return prm[i];
    }

    std::vector<char> getPrm(const Tree& tree, int n) {
        std::string res = tree[n-1];
        std::vector<char> prm;
        for (int i = 0; i < res.length(); ++i) {
            prm.push_back(res[i]);
        }
      return prm;
    }

 private:
    struct Node {
        char val;
        std::vector<Node*> vect;
    };
    Node* rt;
    std::vector<std::string> prm;
    void BuildT(Node* rt, std::vector<char> temp) {
    if (!temp.size()) {
     return;
    }
        if (rt->val != '/') {
            std::vector<char>::iterator t = temp.begin();
            while (t != temp.end()) {
                if (*t == rt->val) {
                    temp.erase(t);
                    break;
                }
                t++;
            }
        }
    int i = 0;
        while (i < temp.size()) {
            rt->vect.push_back(new Node);
            i++;
        }
        for (int i = 0; i < rt->vect.size(); ++i) {
            rt->vect[i]->val = temp[i];
        }
        for (int i = 0; i < rt->vect.size(); ++i) {
            BuildT(rt->vect[i], temp);
        }
    }

    void PermNumb(Node* rt, std::string s = "") {
        if (!rt->vect.size()) {
            s = s + rt->val;
            prm.push_back(s);
            return;
        }
        if (rt->val != '/') {
            s = s + rt->val;
        }
        int i = 0;
        while (i < rt->vect.size()) {
            PermNumb(rt->vect[i], s);
            i++;
        }
    }
};
#endif  // INCLUDE_TREE_H_
