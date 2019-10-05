#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <iostream>

int position_counter = 0, aux, element_counter = 0, level_counter = 1;
bool position_counter_check = false, element_counter_check = false; 

struct node {
    int data;
    int level;
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
        root->level = level_counter;
        level_counter = 1;
    }

    else {
        if (data == root->data) return;

        else if (data > root->data) {
            level_counter++;
            insert(root->right, data);
        }

        else {
            level_counter++;
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
    }

    ptr->visitado = true;
    std::cout<< ptr->data <<  " - (level)" << ptr->level << "\n";

    if(ptr->right != nullptr){
        simetrica(ptr->right);
    }
}

int posicao(node *ptr, int data) {
    if(ptr->left != nullptr) {
        posicao(ptr->left, data);
    }

    position_counter++;
    if(ptr->data == data) {
        aux = position_counter;
        position_counter = 0;
        position_counter_check = true;
    }

    if(ptr->right != nullptr){
        posicao(ptr->right, data);
    }

    if(position_counter_check) return aux;
}

bool ehCheia (node * ptr) {
    if(ptr != nullptr) {
        if(( (ptr->left == nullptr) && (ptr->right != nullptr) ) || (ptr->right == nullptr) && (ptr->left != nullptr)) {
            return false;
        }

        if(ptr->left != nullptr){
            return (ehCheia(ptr->left) && ehCheia(ptr->right));
        }
        else{
            return true;
        }
    }

    else {
        return false;
    }
}

bool ehNada (node * ptr) {
    if(ptr != nullptr) {
        if(( (ptr->left == nullptr) && (ptr->right != nullptr) ) || (ptr->right == nullptr) && (ptr->left != nullptr)) {
            return false;
        }

        if(ptr->left != nullptr){
            return (ehCheia(ptr->left) && ehCheia(ptr->right));
        }
        else{
            return true;
        }
    }

    else {
        return false;
    }
}


#endif