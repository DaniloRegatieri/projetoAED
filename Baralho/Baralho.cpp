#include "Baralho.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

Baralho::Baralho() : ptrTopo(nullptr) {}

Baralho::~Baralho() {
    while (!estaVazia()) {
        No* aux = ptrTopo;
        ptrTopo = ptrTopo->ptrProximo;
        delete aux;
    }
}

void Baralho::adicionaElemento(Carta c) {
    No* novoNo = new No{{c.getValor(), c.getCor()}, ptrTopo};
    ptrTopo = novoNo;
}

Carta Baralho::removeElemento() {
    if (estaVazia()) {
        std::cerr << "AVISO: Tentativa de remover carta de um baralho vazio." << std::endl;
        return Carta("INVALIDA", "INVALIDA");
    }
    No* aux = ptrTopo;
    Carta cartaRemovida = aux->carta;
    ptrTopo = ptrTopo->ptrProximo;
    delete aux;
    return cartaRemovida;
}

Carta Baralho::elementoTopo() {
    if (estaVazia()) {
        return Carta("INVALIDA", "INVALIDA");
    }
    return ptrTopo->carta;
}

bool Baralho::estaVazia() {
    return ptrTopo == nullptr;
}

void Baralho::criarBaralhoPadrao() {
    const std::string cores[] = {"Vermelho", "Verde", "Azul", "Amarelo"};
    const std::string valoresNumericos[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    const std::string valoresAcao[] = {"+2", "Inverter", "Bloqueio"};

    for (const auto& cor : cores) {
        adicionaElemento(Carta("0", cor));
        for (int i = 0; i < 2; ++i) {
            for (const auto& valor : valoresNumericos) {
                adicionaElemento(Carta(valor, cor));
            }
            for (const auto& valor : valoresAcao) {
                adicionaElemento(Carta(valor, cor));
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        adicionaElemento(Carta("Coringa", "Preto"));
        adicionaElemento(Carta("Coringa+4", "Preto"));
    }
}

void Baralho::embaralhar() {
    if (estaVazia()) return;
    std::vector<Carta> todasAsCartas;
    while (!estaVazia()) {
        todasAsCartas.push_back(removeElemento());
    }
    unsigned seed = time(0);
    std::shuffle(todasAsCartas.begin(), todasAsCartas.end(), std::default_random_engine(seed));
    for (const auto& carta : todasAsCartas) {
        adicionaElemento(carta);
    }
}