#ifndef CARTA_H
#define CARTA_H

#include <string>
#include <iostream>

using namespace std;

class Carta {
private:
    int numero;
    string cor;

public:
    // Construtor: cria uma nova carta com um número e uma cor
    Carta(int num, const string& c);

    // Métodos para obter os valores da carta (Getters)
    int getNumero() const;
    string getCor() const;

    // Método para mostrar a carta no console
    void mostrar() const;
};

#endif