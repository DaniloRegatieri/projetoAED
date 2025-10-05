#ifndef BARALHO_H
#define BARALHO_H

#include <iostream>
#include <string>
#include <algorithm>  // Para usar swap
#include <random>     // Para random_device, mt19937 e uniform_int_distribution

using namespace std;

struct No{
    //dados contidos no nó
    int numCarta;
    string corCarta;
    No* ptrProximo; //ponteiro que aponta para o proximo nó
};

class Baralho{
private:
    No* ptrTopo;
    string cartaTopo[2];
    string matrizCartas[2][44];

public:
    Baralho();

    /*
    métodos
    */

    //método que verifica se a fila esta vazia
    bool estaVazia();

    //método que adiciona um elemento ao ptrTopo da fila
    void adicionaElemento(int snumCarta, string scorCarta);

    //método para remover um item do ptrTopo da fila
    void removeElemento();

    //método para mostrar cor do topo
    int numTopo();

    //método para mostrar cor do topo
    string corTopo();

 
    //método para mostrar elemento do topo
    void elementoTopo();

    void criarBaralho();

    //método para varrer a pilha
    void varrerPilha();

    void embaralha();

    //método para imprimir a matriz embaralhada:
    void imprimeMatriz();

};


#endif