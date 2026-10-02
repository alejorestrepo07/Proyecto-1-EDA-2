#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"

// Bubble Sort de fuerza bruta intercambiando nodos logicamente (punteros)
void bubbleSort(struct Node** head) {
    struct Node** h;
    int swapped;
    struct Node* p1;
    struct Node* p2;

    if (*head == NULL) return;

    do {
        swapped = 0;
        h = head;

        while (*h != NULL && (*h)->next != NULL) {
            p1 = *h;
            p2 = p1->next;

            // Ordenamos por ID del paquete, si el primero es mayor, se cambian los punteros
            if (p1->packageId > p2->packageId) {
                p1->next = p2->next;
                p2->next = p1;
                *h = p2;
                swapped = 1;
            }
            h = &(*h)->next;
        }
    } while (swapped);
}

// Merge Sort adaptado para listas enlazadas usando Dividir y Conquistar[cite: 1]
void mergeSort(struct Node** headRef) {
    struct Node* head;
    struct Node* a;
    struct Node* b;

    head = *headRef;

    // Si la lista esta vacia o solo tiene un paquete, ya esta melo
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    // Partimos la lista en dos mitades
    frontBackSplit(head, &a, &b);

    // Llamada recursiva pa ordenar cada mitad
    mergeSort(&a);
    mergeSort(&b);

    // Juntamos las dos mitades ya ordenaditas
    *headRef = sortedMerge(a, b);
}

// Funcion auxiliar para unir dos listas ordenadas en el Merge Sort
struct Node* sortedMerge(struct Node* a, struct Node* b) {
    struct Node* result;
    
    result = NULL;

    if (a == NULL) return b;
    if (b == NULL) return a;

    // Aca vamos acomodando el menor de primero
    if (a->packageId <= b->packageId) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

// Funcion auxiliar para partir la lista en dos usando el truco de punteros rapido y lento
void frontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    struct Node* fast;
    struct Node* slow;

    slow = source;
    fast = source->next;

    // El rapido avanza dos nodos y el lento avanza uno
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // El lento queda en la mitad, asi que ahi cortamos la lista
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Busqueda lineal por fuerza bruta nodo por nodo[cite: 1]
struct Node* linearSearch(struct Node* head, int targetId) {
    struct Node* current;
    
    current = head;

    // Recorremos buscando el paquete hasta que aparezca o se acabe la lista
    while (current != NULL) {
        if (current->packageId == targetId) {
            return current;
        }
        current = current->next;
    }
    
    // Si no pillamos nada, devolvemos NULL
    return NULL;
}