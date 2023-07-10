#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "Node.h"

class List {
    private:
        Node *m_head;
        size_t size;

    public:
        // Função contrutora: inicializa uma nova lista com um no cabeca
        List();

        // Função destrutora: desaloca todos os nos criados, o m_head e o m_tail
        ~List();

        // retorna o nó cabeça da lista atual
        Node* getHead();
        
        // Função append: adiciona um novo elemento ao final da lista
        void append(int value);

        // imprime a lista atual
        void print();

        // retorna o primeiro nó da lista atual
        Node* begin();

        // retorna o último nó da lista atual
        Node* end();

        void swap(Node* atual, Node* aux);

        // realiza o bubble sort na lista atual
        void bubblesort();

        // realiza o insertion sort na lista atual
        void insertionSort();

        // realiza o selection sort na lista atual
        void selectionSort();

        // realiza o quick sort na lista atual
        void quicksort(Node* low, Node* high);
        // auxilia o quicksort a particionar a lista
        Node* partition(Node* inicio, Node* fim);

        // realiza o merge sort na lista atual
        void mergeSort(Node* head, Node* tail);
        // auxilia o merge sort a particionar a lista
        Node* split(Node* head, Node* tail);
        // auxilia o merge sort a combinar duas sublistas
        void merge(Node* head, Node* tail, Node* middle);

        // realiza o cocktail sort na lista atual
        void cocktailSort();
};

#endif
