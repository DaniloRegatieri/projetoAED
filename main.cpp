#include <iostream>
#include <vector>
#include <list>
#include <limits> // Para limpar o buffer do cin

// Incluímos apenas o "cérebro" do jogo.
// O Jogo.h já inclui as outras classes que ele precisa.
#include "Game.h"

// Função auxiliar para limpar a tela de forma simples (funciona em Linux/Mac)
void limparTela() {
    // A sequência \033[2J limpa a tela e \033[H move o cursor para o topo.
    std::cout << "\033[2J\033[H";
}

int main() {
    try {
        limparTela();
        std::cout << "===============================" << std::endl;
        std::cout << "      BEM-VINDO AO JOGO!       " << std::endl;
        std::cout << "===============================" << std::endl;

        // --- PASSO 1: CONFIGURAR A PARTIDA ---
        int numJogadores = 0;
        while (numJogadores < 2 || numJogadores > 4) {
            std::cout << "\nQuantos jogadores (2 a 4)? ";
            std::cin >> numJogadores;

            if (std::cin.fail() || numJogadores < 2 || numJogadores > 4) {
                std::cout << "Numero invalido. Por favor, digite um numero entre 2 e 4." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                numJogadores = 0;
            }
        }

        std::list<Jogador> jogadores;
        for (int i = 0; i < numJogadores; ++i) {
            std::string nome;
            std::cout << "Digite o nome do jogador " << i + 1 << ": ";
            std::cin >> nome;
            jogadores.emplace_back(nome, i);
        }

        // --- PASSO 2: CRIAR O OBJETO JOGO ---
        std::cout << "\nCriando a partida com " << numJogadores << " jogadores..." << std::endl;
        Game partida(jogadores);


       
        
        partida.iniciarPartida();

    } catch (const std::exception& e) {
        // --- PASSO 4: TRATAR ERROS ---
        std::cerr << "\n!! Ocorreu um erro inesperado que encerrou o jogo !!" << std::endl;
        std::cerr << "Detalhe do erro: " << e.what() << std::endl;
        return 1; // Retorna 1 para indicar que o programa terminou com erro
    }

    std::cout << "\nObrigado por jogar!" << std::endl;
    return 0; // Sucesso
}