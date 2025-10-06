#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <vector>
#include "../Cartas/Carta.h"
#include "../Baralho/Baralho.h"

class Jogador {
private:
    std::string nome;
    std::vector<Carta> mao;

public:
    Jogador(std::string n);

    void comprarCarta(Baralho &baralhoDeCompra);
    Carta jogarCarta(int indice);
    void verMao() const;
    
    std::string getNome() const;
    size_t numeroDeCartas() const;
    const std::vector<Carta>& getMao() const;
};

#endif //JOGADOR_H