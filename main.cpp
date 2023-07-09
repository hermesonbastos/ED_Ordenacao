#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <chrono>
#include <limits>
#include "List.h"
using namespace std;

void gera_dados(const int& num_iteracoes, const int vetor_tam[]) {
	for(int n = 0; n < num_iteracoes; ++n) {
		for(int semente = 0; semente < 5; semente++) {	
			std::string nome_arquivo = "dados/random"+std::to_string(n)+"_"+std::to_string(semente)+".dat";
			ofstream fout(nome_arquivo.c_str(), ios::binary);
			srand(time(NULL));
			int r;
			int tamanho_vetor = vetor_tam[n];
			for(int i = 0; i < tamanho_vetor; i++) 
			{
				r = rand();
				fout.write((char*) &r, sizeof(r)); 
			}
			fout.close();
		}
	}
}

void ler_dados(int n, List* lista, const char *nomeArquivo) {	
    int value;
	ifstream input_file(nomeArquivo, ios::binary);
	for (int i = 0; i < n; i++) 
	{
		input_file.read((char*)&value, sizeof(int)); 
        lista->append(value);
	}
	input_file.close();
}

int main(){
	const int tam[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 
	                   11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 
					   20000, 21000, 22000, 23000, 24000, 25000, 26000, 27000, 28000, 
					   29000, 30000, 31000, 32000, 33000, 34000, 35000, 36000, 37000, 
					   38000, 39000, 40000, 41000, 42000, 43000, 44000, 45000, 46000, 
					   47000, 48000, 49000, 50000, 51000, 52000, 53000, 54000, 55000, 
					   56000, 57000, 58000, 59000, 60000, 61000, 62000, 63000, 64000, 
					   65000, 66000, 67000, 68000, 69000, 70000, 71000, 72000, 73000, 
					   74000, 75000, 76000, 77000, 78000, 79000, 80000, 81000, 82000, 
					   83000, 84000, 85000, 86000, 87000, 88000, 89000, 90000, 91000, 
					   92000, 93000, 94000, 95000, 96000, 97000, 98000, 99000};
	
	const int TOTAL_N = sizeof(tam)/sizeof(tam[0]);

    vector<string> vec = {"2.txt", "insertionSort.txt", "selectionSort.txt", "quickSort.txt", "mergeSort.txt", "cocktailSort.txt"};

	gera_dados(TOTAL_N, tam);
	
    for(int i = 3; i < 6; i++){
        ofstream outputFile("./results/" + vec[i]);

        for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {	
            long double duracao_media = 0.0;
            long double duracao_cocktail = 0.0;
            const int tamanho_vetor = tam[iteracao];
    
        for(int semente = 0; semente < 5; semente++) {	
            List *lista = new List();
            string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
            
            ler_dados(tamanho_vetor, lista, nome_arquivo.c_str());

            cout << "Oi estou testando " + vec[i] + " tamanho:" + to_string(tamanho_vetor) << "\n";
            if(i == 0){
                auto ini = std::chrono::high_resolution_clock::now();
                lista->bubblesort();
                auto fim = std::chrono::high_resolution_clock::now();
                duracao_cocktail = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
            } else if(i == 1){
                auto ini = std::chrono::high_resolution_clock::now();
                lista->insertionSort();
                auto fim = std::chrono::high_resolution_clock::now();
                duracao_cocktail = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
            } else if(i == 2){
                auto ini = std::chrono::high_resolution_clock::now();
                lista->selectionSort();
                auto fim = std::chrono::high_resolution_clock::now();
                duracao_cocktail = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();              
            } else if(i == 3){
                auto ini = std::chrono::high_resolution_clock::now();
                lista->quicksort(lista->begin(), lista->end());
                auto fim = std::chrono::high_resolution_clock::now();
                duracao_cocktail = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();                
            } else if(i == 4){
                auto ini = std::chrono::high_resolution_clock::now();
                lista->mergeSort(lista->begin(), lista->end());
                auto fim = std::chrono::high_resolution_clock::now();
                duracao_cocktail = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();                
            } else if(i == 5){
                auto ini = std::chrono::high_resolution_clock::now();
                lista->cocktailSort();
                auto fim = std::chrono::high_resolution_clock::now();
                duracao_cocktail = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();             
            }
            duracao_media += duracao_cocktail;
        }

        duracao_media /= 5.0;
		
		outputFile << tamanho_vetor << " " << duracao_media << "\n";
	}
	outputFile.close();
    }
}
