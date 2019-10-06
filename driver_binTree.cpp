#include "binTree.h"

int main () {

    node * raiz = nullptr;
    int s;

    insert(raiz, 30);
    insert(raiz, 15);
    insert(raiz, 80);
    insert(raiz, 10);
    insert(raiz, 25);
    insert(raiz, 40);
    insert(raiz, 85);
    insert(raiz, 20);
    insert(raiz, 35);
    insert(raiz, 50);
    insert(raiz, 90);
    insert(raiz, 45);
    insert(raiz, 70);
    insert(raiz, 60);
    insert(raiz, 75);
    insert(raiz, 55);
    insert(raiz, 65);


    //std::cout << toString(raiz) << std::endl;
    simetrica(raiz);

    std::cin >> s;

    auto result = enesimoElemento(raiz, s);
    //std::cout << std::endl;


    std::cout << "\nElemento achado: " << result->data << "\n";

    std::cin >> s;

    auto craco = enesimoElemento(raiz, s);
    //std::cout << std::endl;


    std::cout << "\nElemento achado: " << craco->data << "\n";
    //bool result = ehCheia(raiz);

    //std::cout << "posicao: " << result << std::endl;
    //if(search(raiz, 20) != nullptr) std::cout << "achei o 15\n";
    //else std::cout << "deu bug\n";

    return 0;    
}