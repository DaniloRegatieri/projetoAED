#include "Jogador.h"
#include <iostream>

Jogador::Jogador(std::string n) : nome(n) {}

std::string Jogador::getNome() const {
    return nome;
}

size_t Jogador::numeroDeCartas() const {
    return mao.size();
}

const std::vector<Carta>& Jogador::getMao() const {
    return mao;
}

void Jogador::comprarCarta(Baralho &baralhoDeCompra) {
    if (!baralhoDeCompra.estaVazia()) {
        mao.push_back(baralhoDeCompra.removeElemento());
    }
}

Carta Jogador::jogarCarta(int indice) {
    Carta cartaJogada = mao[indice];
    mao.erase(mao.begin() + indice);
    return cartaJogada;
}

void Jogador::verMao() const {
    std::cout << "--- Mao de " << nome << " ---" << std::endl;
    for (size_t i = 0; i < mao.size(); ++i) {
        std::cout << i << ": ";
        mao[i].mostrar();
        std::cout << std::endl;
    }
    std::cout << "--------------------" << std::endl;
}