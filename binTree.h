#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <iostream>

struct node {
    int data;
    int id;
    bool visitado;
    node * left;
    node * right;
};

void insert(node * &root, int data) {
    if (root == nullptr) {
        root = new node;
        root->left = nullptr;
        root->right = nullptr;
        root->data = data;
    }

    else {
        if (data == root->data) return;

        else if (data > root->data) {
            insert(root->right, data);
        }

        else {
            insert(root->left, data);
        }
    }
}

node * search(node * root, int data){
    if(root == nullptr) {
        return nullptr;
    }

    else {
        if(root->data == data)
        {
            return root;
        }

        else if(data > root->data){
            search(root->right, data);
        }

        else{
            search(root->left, data);
        }
    }
}

void pre_ordem(node *ptr) {
    ptr->visitado = true;
    std::cout << ptr->data << std::endl;
    if(ptr->left != nullptr) {
        pre_ordem(ptr->left);
    }

    if(ptr->right != nullptr) {
        pre_ordem(ptr->right);
    }
}


void simetrica(node *ptr) {
    if(ptr->left != nullptr) {
        simetrica(ptr->left);
        ptr->visitado = true;
        std::cout<< ptr->data << "\n";
        simetrica(ptr->right);
    }
}


#endif