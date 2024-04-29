#include <iostream>
#include <stdlib.h>

using namespace std;

int dato, opcion;
int contador = 0;
int i = 0;

// Definición de la estructura del nodo del árbol
struct Nodo
{
    int dato;
    Nodo *izquierda;
    Nodo *derecha;
    Nodo *padre;
};

// Prototipos
void menu();
Nodo *crearNodo(int, Nodo *);
void insertarNodo(Nodo *&, int, Nodo *);
void imprimirArbol(Nodo *, int);
void eliminarNodo(Nodo *, int);
void eliminar(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void destruirNodo(Nodo *);

// Nodo raíz del árbol
Nodo *arbol = NULL;

// Función para crear un nuevo nodo
Nodo *crearNodo(int n, Nodo *padre)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    nuevoNodo->padre = padre;

    return nuevoNodo;
}

// Función para insertar un nodo en el árbol
void insertarNodo(Nodo *&arbol, int n, Nodo *padre)
{
    if (arbol == NULL)
    {
        Nodo *nuevoNodo = crearNodo(n, padre);
        arbol = nuevoNodo;
    }
    else
    {
        int valorRaiz = arbol->dato;
        if (n < valorRaiz)
        {
            insertarNodo(arbol->izquierda, n, arbol);
        }
        else
        {
            insertarNodo(arbol->derecha, n, arbol);
        }
    }
}

// Función para imprimir el árbol
void imprimirArbol(Nodo *arbol, int cont)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        imprimirArbol(arbol->derecha, cont + 1);
        for (i = 0; i < cont; i++)
        {
            cout << "   ";
        }
        cout << arbol->dato << endl;
        imprimirArbol(arbol->izquierda, cont + 1);
    }
}

// Función para encontrar el nodo mínimo en el árbol
Nodo *minimo(Nodo *arbol)
{
    if (arbol == NULL)
    {
        return NULL;
    }
    if (arbol->izquierda)
    {
        return minimo(arbol->izquierda);
    }
    else
    {
        return arbol;
    }
}

// Función para reemplazar un nodo en el árbol
void reemplazar(Nodo *nodoEliminar, Nodo *nuevoNodo)
{
    if (nodoEliminar->padre)
    {
        if (nodoEliminar == nodoEliminar->padre->izquierda)
        {
            nodoEliminar->padre->izquierda = nuevoNodo;
        }
        else if (nodoEliminar == nodoEliminar->padre->derecha)
        {
            nodoEliminar->padre->derecha = nuevoNodo;
        }
    }
    if (nuevoNodo)
    {
        nuevoNodo->padre = nodoEliminar->padre;
    }
}

// Función para eliminar un nodo del árbol
void eliminarNodo(Nodo *arbol, int n)
{
    if (arbol == NULL)
    {
        return;
    }
    else if (n < arbol->dato)
    {
        eliminarNodo(arbol->izquierda, n);
    }
    else if (n > arbol->dato)
    {
        eliminarNodo(arbol->derecha, n);
    }
    else
    {
        eliminar(arbol);
    }
}

// Función para destruir un nodo
void destruirNodo(Nodo *nodo)
{
    nodo->izquierda = NULL;
    nodo->derecha = NULL;

    delete nodo;
}

// Función para eliminar un nodo del árbol
void eliminar(Nodo *nodoEliminar)
{
    if (nodoEliminar->izquierda && nodoEliminar->derecha)
    {
        Nodo *menor = minimo(nodoEliminar->derecha);
        nodoEliminar->dato = menor->dato;
        eliminar(menor);
    }
    else if (nodoEliminar->izquierda)
    {
        reemplazar(nodoEliminar, nodoEliminar->izquierda);
        destruirNodo(nodoEliminar);
    }
    else if (nodoEliminar->derecha)
    {
        reemplazar(nodoEliminar, nodoEliminar->derecha);
        destruirNodo(nodoEliminar);
    }
    else
    {
        reemplazar(nodoEliminar, NULL);
        destruirNodo(nodoEliminar);
    }
}

// Función principal
int main()
{
    menu();
}

// Función para mostrar el menú
void menu()
{
    do
    {
        cout << "\nMENU:\n";
        cout << "1. Insertar un nodo\n";
        cout << "2. Eliminar un nodo\n";
        cout << "3. Mostrar todos los elementos del Árbol\n";
        cout << "4. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "\nIngrese un numero:";
            cin >> dato;
            insertarNodo(arbol, dato, NULL);
            system("pause");
            break;
        case 2:
            cout << "\nDigite el numero a eliminar: ";
            cin >> dato;
            eliminarNodo(arbol, dato);
            system("pause");
            break;
        case 3:
            cout << "\nÁrbol:\n";
            imprimirArbol(arbol, contador);
            cout << "\n";
            system("pause");
            break;
        case 4:
            cout << "\nGracias por trabajar con el programa. ¡Adiós!" << endl;
            break;
        default:
            cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
            system("pause");
        }
        system("cls");
    } while (opcion != 4);
}
