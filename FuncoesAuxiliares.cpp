#include "Baralho/Baralho.h"
#include "Cartas/Carta.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ----------------------------------------------------
// Verifica se uma carta pode ser jogada
// ----------------------------------------------------
bool podeJogar(const Carta& cartaJogada, const Carta& cartaNoTopo, const string& corAtual) {
    // Uma carta pode ser jogada se:
    // 1. Tiver a mesma cor da carta no topo
    // 2. Tiver o mesmo número/valor
    // 3. For uma carta "Preta" (Coringa ou +4)
    return (
        cartaJogada.getCor() == corAtual ||
        cartaJogada.getValor() == cartaNoTopo.getValor() ||
        cartaJogada.getCor() == "Preto"
    );
}

// ----------------------------------------------------
// Reaproveita a pilha de descarte como baralho de compra
// ----------------------------------------------------
void reciclarPilhaDeDescarte(Baralho& baralhoDeCompra, Baralho& pilhaDeDescarte) {
    cout << "\n[INFO] Reciclando pilha de descarte..." << endl;

    // Guarda a carta do topo (a última jogada) — ela continua na mesa
    Carta cartaTopo = pilhaDeDescarte.removeElemento();

    // Move todas as demais cartas da pilha de descarte de volta para o baralho de compra
    while (!pilhaDeDescarte.estaVazia()) {
        baralhoDeCompra.adicionaElemento(pilhaDeDescarte.removeElemento());
    }

    // Embaralha novamente o baralho
    baralhoDeCompra.embaralhar();

    // Recoloca a carta do topo na pilha de descarte
    pilhaDeDescarte.adicionaElemento(cartaTopo);

    cout << "[INFO] Baralho reciclado e embaralhado com sucesso!\n" << endl;
}
