/* inicio do código do projeto de AED*/
#include <iostream>
#include <string>
#include <algorithm>  // Para usar swap
#include <random>     // Para random_device, mt19937 e uniform_int_distribution

#include "Baralho.h"

using namespace std;

int main() {
    // 1. Cria um baralho (que começa vazio)
    Baralho meuBaralho;

    if(meuBaralho.estaVazia()){
        cout << "O baralho esta vazio." << endl;
    } else{
        cout << "O baralho nao esta vazio." << endl;
    }
    // 2. Preenche o baralho com as cartas padrão
    meuBaralho.criarBaralho();
    
    cout<<"Baralho criado\n";

    cout << "--- BARALHO ORDENADO (EM ORDEM DE INSERCAO) ---" << endl;
    meuBaralho.varrerPilha();

    return 0; // O destrutor do ~Baralho() será chamado automaticamente aqui
}