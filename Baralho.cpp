#include <iostream>
#include <string>
#include <algorithm>  // Para usar swap
#include <random>     // Para random_device, mt19937 e uniform_int_distribution

#include "Baralho.h"
#include "Carta.h"

using namespace std;

//construtor

Baralho::Baralho(){
    ptrTopo = nullptr;
}

//destrutor 

Baralho::~Baralho(){
    if (estaVazia()) {
        cout << "O baralho esta vazio." << endl;
        return;
    }
    else{
        while (!estaVazia()) {
            Carta cartaRemovida = ptrTopo->carta;
            Node* aux = ptrTopo;
            ptrTopo = ptrTopo->ptrProximo;

            delete aux;
        }
    }
}

/*
métodos
*/

void Baralho::criarBaralho(){
    string cores[] = {"verde", "vermelho", "azul", "amarelo"};
    string especial[] = {"bloqueio", "+2", "inverter"};
    for (const string& cor : cores) {
        for (int i = 0; i < 10; i++) {
            // Cria um objeto Carta
            Carta novaCarta(to_string(i), cor);
            // Adiciona à pilha usando a sua lógica
            adicionaElemento(novaCarta);
            if(i != 0){
                adicionaElemento(novaCarta);
            }
        }
        for(const string& esp : especial) {
            Carta novaCartaEspecial(esp, cor);
            adicionaElemento(novaCartaEspecial);
            adicionaElemento(novaCartaEspecial);
        }
    }
    for (int i = 0; i < 4; ++i) {
        Carta novaCartaCoringa1("+4", "preto");
        adicionaElemento(novaCartaCoringa1);
        Carta novaCartaCoringa2("escolha_cor", "preto");
        adicionaElemento(novaCartaCoringa2);
    }
}

//método que verifica se a fila esta vazia
bool Baralho::estaVazia(){
    if (ptrTopo == nullptr){
        return true;
    }        else{
        return false;
    }
}

//método que adiciona um elemento ao ptrTopo da fila
void Baralho::adicionaElemento(const Carta& novaCarta) {
    Node* novo = new Node(novaCarta); // Cria um novo nó já com a carta
    novo->ptrProximo = ptrTopo;
    ptrTopo = novo;
}

//método para remover um item do ptrTopo da fila
void Baralho::removeElemento(){
    if (!estaVazia()){
        Node* aux = ptrTopo;
        ptrTopo = ptrTopo->ptrProximo;
        delete aux;
    } else{
        cout << "\n\n------Baralho esta vazio------\n\n" << endl;
    }

}

//método para mostrar cor do topo
string Baralho::numTopo(){
    if (!estaVazia()){
        return ptrTopo->carta.getNumero();
    }else{
        cout << "\n\n------A Pilha Esta Vazia------\n\n";
        return "-1";
    }
}

//método para mostrar cor do topo
string Baralho::corTopo(){
    if (!estaVazia()){
        return ptrTopo->carta.getCor();
    }else{
        cout << "\n\n------A Pilha Esta Vazia------\n\n";
        return "-1";
    }
}

 
//método para mostrar elemento do topo
Carta Baralho::elementoTopo(){
    if (estaVazia()) {
        cout << "Erro: Tentando acessar o topo de um baralho vazio!" << endl;
        throw runtime_error("Baralho vazio em elementoTopo()");
    }
    return ptrTopo->carta;
}

//método para varrer a pilha
void Baralho::varrerPilha(){
    Node* aux = ptrTopo;
    if (aux == nullptr) {
        cout << "O baralho esta vazio." << endl;
        return;
    }
    cout << "\n\n------Varrendo Cartas------ \n\n";
    while (aux != nullptr) {
        cout << aux->carta.mostrar() << endl;
        aux = aux->ptrProximo;
    }
    cout << "\n\n------Varredura Finalizada ------\n\n";
}

void Baralho::embaralhar() {
    // Não faz nada se a pilha estiver vazia ou tiver apenas um elemento
    if (ptrTopo == nullptr || ptrTopo->ptrProximo == nullptr) {
        return;
    }

    // 1. Copiar os ponteiros (endereços) dos nós para um vetor
    std::vector<Node*> nos;
    Node* atual = ptrTopo;
    while (atual != nullptr) {
        nos.push_back(atual);
        atual = atual->ptrProximo;
    }

    // 2. Embaralhar o vetor de ponteiros
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(nos.begin(), nos.end(), g);

    // 3. Religar os nós na nova ordem
    ptrTopo = nos[0]; // O novo topo é o primeiro ponteiro do vetor embaralhado
    for (size_t i = 0; i < nos.size() - 1; ++i) {
        nos[i]->ptrProximo = nos[i+1]; // O nó atual aponta para o próximo da lista embaralhada
    }
    // O último nó da nova lista deve apontar para nullptr
    nos.back()->ptrProximo = nullptr; 
}

//método para remover todos do ptrTopo da fila
void Baralho::esvaziaPilha() {
     if (estaVazia()) {
        cout << "O baralho esta vazio." << endl;
        return;
    }
    else{
        if(!estaVazia()){cout << "\n\n------Removendo Todas as Cartas------\n\n ";}
        while (!estaVazia()) {
            Carta cartaRemovida = ptrTopo->carta;
            Node* aux = ptrTopo;
            ptrTopo = ptrTopo->ptrProximo;

            delete aux;

            cout << "Carta " << cartaRemovida.getNumero() << " " << cartaRemovida.getCor() << " deletada com sucesso." << endl;
        }
        cout << "\n\n------Pilha Esvaziada Completamente------\n\n" << endl;
    }
}
