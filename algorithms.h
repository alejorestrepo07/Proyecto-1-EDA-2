#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "package_list.h"

// Ordenamiento por fuerza bruta usando Bubble Sort para los paquetes[cite: 1]
void bubbleSort(struct Node** head);

// Ordenamiento por el metodo de dividir y conquistar usando Merge Sort adaptado[cite: 1]
void mergeSort(struct Node** head);

// Funciones auxiliares necesarias para que el Merge Sort funcione con listas enlazadas[cite: 1]
void frontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef);
struct Node* sortedMerge(struct Node* a, struct Node* b);

// Busqueda lineal de fuerza bruta para encontrar un paquete por su ID unico[cite: 1]
struct Node* linearSearch(struct Node* head, int targetId);

#endif