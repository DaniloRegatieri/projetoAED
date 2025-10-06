#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>
#include <list>

#include "../Cartas/Carta.h"

using namespace std;

class Jogador{
private:
    string nome;
    int id;
    list<Carta> mao;
public:
    Jogador(const string& nome, int id);
    void comprarCarta(const Carta& carta);
    void descartarCarta(int indiceCarta);
    void mostrarMao() const;
    string getNome() const;
    int getId() const;
    int getNumeroCartas() const;
    void setNome(const string& nome);
    void setId(const int id);
};

#endif