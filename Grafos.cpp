#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura para un nodo de la lista de adyacencia
struct ListNode {
    int destino;
    struct ListNode* siguiente;
};

// Definición de la estructura para representar un grafo
struct Grafo {
    int numVertices;
    struct ListNode** listaAdy;
};

// Función para crear un nuevo nodo de la lista de adyacencia
struct ListNode* nuevoNodo(int destino) {
    struct ListNode* nodo = (struct ListNode*)malloc(sizeof(struct ListNode));
    nodo->destino = destino;
    nodo->siguiente = NULL;
    return nodo;
}

// Función para crear un grafo con un número dado de vértices
struct Grafo* crearGrafo(int numVertices) {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->numVertices = numVertices;
    grafo->listaAdy = (struct ListNode**)malloc(numVertices * sizeof(struct ListNode*));
    
    // Inicializar todas las listas de adyacencia como vacías
    for (int i = 0; i < numVertices; ++i)
        grafo->listaAdy[i] = NULL;
    
    return grafo;
}

// Función para agregar una arista al grafo no dirigido
void agregarArista(struct Grafo* grafo, int origen, int destino) {
    // Agregar arista de origen a destino
    struct ListNode* nodo = nuevoNodo(destino);
    nodo->siguiente = grafo->listaAdy[origen];
    grafo->listaAdy[origen] = nodo;
    
    // Agregar arista de destino a origen (grafo no dirigido)
    nodo = nuevoNodo(origen);
    nodo->siguiente = grafo->listaAdy[destino];
    grafo->listaAdy[destino] = nodo;
}

// Función para imprimir el grafo
void imprimirGrafo(struct Grafo* grafo) {
    for (int v = 0; v < grafo->numVertices; ++v) {
        struct ListNode* temp = grafo->listaAdy[v];
        printf("\n Lista de adyacencia del vertice %d\n ", v);
        while (temp) {
            printf("-> %d", temp->destino);
            temp = temp->siguiente;
        }
        printf("\n");
    }
}

int main() {
    int numVertices, numAristas;
    printf("Introduce el numero de vertices en el grafo: ");
    scanf("%d", &numVertices);
    printf("Introduce el numero de aristas en el grafo: ");
    scanf("%d", &numAristas);

    struct Grafo* grafo = crearGrafo(numVertices);
    
    printf("Introduce las aristas (origen destino):\n");
    for (int i = 0; i < numAristas; ++i) {
        int origen, destino;
        scanf("%d %d", &origen, &destino);
        agregarArista(grafo, origen, destino);
    }
    
    printf("\nGrafo creado:\n");
    imprimirGrafo(grafo);
    
    return 0;
}


