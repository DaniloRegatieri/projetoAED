#include <iostream>
#include <string>

using namespace std;

// estrutura do nó da lista
struct No {
    int valor;      // valor contido no nó
    No* ptrProximo; // ponteiro para o próximo nó
};

// classe lista ligada
class Lista {
private:
    No* ptrInicio; // ponteiro para o início da lista

public:
    Lista() {
        ptrInicio = nullptr;
    }

    // verifica se a lista está vazia
    bool estaVazia() {
        return ptrInicio == nullptr;
    }

    // adiciona elemento no início da lista
    void adicionaInicio(int sValor) {
        No* novo = new No();
        novo->valor = sValor;
        novo->ptrProximo = ptrInicio;
        ptrInicio = novo;
    }

    // adiciona elemento no final da lista
    void adicionaFim(int sValor) {
        No* novo = new No();
        novo->valor = sValor;
        novo->ptrProximo = nullptr;

        if (estaVazia()) {
            ptrInicio = novo;
            return;
        }

        No* aux = ptrInicio;
        while (aux->ptrProximo != nullptr) {
            aux = aux->ptrProximo;
        }
        aux->ptrProximo = novo;
    }

    // remove elemento do início da lista
    void removeInicio() {
        if (!estaVazia()) {
            No* aux = ptrInicio;
            ptrInicio = ptrInicio->ptrProximo;
            cout << "Elemento " << aux->valor << " removido do início." << endl;
            delete aux;
        } else {
            cout << "Lista vazia." << endl;
        }
    }

    // remove elemento do final da lista
    void removeFim() {
        if (estaVazia()) {
            cout << "Lista vazia." << endl;
            return;
        }

        if (ptrInicio->ptrProximo == nullptr) { // apenas 1 elemento
            cout << "Elemento " << ptrInicio->valor << " removido do final." << endl;
            delete ptrInicio;
            ptrInicio = nullptr;
            return;
        }

        No* aux = ptrInicio;
        No* prev = nullptr;
        while (aux->ptrProximo != nullptr) {
            prev = aux;
            aux = aux->ptrProximo;
        }
        cout << "Elemento " << aux->valor << " removido do final." << endl;
        prev->ptrProximo = nullptr;
        delete aux;
    }

    // varre a lista
    void varrerLista() {
        if (estaVazia()) {
            cout << "Lista vazia." << endl;
            return;
        }

        No* aux = ptrInicio;
        while (aux != nullptr) {
            cout << aux->valor << " -> ";
            aux = aux->ptrProximo;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Lista lista1;
    int numElementos, valor;

    cout << "Digite o número de elementos: ";
    cin >> numElementos;

    for (int i = 0; i < numElementos; i++) {
        cout << "Elemento a ser adicionado: ";
        cin >> valor;
        lista1.adicionaFim(valor); // adicionando no final da lista
    }

    cout << "Lista atual:" << endl;
    lista1.varrerLista();

    cout << "Removendo elemento do início..." << endl;
    lista1.removeInicio();
    lista1.varrerLista();

    cout << "Removendo elemento do final..." << endl;
    lista1.removeFim();
    lista1.varrerLista();

    return 0;
}
