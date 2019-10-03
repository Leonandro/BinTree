#include "binTree.h"

int main () {

    node * raiz = new node;

    insert(raiz, 30);
    insert(raiz, 15);
    insert(raiz, 50);
    insert(raiz, 20);

    simetrica(raiz);

    return 0;    
}