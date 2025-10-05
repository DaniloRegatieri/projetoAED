#include "Carta.h"

// Implementação do Construtor
Carta::Carta(const string& num, const string& c) : numero(num), cor(c) {
    // O corpo pode ser vazio, pois a lista de inicialização já fez o trabalho
}

// Implementação dos Getters
string Carta::getNumero() const {
    return this->numero;
}

string Carta::getCor() const {
    return this->cor;
}

// Implementação do método para mostrar
void Carta::mostrar() const {
    cout << "Carta: " << this->numero << " " << this->cor;
}