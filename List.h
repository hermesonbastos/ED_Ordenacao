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
        
        // Função append: adiciona um novo elemento ao final da lista
        void append(int value);

        // Função begin: retorna o valor no inicio da lista
        int begin();

        // imprime a lista atual
        void print();

        // insertion sort
        void insertionSort();
        
        // // merge Sort
        // void mergeSort();

};

#endif
