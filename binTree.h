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

//TODO: solucionar o pq estar aparecendo o 0 antes dos nós, propriamente ditos.
void simetrica(node *ptr) {
    if(pNo != nullptr) {
        simetrica(ptr->left);
        ptr->visitado = true;
        std::cout<< ptr->data << "\n";
        simetrica(ptr->right);
    }
}


#endif