#include <stdio.h>
#include <stdlib.h>
#include "package_list.h"

// Insercion de un paquete al inicio de la lista enlazada
void insertPackage(struct Node** head, int packageId, float weight, int priority) {
    struct Node* newNode;
    
    // Asignacion de memoria para el nuevo nodo
    newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Validacion de la asignacion de memoria
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    
    // Asignacion de los datos del paquete logistico
    newNode->packageId = packageId;
    newNode->weight = weight;
    newNode->priority = priority;
    
    // Conexion del nuevo nodo con la cabeza de la lista
    newNode->next = *head;
    // Actualizacion del puntero de la cabeza principal
    *head = newNode;
}

// Impresion de la lista de paquetes para verificacion de datos
void printList(struct Node* head) {
    struct Node* current;
    
    current = head;
    printf("Package Distribution List\n");
    
    // Recorrido de la lista hasta el ultimo nodo
    while (current != NULL) {
        printf("ID: %d | Weight: %.2f | Priority: %d\n", 
               current->packageId, current->weight, current->priority);
        // Avance al siguiente paquete en la estructura
        current = current->next;
    }
}

// Liberacion de memoria de la lista enlazada al finalizar la ejecucion
void freeList(struct Node* head) {
    struct Node* current;
    struct Node* nextNode;
    
    current = head;
    
    // Iteracion para liberar cada nodo y prevenir fugas de memoria
    while (current != NULL) {
        nextNode = current->next; 
        free(current);            
        current = nextNode;       
    }
}