#ifndef BARALHO_H
#define BARALHO_H

#include <iostream>
#include <string>
#include <algorithm>  // Para usar swap
#include <random>     // Para random_device, mt19937 e uniform_int_distribution
#include "Carta.h"

using namespace std;

struct Node{
    Carta carta; // Objeto Carta que contém os dados da carta
    Node* ptrProximo; //ponteiro que aponta para o proximo nó

    Node(const Carta& c) : carta(c), ptrProximo(nullptr) {}
};

class Baralho{
private:
    Node* ptrTopo;
public:
    Baralho();
    
    ~Baralho();
    /*
    métodos
    */

    //método que verifica se a fila esta vazia
    bool estaVazia();

    //método que adiciona um elemento ao ptrTopo da fila
    void adicionaElemento(const Carta& novaCarta);

    //método para remover um item do ptrTopo da fila
    void removeElemento();

    //método para mostrar cor do topo
    int numTopo();

    //método para mostrar cor do topo
    string corTopo();
 
    //método para mostrar elemento do topo
    string elementoTopo();

    //método para criar o baralho
    void criarBaralho();

    //método para varrer a pilha
    void varrerPilha();

    //método para embaralhar a matriz
    void embaralhar();

    //método para esvaziar pilha
    void esvaziaPilha();

};

#endif