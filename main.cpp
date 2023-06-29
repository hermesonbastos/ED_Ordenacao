#include <iostream>
#include <random>
#include <chrono>
#include "List.h"
using namespace std;

int main(){

    // Obtém o tempo atual como semente para o gerador de números aleatórios
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    mt19937 gen(seed);

    // Cria uma distribuição uniforme de números inteiros nessa faixa
    uniform_int_distribution<int> dist(1, 100);

    for(int j = 0; j < 2; j++){
        List *lista = new List();
        for(int i = 0; i < 10; i++){
            int randomNum = dist(gen);
            lista->append(randomNum);
        }
        lista->print();
        cout << "\n";
    }
}