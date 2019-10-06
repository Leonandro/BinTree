#include "../include/binTree.h"
#include <sstream>

int main () {

    node * raiz = nullptr;
    std::string path;
    int actual_node_data = 0;
    std::fstream file_;

    std::cout << "Digite o endereço do arquivo contendo os nós: ";
    std::cin >> path;

    file_.open(path);

    if(file_.is_open()){
        while(file_ >> actual_node_data){
            insert(raiz, actual_node_data);
        }
    }

    else {
        std::cout << "Falha na abertura do arquivo desejado.. encerrando o programa\n";
        return 1;
    }

    file_.close();
    path.clear();

    std::cout << "Digite o endereço do arquivo contendo os comandos: ";
    std::cin >> path;
    std::string multi;
    int number = 0;
    std::string command;

    file_.open(path);
    if(file_.is_open()){
        while(std::getline(file_, multi)){
            if(multi.find(" ") != std::string::npos) {
                std::string command = multi.substr(0, multi.find_first_of(" "));
                std::string to_number = multi.substr(multi.find_first_of(" "), multi.length());
                number = std::stoi(to_number);
                gerencia(raiz, command, number);
                std::cout << std::endl;
            }

            else {
                std::stringstream aux(multi);
                aux >> command;
                gerencia(raiz, command, 0);
                std::cout << std::endl;
            }
        }
    }

    else {
        std::cout << "Falha na abertura do arquivo desejado.. encerrando o programa\n";
        return 1;
    }



    return 0;    
}