#include "Game.h"
#include <iostream>
#include <iterator>
#include "Carta.h"

Game::Game(const list<Jogador>& jogadores) {
    this->jogadores = jogadores;
    this->jogadorAtual = 0;
    this->sentidoJogo = true; // Começa em sentido horário
}

void Game::iniciarPartida(){
    cout << "=== INICIANDO A PARTIDA ===" << endl;
    prepararMesa();
    distribuirCartasIniciais();

    // Loop principal do jogo
    while (!verificarVencedor()) {
        executarTurno();
        proximoJogador();
    }

    cout << "\n=== FIM DE JOGO ===" << endl;
    // Anuncia o vencedor (o último jogador a jogar antes da condição de vitória)
    auto it = jogadores.begin();
    std::advance(it, jogadorAtual);
    cout << "O jogador " << it->getNome() << " venceu!" << endl;
}

void Game::prepararMesa(){
    cout << "\nPreparando a mesa..." << endl;
    this->monteDeCompra.criarBaralho();
    this->monteDeCompra.embaralhar();

    Carta cartaInicio = monteDeCompra.elementoTopo();
    monteDeCompra.removeElemento();
    monteDeDescarte.adicionaElemento(cartaInicio);
    this->corAtualDoJogo = cartaInicio.getCor();

    if (this->corAtualDoJogo == "") {
        this->corAtualDoJogo = "azul"; // Define uma cor padrão se for coringa
        cout << "A primeira carta eh um Coringa! A cor inicial sera azul." << endl;
    }

    cout << "A primeira carta na mesa eh: " << cartaInicio.mostrar() << endl;
}

void Game::distribuirCartasIniciais(){
    cout << "\nDistribuindo cartas..." << endl;
    for (int i = 0; i < 7; ++i) {
        for (auto& jogador : jogadores) {
            Carta cartaComprada = monteDeCompra.elementoTopo();
            monteDeCompra.removeElemento();
            jogador.comprarCarta(cartaComprada);
        }
    }
}

bool Game::jogadaValida(const Carta& cartaJogada){
    Carta cartaMesa = monteDeDescarte.elementoTopo();
    if (cartaJogada.getCor() == corAtualDoJogo || cartaJogada.getNumero() == cartaMesa.getNumero() || cartaJogada.getNumero() == "+4" || cartaJogada.getNumero() == "escolha_cor") {
        return true;
    }
    return false;
}

void Game::executarTurno(){
    auto it = jogadores.begin();
    std::advance(it, jogadorAtual);
    Jogador& jogadorDaVez = *it;
    Carta cartaMesa = monteDeDescarte.elementoTopo();

    cout << "\n--- Turno de " << jogadorDaVez.getNome() << " ---" << endl;
    cout << "Carta no topo do descarte: " << cartaMesa.mostrar() << endl;
    jogadorDaVez.mostrarMao();

    if (!jogadorDaVez.temJogadaValida(cartaMesa, this->corAtualDoJogo)) {
        cout << "\nVoce nao tem nenhuma carta valida para jogar. Comprando uma carta..." << endl;
        if (!monteDeCompra.estaVazia()) {
            Carta cartaComprada = monteDeCompra.elementoTopo();
            monteDeCompra.removeElemento();
            jogadorDaVez.comprarCarta(cartaComprada);
            cout << "Voce comprou a carta: " << cartaComprada.mostrar() << endl;
        } else {
            cout << "O monte de compras esta vazio! Passando o turno." << endl;
        }
        return; // Fim do turno
    }

    string escolha = "-1";
    bool jogadaFeita = false;
    while (!jogadaFeita) {
        cout << "\nEscolha uma carta para jogar pelo seu índice ou digite \"c\" para comprar: ";
        cin >> escolha;

        if (escolha == "c") {
            if (!monteDeCompra.estaVazia()) {
                Carta cartaComprada = monteDeCompra.elementoTopo();
                jogadorDaVez.comprarCarta(cartaComprada);
                cout << "Voce comprou a carta: " << cartaComprada.mostrar() << endl;
            } else {
                cout << "O monte de compras esta vazio!" << endl;
            }
            jogadaFeita = true; // Termina o turno após comprar
            continue;
        }

        int indice = std::stoi(escolha);

        if(indice < 0 || indice >= jogadorDaVez.getNumeroCartas()){
            cout << "Indice invalido. Tente novamente." << endl;
            continue;
        }

        Carta cartaEscolhida = jogadorDaVez.verCarta(indice);

        if(jogadaValida(cartaEscolhida)){
            jogadorDaVez.descartarCarta(indice);
            if (cartaEscolhida.getCor() != "preto" && cartaEscolhida.getCor() != "") { 
                corAtualDoJogo = cartaEscolhida.getCor();
            }
            monteDeDescarte.adicionaElemento(cartaEscolhida);
            cout << "\n>> " << jogadorDaVez.getNome() << " jogou a carta " << cartaEscolhida.mostrar() << " << \n";
            aplicarEfeitoCarta(cartaEscolhida);
            jogadaFeita = true;
        }
        else{
            cout << "Jogada invalida! A carta deve combinar cor ou numero ou ser um coringa. Tente novamente."<< endl;
        }
    }
}

