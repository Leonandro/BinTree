#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <iostream>
#include <queue>
#include <string>
#include <fstream>

int position_counter = 0, aux, element_counter = 0, level_counter = 1, nodes_count = 0;
bool position_counter_check = false, element_counter_check = false;

struct node {
    int data;
    int level;
    bool visitado;
    node * left;
    node * right;
};

// O argumeto number_nodes representa a quantidade de nó que tem na árvore
bool isComplete (node* root, unsigned int number_nodes, unsigned int index = 0) { 
    if (root == nullptr) 
        return true; 
    if (index >= number_nodes) 
        return false; 
    return isComplete(root->left, 2*index + 1, number_nodes) && 
           isComplete(root->right, 2*index + 2, number_nodes); 
} 
node * aux_node;

void insert(node * &root, int data) {
    if (root == nullptr) {
        root = new node;
        root->left = nullptr;
        root->right = nullptr;
        root->data = data;
        root->level = level_counter;
        level_counter = 1;
        nodes_count++;
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

node * minimo(node * root)
{
	while(root->left != nullptr) root = root->left;
	return root;
}

node * remove(node * root, int data) {
    if(root == nullptr) {
        return nullptr;
    }

    else if(data < root->data){
        root->left = remove(root->left, data);
    }

    else if(data > root->data){
        root->right = remove(root->right, data);
    }

    else {
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
            return root;
        }

        else if(root->left == nullptr){
            node * aux = root;
            root = root->right;
            delete aux;
            return root;
        }

        else if(root->right == nullptr){
            node * aux = root;
            root = root->left;
            delete aux;
            return root;
        }

        else {
            node * aux = minimo(root->right);
			root->data = aux->data;
			root->right = remove(root->right, aux->data);
        }
    }

    return root;

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

    if(position_counter_check)
    {   
        return aux;
    }
}

bool ehCheia(node * root) {
	if (root == nullptr){
        return false;
    }

	if (root->left != nullptr && root->right != nullptr){
		return true;
    }

	if (root->left != nullptr){
		if (ehCheia(root->left)){
			return true;
        }
		else{
			return false;
        }
	}
	else{
		if (ehCheia(root->right)){
			return true;
        }
		else {
			return false;
        }
	}
}

node * enesimoElemento(node * ptr, int data){

    if (ptr == nullptr){ 
        return nullptr; 
    }
  
    if (element_counter <= data) { 
        enesimoElemento(ptr->left, data); 
        
        element_counter++; 
        if (element_counter == data){
            aux_node =  ptr;
            element_counter_check = true;
        }
  
        enesimoElemento(ptr->right, data); 
    } 

    if(element_counter_check)return aux_node;
}

node * mediana(node * root){
    return enesimoElemento(root, (nodes_count/2));
}

bool estBin (node * ptr) {
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


std::string toString(node * root) {
    if(root == nullptr) {
        return "Empty";
    }
    std::string traversal = "";
    std::queue<node*> hue;
    hue.push(root);
    while(!hue.empty()){
        node * aux = hue.front();
        traversal += std::to_string(aux->data) + "  ";
        if(aux->left != nullptr) hue.push(aux->left);
        if(aux->right != nullptr) hue.push(aux->right);
        hue.pop();
    }
    return traversal;  
}

void refresh_counters(){
    position_counter = 0;
    element_counter = 0;
    position_counter_check = false;
    element_counter_check = false;
    aux_node = nullptr;
}


void gerencia(node * tree, std::string command, int number){
    refresh_counters();

    if(number == 0)std::cout << "[" << command << "]"<< std::endl;
    else std::cout << "[" << command << " " << number << "]"<< std::endl;

    if(command == "POSICAO"){
        auto result = posicao(tree, number);
        if(result > 0)std::cout << "A Posição do nó " << number << " em percusso simétrico eh: " << result << std::endl;
        else std::cout << "O nó " << number << " Não está na árvore\n";
    }

    else if(command == "ENESIMO"){
        auto result = enesimoElemento(tree, number);
        std::cout << "O " << number << "º " << " em percursso simétrico eh: " << result->data << std::endl;
    }
    
    else if(command == "CHEIA"){
        if(ehCheia(tree)) std::cout << "TRUE\n";
        else std::cout << "FALSE\n";
    }

    else if(command == "IMPRIMA"){
        std::cout << toString(tree) << std::endl;
    }


    else if(command == "INSIRA"){
        insert(tree, number);
    }

    else if(command == "REMOVA"){
        remove(tree, number);
    }

    else if(command == "MEDIANA"){
        std::cout << "O nó na posição mediana (" << (nodes_count/2) << ") em percusso simétrico eh: " << mediana(tree)->data << std::endl;
    }

	else if (command == "COMPLETA"){
		std::cout << "A ávore " << (isComplete(tree, nodes_count) ? " é" : "não é") << " completa" << std::endl;
	}
    else {
        std::cout << "Comando não reconhecido\n";
    }
}

#endif
