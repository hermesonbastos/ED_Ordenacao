#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <chrono>
#include <limits>
#include "List.h"
using namespace std;

int main(){

    // Obtém o tempo atual como semente para o gerador de números aleatórios
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    mt19937 gen(seed);

    int maxInt = numeric_limits<int>::max();
    // Cria uma distribuição uniforme de números inteiros nessa faixa
    uniform_int_distribution<int> dist(1, maxInt);
    vector<string> vec = {"bubbleSort.txt", "insertionSort.txt", "selectionSort.txt", "quickSort.txt", "mergeSort.txt", "cocktailSort.txt"};

    for(int i = 0; i < 6; i++){
        ofstream outputFile("./results/" + vec[i]);
        for(int size = 1000; size < 100000; size+=1000){
            List *lista = new List();
            int med = 0;
            int temp;
            for(int i = 0; i < size; i++){
                int randomNum = dist(gen);
                lista->append(randomNum);
            }

            for(int i = 0; i < 5; i++){
                if(i == 0){
                    auto start = chrono::high_resolution_clock::now();
                    lista->bubblesort();
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    temp = duration.count();
                } else if(i == 1){
                    auto start = chrono::high_resolution_clock::now();
                    lista->insertionSort();
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    temp = duration.count();
                } else if(i == 2){
                    auto start = chrono::high_resolution_clock::now();
                    lista->selectionSort();
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    temp = duration.count();                   
                } else if(i == 3){
                    auto start = chrono::high_resolution_clock::now();
                    lista->quicksort(lista->begin(), lista->end());
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    temp = duration.count();                    
                } else if(i == 4){
                     auto start = chrono::high_resolution_clock::now();
                    lista->mergeSort(lista->begin(), lista->end());
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    temp = duration.count();                  
                } else {
                    auto start = chrono::high_resolution_clock::now();
                    lista->cocktailSort();
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    temp = duration.count();                    
                }

                med+=temp;
            }
            med = med / 5.0;
            outputFile << size << " " << med << endl;
            delete lista;
        }
        outputFile.close();
    }
}