void Game::proximoJogador() {
    if (this->sentidoJogo) { // Sentido horário
        this->jogadorAtual++;
        if (this->jogadorAtual >= jogadores.size()) {
            this->jogadorAtual = 0;
        }
    } else { // Sentido anti-horário
        this->jogadorAtual--;
        if (this->jogadorAtual < 0) {
            this->jogadorAtual = jogadores.size() - 1;
        }
    }
}

bool Game::verificarVencedor() const {
    // O jogo termina se qualquer jogador tiver 0 cartas
    for (const auto& jogador : jogadores) {
        if (jogador.getNumeroCartas() == 0) {
            return true;
        }
    }
    return false;
}

void Game::aplicarEfeitoCarta(const Carta& cartaJogada) {
    string numeroCarta = cartaJogada.getNumero();


    if(numeroCarta == "bloqueio"){
        cout << ">> Efeito: Bloqueio! O proximo jogador foi pulado. <<" << endl;
            proximoJogador(); // Simplesmente avança o turno mais uma vez
            return;
    }
    else if(numeroCarta == "inverter"){
        cout << ">> Efeito: Inverter! O sentido do jogo foi alterado. <<" << endl;
            sentidoJogo = !sentidoJogo; // Inverte o booleano (true vira false, false vira true)
            return;
    }
    else if(numeroCarta == "+2"){
        cout << ">> Efeito: +2! O proximo jogador compra duas cartas e eh pulado. <<" << endl;
            { // Usamos chaves para criar um escopo para a variável 'indiceAlvo'
                int indiceAlvo = getIndiceProximoJogador();
                auto it = jogadores.begin();
                std::advance(it, indiceAlvo);
                (*it).comprarCarta(monteDeCompra.elementoTopo());
                monteDeCompra.removeElemento();
                (*it).comprarCarta(monteDeCompra.elementoTopo());
                monteDeCompra.removeElemento();
                proximoJogador(); // Pula o jogador que comprou as cartas
            }
            return;
    }
    else if(numeroCarta == "escolha_cor"){
                int escolhaCor = 0;
                cout << ">> Efeito: Escolha cor! Escolha a proxima cor: <<" << endl;
                cout << "1: Verde, 2: Vermelho, 3: Azul, 4: Amarelo" << endl;
                
                // Loop para garantir que o jogador escolha uma opção válida
                while (escolhaCor < 1 || escolhaCor > 4) {
                    cout << "Digite sua escolha (1-4): ";
                    cin >> escolhaCor;
                    if (cin.fail() || escolhaCor < 1 || escolhaCor > 4) {
                        cout << "Escolha invalida. Tente novamente." << endl;
                        cin.clear(); // Limpa o estado de erro do cin
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta a entrada inválida
                        escolhaCor = 0; // Reseta a escolha para continuar no loop
                    }
                }

                string cores[] = {"Verde", "Vermelho", "Azul", "Amarelo"};
                corAtualDoJogo = cores[escolhaCor - 1];
                cout << ">> A nova cor do jogo eh " << corAtualDoJogo << "! <<" << endl;
                return;
            }
    else if(numeroCarta == "+4"){
        cout << ">> Efeito: +4! O proximo jogador compra quatro cartas e é pulado e o jogador atual escolhe a próxima cor. <<" << endl;
        int escolhaCor = 0;
                // Loop para garantir que o jogador escolha uma opção válida
                while (escolhaCor < 1 || escolhaCor > 4) {
                    cout << "Digite sua escolha (1-4): ";
                    cin >> escolhaCor;
                    if (cin.fail() || escolhaCor < 1 || escolhaCor > 4) {
                        cout << "Escolha invalida. Tente novamente." << endl;
                        cin.clear(); // Limpa o estado de erro do cin
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta a entrada inválida
                        escolhaCor = 0; // Reseta a escolha para continuar no loop
                    }
                }

        string cores[] = {"Verde", "Vermelho", "Azul", "Amarelo"};
        corAtualDoJogo = cores[escolhaCor - 1];
        cout << ">> A nova cor do jogo eh " << corAtualDoJogo << "! <<" << endl;
            { // Usamos chaves para criar um escopo para a variável 'indiceAlvo'
            int indiceAlvo = getIndiceProximoJogador();
            auto it = jogadores.begin();
            std::advance(it, indiceAlvo);
            (*it).comprarCarta(monteDeCompra.elementoTopo());
            monteDeCompra.removeElemento();
            (*it).comprarCarta(monteDeCompra.elementoTopo());
            monteDeCompra.removeElemento();
            (*it).comprarCarta(monteDeCompra.elementoTopo());
            monteDeCompra.removeElemento();
            (*it).comprarCarta(monteDeCompra.elementoTopo());
            monteDeCompra.removeElemento();
            proximoJogador(); // Pula o jogador que comprou as cartas
            }
    }
            
}

int Game::getIndiceProximoJogador() const {
    int proximo = jogadorAtual;
    if (sentidoJogo) { // Sentido horário
        proximo++;
        if (proximo >= jogadores.size()) {
            proximo = 0;
        }
    } else { // Sentido anti-horário
        proximo--;
        if (proximo < 0) {
            proximo = jogadores.size() - 1;
        }
    }
    return proximo;
}