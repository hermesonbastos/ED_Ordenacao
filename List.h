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

        Node* getHead();
        
        // Função append: adiciona um novo elemento ao final da lista
        void append(int value);

        // imprime a lista atual
        void print();

        Node* begin();
        Node* end();
        void swap(Node* atual, Node* aux);
        void bubblesort();
        void selectionSort();
        Node* partition(Node* inicio, Node* fim);
        void quicksort(Node* low, Node* high);

        // insertion sort
        void insertionSort();

        // merge sort
        void mergeSort(Node* head, Node* tail);

        Node* split(Node* head, Node* tail);

        void merge(Node* head, Node* tail, Node* middle);

        // gnome sort
        void cocktailSort();
};

#endif
