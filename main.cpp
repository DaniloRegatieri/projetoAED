#include <iostream>
#include <vector>
#include <string>
#include <limits>  // para numeric_limits
#include "Baralho/Baralho.h"
#include "Jogador/Jogador.h"
#include "Cartas/Carta.h"

// Se você tiver funções auxiliares em outro arquivo, inclua também:
// #include "FuncoesAuxiliares.h"

using namespace std;

// Se a função `podeJogar` e `reciclarPilhaDeDescarte` estiverem em outro arquivo,
// lembre-se de declarar seus protótipos:
bool podeJogar(const Carta& cartaJogada, const Carta& cartaNoTopo, const string& corAtual);
void reciclarPilhaDeDescarte(Baralho& baralhoDeCompra, Baralho& pilhaDeDescarte);

// =======================
// Função principal do jogo
// =======================
int main() {
    // 1. Configuração do Jogo
    Baralho baralhoDeCompra;
    baralhoDeCompra.criarBaralhoPadrao();
    baralhoDeCompra.embaralhar();

    Baralho pilhaDeDescarte;

    vector<Jogador> jogadores;
    jogadores.push_back(Jogador("Jogador 1"));
    jogadores.push_back(Jogador("Jogador 2"));

    // 2. Distribuir cartas iniciais
    for (auto& jogador : jogadores) {
        for (int i = 0; i < 7; ++i) {
            jogador.comprarCarta(baralhoDeCompra);
        }
    }

    // 3. Virar a primeira carta do jogo (garante que não seja um Coringa no início)
    do {
        if (baralhoDeCompra.estaVazia()) break;
        pilhaDeDescarte.adicionaElemento(baralhoDeCompra.removeElemento());
    } while (pilhaDeDescarte.elementoTopo().getCor() == "Preto");

    // 4. Lógica Principal do Jogo
    int jogadorAtualIndex = 0;
    string corAtual = pilhaDeDescarte.elementoTopo().getCor();
    bool vitoria = false;

    cout << "------ JOGO DE UNO INICIADO ------" << endl;

    while (!vitoria) {
        Jogador& jogadorAtual = jogadores[jogadorAtualIndex];
        Carta cartaNoTopo = pilhaDeDescarte.elementoTopo();

        cout << "\n========================================" << endl;
        cout << "Vez de: " << jogadorAtual.getNome() << endl;
        cout << "Carta na mesa: ";
        cartaNoTopo.mostrar();
        cout << " (Cor atual: " << corAtual << ")" << endl;

        jogadorAtual.verMao();

        // Verifica se o jogador tem alguma carta para jogar
        bool temJogadaValida = false;
        for (const auto& carta : jogadorAtual.getMao()) {
            if (podeJogar(carta, cartaNoTopo, corAtual)) {
                temJogadaValida = true;
                break;
            }
        }

        if (temJogadaValida) {
            int indiceEscolhido = -1;
            bool jogadaValida = false;
            while (!jogadaValida) {
                cout << "Digite o numero da carta para jogar (ou -1 para comprar): ";
                cin >> indiceEscolhido;

                if (cin.fail()) {
                    cout << "Entrada invalida. Por favor, digite um numero." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                
                if (indiceEscolhido == -1) break;

                if (indiceEscolhido >= 0 && indiceEscolhido < jogadorAtual.numeroDeCartas()) {
                    if (podeJogar(jogadorAtual.getMao()[indiceEscolhido], cartaNoTopo, corAtual)) {
                        jogadaValida = true;
                    } else {
                        cout << "Jogada invalida. Tente novamente." << endl;
                    }
                } else {
                    cout << "Numero de carta invalido. Tente novamente." << endl;
                }
            }
            
            if (indiceEscolhido != -1) {
                Carta cartaJogada = jogadorAtual.jogarCarta(indiceEscolhido);
                pilhaDeDescarte.adicionaElemento(cartaJogada);
                cout << "\n" << jogadorAtual.getNome() << " jogou: ";
                cartaJogada.mostrar();
                cout << endl;

                if (cartaJogada.getCor() == "Preto") {
                    cout << "Escolha a proxima cor (Vermelho, Verde, Azul, Amarelo): ";
                    cin >> corAtual;
                } else {
                    corAtual = cartaJogada.getCor();
                }

            } else {
                 if(baralhoDeCompra.estaVazia()) reciclarPilhaDeDescarte(baralhoDeCompra, pilhaDeDescarte);
                 jogadorAtual.comprarCarta(baralhoDeCompra);
            }

        } else {
            cout << "\n" << jogadorAtual.getNome() << " nao tem jogada valida. Comprando uma carta." << endl;
            if(baralhoDeCompra.estaVazia()) reciclarPilhaDeDescarte(baralhoDeCompra, pilhaDeDescarte);
            jogadorAtual.comprarCarta(baralhoDeCompra);
        }

        if (jogadorAtual.numeroDeCartas() == 0) {
            vitoria = true;
            cout << "\n!!!!!! " << jogadorAtual.getNome() << " VENCEU O JOGO !!!!!!\n" << endl;
        }

        jogadorAtualIndex = (jogadorAtualIndex + 1) % jogadores.size();
    }

    return 0;
}
