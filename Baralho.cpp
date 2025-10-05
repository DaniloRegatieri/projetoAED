#include <iostream>
#include <string>
#include <algorithm>  // Para usar swap
#include <random>     // Para random_device, mt19937 e uniform_int_distribution

#include "Baralho.h"

using namespace std;

//construtor

Baralho::Baralho(){
    ptrTopo = nullptr;
}

/*
métodos
*/

//método que verifica se a fila esta vazia
bool Baralho::estaVazia(){
    if (ptrTopo == nullptr){
        return true;
    }        else{
        return false;
    }
}

//método que adiciona um elemento ao ptrTopo da fila
void Baralho::adicionaElemento(int snumCarta, string scorCarta){
    Node* novo = new Node();
    novo->numCarta = snumCarta;
    novo->corCarta = scorCarta;
    novo->ptrProximo = ptrTopo;
    ptrTopo = novo;
}

//método para remover um item do ptrTopo da fila
void Baralho::removeElemento(int& snumCarta, string& scorCarta){
    if (!estaVazia()){
        snumCarta = ptrTopo->numCarta;
        scorCarta = ptrTopo->corCarta;
        Node* aux = ptrTopo;
        ptrTopo = ptrTopo->ptrProximo;
        delete aux;
    } else{
        cout << "Baralho esta vazio." << endl;
    }

}

//método para mostrar cor do topo
int Baralho::numTopo(){
    if (!estaVazia()){
        return ptrTopo->numCarta;
    }else{
        cout << " A pilha vazia ";
        return -1;
    }
}

//método para mostrar cor do topo
string Baralho::corTopo(){
    if (!estaVazia()){
        return ptrTopo->corCarta;
    }else{
        cout << " A pilha vazia ";
        return "-1";
    }
}

 
//método para mostrar elemento do topo
void Baralho::elementoTopo(){
    cartaTopo[0] = numTopo();
    cartaTopo[1] = corTopo();

    cout << "Carta do topo: " << cartaTopo[0] << cartaTopo[1] << endl;
}

void Baralho::criarBaralho(){
    string corLocal[4] = {"verde", "vermelho", "azul", "amarelo"};
    int index = 0; 
    for(int l = 0; l<4; l++){
        for(int i = 0; i<11; i++){
            adicionaElemento(i, corLocal[l]);
            matrizCartas[0][index] = to_string(i);  // números como string para simplicidade
            matrizCartas[1][index] = corLocal[l];
            index++;
        }
    }   
}

//método para varrer a pilha
void Baralho::varrerPilha(){
    Node* aux = ptrTopo;

    if(aux == nullptr){
        cout << "Pilha vazia." << endl;
        return;
    } 

    while (aux!=nullptr){
        cout << aux->numCarta << " " << aux->corCarta << "\n -> \n" ;
        aux = aux->ptrProximo;
    }

    cout << "null" << endl;
}

void Baralho::embaralha(){
    // Embaralhar as colunas
    random_device rd;
    mt19937 g(rd());

    for(int i = 43; i > 0; i--){ // algoritmo Fisher-Yates
        uniform_int_distribution<int> dist(0, i);
        int j = dist(g);

        // Trocar coluna i com coluna j
        swap(matrizCartas[0][i], matrizCartas[0][j]);
        swap(matrizCartas[1][i], matrizCartas[1][j]);
    }
}

//método para imprimir a matriz embaralhada:
void Baralho::imprimeMatriz(){
    for(int i=0;i<44;i++){
        cout << matrizCartas[0][i] << " - " << matrizCartas[1][i] << endl;
    }
}

//método para remover um item do ptrTopo da fila
void Baralho::esvaziaPilha() {
    while (!estaVazia()) {
        int numX = ptrTopo->numCarta;
        string corX = ptrTopo->corCarta;

        Node* aux = ptrTopo;
        ptrTopo = ptrTopo->ptrProximo;

        delete aux;

        cout << "Carta " << numX << " " << corX << " deletada com sucesso." << endl;
    }
    cout << "Pilha esvaziada completamente." << endl;
}


void Baralho::converteMatriz(Baralho& b){
    for(int i = 0; i < 44; i++){
        adicionaElemento(stoi(b.matrizCartas[0][i]), b.matrizCartas[1][i]);
    }

    cout << "\n\nPilha embaralhada:\n" << endl;

    varrerPilha();
}