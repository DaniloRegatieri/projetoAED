#ifndef GAME_H
#define GAME_H

#include "Baralho.h"
#include "Jogador.h"

class Game{
    private:
        Baralho monteDeCompra;
        Baralho monteDeDescarte;
        list<Jogador> jogadores;
        int jogadorAtual;
        bool sentidoJogo; // true para sentido horario, false para anti-horario
        string corAtualDoJogo;

    public:
        Game(const list<Jogador>& nomesJogadores);
        void iniciarPartida();
    private:
        // --- Métodos que REPRESENTAM AS REGRAS ---
        bool jogadaValida(const Carta& cartaJogada);
        void aplicarEfeitoCarta(const Carta& cartaJogada);
        bool verificarVencedor()const;

        void distribuirCartasIniciais();
        void prepararMesa();
        void proximoJogador();
        void executarTurno();
        int getIndiceProximoJogador()const;
};
            

#endif