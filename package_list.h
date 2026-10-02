#ifndef PACKAGE_LIST_H
#define PACKAGE_LIST_H

// Estructura base del nodo para guardar la informacion de cada paquete logistico
struct Node {
    int packageId;
    float weight;
    int priority;
    struct Node* next;
};

// Declaracion de las funciones para gestionar la lista enlazada simple[cite: 1]
void insertPackage(struct Node** head, int packageId, float weight, int priority);
void printList(struct Node* head);
void freeList(struct Node* head);

#endif