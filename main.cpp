#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>
#include "List.h"

// Função para ordenar um vetor usando o algoritmo de ordenação desejado
void ordenarLista(List* lista, const std::string& algoritmo) {
    if (algoritmo == "bubble") {
        lista->bubblesort();
    } else if (algoritmo == "selection") {
        lista->selectionSort();
    } else if(algoritmo == "quick") {
        lista->quicksort(lista->begin(), lista->end());
    }
} 
    // Adicione as implementações para os outros algoritmos de ordenação

int main() {
    // Vetor com os nomes dos algoritmos de ordenação
    std::vector<std::string> algoritmos = {"bubble", "selection", "quick"};

    // Intervalo de tamanhos de vetor desejado
    int tamanhoInicial = 1000;
    int tamanhoFinal = 99000;
    int tamanhoIncremento = 1000;

    // Número de execuções por tamanho de vetor
    int numExecucoes = 5;

    // Abrir arquivo de saída
    std::ofstream arquivo("resultados.txt");

    // Loop pelos tamanhos de vetor
    for (int tamanhoVetor = tamanhoInicial; tamanhoVetor <= tamanhoFinal; tamanhoVetor += tamanhoIncremento) {
        // Imprimir tamanho do vetor no arquivo
        arquivo << tamanhoVetor << '\t';

        // Loop pelos algoritmos de ordenação
        for (const auto& algoritmo : algoritmos) {
            // Variável para armazenar o tempo total de execução
            double tempoTotal = 0.0;

            // Executar o algoritmo de ordenação 'numExecucoes' vezes
            for (int execucao = 0; execucao < numExecucoes; execucao++) {
                // Criar uma lista com valores aleatórios
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(1, 100);

                List* lista = new List;

                for (int i = 0; i < tamanhoVetor; ++i) {
                int nodeValue = dis(gen);
                lista->append(nodeValue);
                };

                // Realizar a ordenação e registrar o tempo de execução
                auto inicio = std::chrono::steady_clock::now();
                ordenarLista(lista, algoritmo);
                auto fim = std::chrono::steady_clock::now();

                // Calcular o tempo de execução em segundos
                double tempoExecucao = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
                tempoTotal += tempoExecucao;
            }

            // Calcular o tempo médio de execução
            double tempoMedio = tempoTotal / numExecucoes;

            // Imprimir tempo médio no arquivo
            arquivo << tempoMedio << '\t';
        }

        // Quebrar linha no arquivo após cada tamanho de vetor
        arquivo << '\n';
    }

    // Fechar arquivo de saída
    arquivo.close();

    return 0;
}
