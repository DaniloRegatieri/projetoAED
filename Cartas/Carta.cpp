#include "Carta.h"
#include <iostream>

// A implementação (o "como fazer") das funções declaradas no .h
Carta::Carta(std::string v, std::string c) : valor(v), cor(c) {}

std::string Carta::getValor() const {
    return this->valor;
}

std::string Carta::getCor() const {
    return this->cor;
}

void Carta::mostrar() const {
    std::cout << this->valor << " " << this->cor;
}