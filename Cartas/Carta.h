#ifndef CARTA_H
#define CARTA_H

#include <string>

// A "planta" da classe Carta. Declara o que ela tem e o que ela faz.
class Carta {
private:
    std::string valor;
    std::string cor;

public:
    // Construtor
    Carta(std::string v, std::string c);

    // Funções (métodos)
    std::string getValor() const;
    std::string getCor() const;
    void mostrar() const;
};

#endif //CARTA_H