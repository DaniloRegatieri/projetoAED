#ifndef BARALHO_H
#define BARALHO_H

#include "../Cartas/Carta.h"
#include <vector>

// Estrutura do nó que armazena a carta
struct No {
    Carta carta;
    No* ptrProximo;
};

class Baralho {
private:
    No* ptrTopo;

public:
    Baralho();
    ~Baralho(); 

    void adicionaElemento(Carta c);
    Carta removeElemento();
    Carta elementoTopo();
    bool estaVazia();
    
    void criarBaralhoPadrao();
    void embaralhar();
};

#endif //BARALHO_H