#include "binTree.h"

int main () {

    node * raiz = nullptr;

    insert(raiz, 30);
    insert(raiz, 15);
    insert(raiz, 50);
    insert(raiz, 20);

    pre_ordem(raiz);

    //if(search(raiz, 20) != nullptr) std::cout << "achei o 15\n";
    //else std::cout << "deu bug\n";

    return 0;    
}