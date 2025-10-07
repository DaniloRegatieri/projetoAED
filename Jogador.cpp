#include <iostream>
#include <string>
#include <algorithm> // Para usar swap
#include <random>    // Para random_device, mt19937 e uniform_int_distribution

#include "Jogador.h"
#include "Baralho.h"

using namespace std;

// construtor

Jogador::Jogador(const string &nome, const int id) : nome(nome), id(id)
{
    cout << "Jogador " << this->nome << " criado!" << endl;
}

string Jogador::getNome() const
{
    return this->nome;
}

int Jogador::getId() const
{
    return this->id;
}

void Jogador::setNome(const string &novoNome)
{
    this->nome = novoNome;
}

void Jogador::setId(const int novoId)
{
    this->id = novoId;
}

void Jogador::comprarCarta(const Carta &carta)
{
    this->mao.push_back(carta);
}

void Jogador::descartarCarta(int indiceCarta)
{
    if (this->mao.empty())
    {
        cout << "Erro: Nao ha cartas na mao para descartar!" << endl;
        return;
    }
    else
    {
        if (indiceCarta >= 0 && indiceCarta < this->mao.size())
        {
            // 2. Obter um iterador para o início da lista
            auto it = this->mao.begin();

            // 3. Avançar o iterador até a posição desejada
            std::advance(it, indiceCarta);

            // 4. Apagar o elemento para o qual o iterador aponta
            this->mao.erase(it);
        }
        else
        {
            cout << "Erro: Indice de carta invalido!" << endl;
        }
    }
}

void Jogador::mostrarMao() const
{
    cout << "--- Mao de " << this->nome << " ---" << endl;
    if (this->mao.empty())
    {
        cout << "A mao esta vazia." << endl;
    }
    else
    {
        int indice = 0;
        // Percorremos a lista com um for-each loop, que é a forma mais fácil
        for (const Carta &carta : this->mao)
        {
            cout << indice << ": " << carta.mostrar() << endl;
            indice++;
        }
    }
    cout << "----------------------" << endl;
}

int Jogador::getNumeroCartas() const
{
    return this->mao.size();
}

bool Jogador::temJogadaValida(const Carta& cartaMesa, const std::string& corAtual) const {
    for (const auto& cartaNaMao : mao) {
        if (cartaNaMao.getCor() == corAtual || cartaNaMao.getNumero() == cartaMesa.getNumero() || cartaNaMao.getNumero() == "+4" || cartaNaMao.getNumero() == "escolha_cor") {
            return true;
        }
    }
    return false;
}

Carta Jogador::verCarta(int indice) const {
    if (indice < 0 || indice >= mao.size()) {
        throw std::out_of_range("Indice da carta invalido.");
    }
    auto it = mao.begin();
    std::advance(it, indice);
    return *it; // Retorna a carta na posição especificada
}