/* inicio do código do projeto de AED*/
#include <iostream>
#include <string>
#include <algorithm>  // Para usar swap
#include <random>     // Para random_device, mt19937 e uniform_int_distribution

#include "Baralho.h"

using namespace std;

int main(){
    Baralho monteInicial;
    monteInicial.criarBaralho();
    monteInicial.varrerPilha();

    monteInicial.embaralha();
    monteInicial.imprimeMatriz();

    Baralho monteEmbaralhado;
    monteEmbaralhado.converteMatriz(monteInicial);
}