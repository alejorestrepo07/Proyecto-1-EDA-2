#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "package_list.h"
#include "algorithms.h"

int main() {
    // Declaracion de todas las variables en ingles al inicio
    int numPackages;
    struct Node* listForBubble;
    struct Node* listForMerge;
    int i;
    int randId;
    float randWeight;
    int randPriority;
    clock_t start;
    clock_t end;
    double timeBubble;
    double timeMerge;
    double timeSearch;
    int searchTargets[100];
    struct Node* foundNode;

    numPackages = 50000;
    listForBubble = NULL;
    listForMerge = NULL;

    // Inicializacion de la semilla para la generacion de numeros aleatorios
    srand(time(NULL));

    printf("Generando %d paquetes logisticos\n", numPackages);

    // Generacion de la lista aleatoria de paquetes
    for (i = 0; i < numPackages; i++) {
        // Asignacion de IDs unicos simulados, pesos y prioridades
        randId = rand() % 1000000;
        randWeight = (float)(rand() % 10000) / 100.0;
        randPriority = (rand() % 5) + 1;

        // Insercion de datos equivalentes en ambas listas para su comparacion
        insertPackage(&listForBubble, randId, randWeight, randPriority);
        insertPackage(&listForMerge, randId, randWeight, randPriority);
        
        // Almacenamiento de IDs especificos para las pruebas de busqueda
        if (i < 100) {
            searchTargets[i] = randId;
        }
    }

    printf("Paquetes generados. Iniciando simulacion empirica\n\n");

    // Medicion de tiempo para el algoritmo de ordenamiento por fuerza bruta
    printf("Pruebas de Ordenamiento\n");
    start = clock();
    bubbleSort(&listForBubble);
    end = clock();
    timeBubble = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    printf("Tiempo de ejecucion Bubble Sort: %.2f ms\n", timeBubble);

    // Medicion de tiempo para el algoritmo de ordenamiento por dividir y conquistar
    start = clock();
    mergeSort(&listForMerge);
    end = clock();
    timeMerge = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    printf("Tiempo de ejecucion Merge Sort: %.2f ms\n\n", timeMerge);

    // Medicion de tiempo para rondas multiples de busqueda lineal
    printf("Pruebas de Busqueda\n");
    start = clock();
    for (i = 0; i < 100; i++) {
        foundNode = linearSearch(listForMerge, searchTargets[i]);
    }
    end = clock();
    timeSearch = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    printf("Tiempo de Busqueda Lineal en 100 rondas: %.2f ms\n\n", timeSearch);

    // Reporte de resultados empiricos y analisis estructural
    printf("Analisis Estructural Empirico\n");
    printf("Nota: La busqueda avanzada como la Binaria no es eficiente aqui.\n");
    printf("Debido a la falta de acceso directo a indices en listas enlazadas simples, es obligatorio recorrer nodo por nodo.\n");
    printf("La busqueda lineal iterativa presento un tiempo de %.2f ms para 100 consultas.\n\n", timeSearch);

    // Liberacion de memoria de las listas enlazadas para evitar fugas
    freeList(listForBubble);
    freeList(listForMerge);

    return 0;
}