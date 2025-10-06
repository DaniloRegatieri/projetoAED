/* inicio do código do projeto de AED*/
#include <iostream>
#include <string>
#include <algorithm>  // Para usar swap
#include <random>     // Para random_device, mt19937 e uniform_int_distribution

#include "Baralho/Baralho.h" // temos "Baralho/Baralho.h", porque o arquivo Baralho.h está na pasta Baralho
#include "Cartas/Carta.h"
#include "Jogador/Jogador.h" // temos "Jogador/Jogador.h", porque o arquivo Jogador.h está na pasta Jogador
/*
-----------------------------------------------------
Provavelmente vai ter que fazer o mesmo com o jogador
-----------------------------------------------------
*/

using namespace std;

int main() {
    // 1. Cria um baralho (que começa vazio)
    Baralho meuBaralho;
    Jogador jogador1("Heitor", 1);

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

    meuBaralho.adicionaElemento(Carta("5", "Vermelho"));
    meuBaralho.adicionaElemento(Carta("5", "Vermelho"));

    meuBaralho.removeElemento();

    std::cout << "Numero Topo: " << meuBaralho.numTopo() << std::endl;
    std::cout << "Cor Topo: " << meuBaralho.corTopo() << std::endl;
    std::cout << "Carta Topo: " << meuBaralho.elementoTopo() << std::endl;

    // 3. Embaralha as cartas
    cout << "\n... Embaralhando as cartas ...\n" << endl;
    meuBaralho.embaralhar();

    cout << "--- BARALHO EMBARALHADO ---" << endl;
    meuBaralho.varrerPilha();

    jogador1.comprarCarta(Carta("3", "Azul"));
    jogador1.comprarCarta(Carta("7", "Verde"));
    cout << jogador1.getNumeroCartas() << endl;
    jogador1.mostrarMao();
    jogador1.descartarCarta(0);
    jogador1.mostrarMao();

    return 0; // O destrutor do ~Baralho() será chamado automaticamente aqui
}