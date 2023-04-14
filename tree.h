#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H
#include <iostream>
#include <stack>

using namespace std;

template <class T> class Tree;
#include "node.h"


template <class T>
class Tree {

public:

    Tree();
    bool insert(const T& x);
    size_t getCount() const;
    TreeNode<T>* getR();
    bool delete_node(T value);
    TreeNode<T>* find_min(TreeNode<T>* N);
    TreeNode<T>* find_node(TreeNode<T>* N, const T& value);
    TreeNode<T>* find_next(const T& val);
    int getHeight();
    void inOrderWalk();
    void iterativeWalk() const;
    bool isSimilar(const Tree<T>& other) const;
    Tree <T>& operator= (const Tree <T>&& src) = delete;
    Tree(const Tree<T>& scr) = delete;
    bool isIdenticalKey(Tree<T>& other);
    ~Tree() {};

private:

    TreeNode<T>* root;
    void inorderWalk(TreeNode<T>*);
    size_t getCount(TreeNode<T>* node) const;
    int getHeight(const TreeNode<T>* node) const;

};

template<class T>
Tree<T>::Tree() {

    root = 0;

}

template<class T>
TreeNode<T>* Tree<T>::find_node(TreeNode<T>* N, const T& value) {

    if (N == 0 || value == N->get_data()) {

        return N;

    }

    if (value > N->get_data()) {

        return find_node(N->right, value);

    }
    else {

        return find_node(N->left, value);

    }
}

template<class T>
bool Tree<T>::insert(const T& x) {

    if (find_node(this->root, x) == nullptr) {

        TreeNode<T>* n = new TreeNode<T>(x);
        TreeNode<T>* ptr;
        TreeNode<T>* ptr1;

        n->parent = n->left = n->right = 0;

        ptr = root;
        ptr1 = nullptr;

        while (ptr != 0) {

            ptr1 = ptr;

            if (x < ptr->get_data()) {

                ptr = ptr->left;

            }

            else {

                ptr = ptr->right;

            }

        }

        n->parent = ptr1;

        if (ptr1 == 0) {

            root = n;

        }

        else {

            if (x < ptr1->get_data()) {

                ptr1->left = n;

            }

            else {

                ptr1->right = n;

            }

        }

        return true;

    }
    else {

        return false;

    }
    
}

template<class T>
void Tree<T>::inorderWalk(TreeNode<T>* n) {

    if (n != 0) {

        inorderWalk(n->left);
        cout << n->get_data() << endl;
        inorderWalk(n->right);

    }
}

template<class T>
void Tree<T>::inOrderWalk() {

    inorderWalk(root);

}

template<class T>
TreeNode<T>* Tree<T>::getR() {

    return root;

}
template<class T>
TreeNode<T>* Tree<T>::find_min(TreeNode<T>* N) {

    while (N->left != 0) {

        N = N->left;

    }
    return N;

}
template<class T>
size_t Tree<T>:: getCount(TreeNode<T>* node) const{
    if (node == nullptr) {
        return 0;
    }
    return (1 + getCount(node->left) + getCount(node->right));
}
template<class T>
size_t Tree<T> ::getCount() const{

    return getCount(this->root);

}

template<class T>
TreeNode<T>* Tree<T>::find_next(const T& val) {

    TreeNode<T>* a = find_node(this->root, val);
    TreeNode<T>* b;

    if (a == 0) {

        return 0;

    }

    if (a->right != 0) {

        return find_min(a->right);

    }

    b = a->parent;

    while (b != 0 && a == b->right){

        a = b;
        b = b->parent;

    }

    return b;
}

template<class T>
bool Tree<T>:: delete_node(T value) {

    TreeNode<T>* node_to_delete = this->find_node(this->root, value);
    if (node_to_delete == nullptr) {

        return false;

    }
    TreeNode<T>* a;
    TreeNode<T>* b;

    if (node_to_delete->left == 0 || node_to_delete->right == 0) {

        a = node_to_delete;

    }

    else {

        a = find_next(node_to_delete->get_data());

    }

    if (a->left != 0) {

        b = a->left;

    }
    else {

        b = a->right;

    }

    if (b != 0) {

        b->parent = a->parent;

    }

    if (a->parent == 0) {

        this->root = b;

    }

    else {

        if (a == (a->parent)->left) {

            (a->parent)->left = b;

        }
        else {

            (a->parent)->right = b;

        }

    }

    if (a != node_to_delete) {

        node_to_delete->data = a->get_data();

    }

    return true;

}
template <class T>
bool Tree<T>:: isIdenticalKey(Tree<T>& other){

    stack<TreeNode<T>*> temp;
    temp.push(this->root);

    while(!temp.empty()) {

        TreeNode<T>* node = temp.top();
        temp.pop();

        if (other.find_node(other.root, node->get_data())) {

            return true;

        } else if (node->right) {

            temp.push(node->right);

        } else {

            temp.push(node->left);

        }

        return false;

    }

}

template <class T>
int Tree<T>::getHeight(const TreeNode<T>* node) const {

    if (node == nullptr) {

        return 0;

    }

    int left = getHeight(node->left);
    int right = getHeight(node->right);
    return (1 + max(left, right));

}
template <class T>
int Tree<T>::getHeight() {

    return getHeight(this->root);

}

template <class T>
void Tree<T>::iterativeWalk() const {

    if (this->root != nullptr) {

        stack<TreeNode<T>*> temp;

        TreeNode<T>* node = this->root;

        while (node != nullptr || !temp.empty()) {

            while (node != nullptr) {

                temp.push(node);
                node = node->left;

            }

            node = temp.top();
            temp.pop();

            cout << node->get_data() << endl;
            node = node->right;

        }

    }
    
}
template <class T>
bool Tree<T>::isSimilar(const Tree<T>& other) const {

    return (getCount(other.root) == getCount(this->root) && getHeight(other.root) == getHeight(this->root));

}



#endif _BINARY_SEARCH_TREE_H