#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo
{
    Nodo *siguiente;
    int dato;
};

Nodo *lista = NULL;
int dato;
void menu();
void insertarlista(Nodo *&, int);
void eliminarnodo(Nodo *&, int);
void buscarlista(Nodo *, int);
void mostrarlista(Nodo *);
void eliminarlista(Nodo *&, int &);

int main()
{

    menu();

    getch();
    return 0;
}

void menu()
{
    int opc;
    do
    {
        cout << "\t.:MENU:.\n";
        cout << "1. Insertar elemento en la lista." << endl;
        cout << "2. Buscar elemento en la lista." << endl;
        cout << "3. Mostrar elementos de la lista." << endl;
        cout << "4. Eliminar elemento de la lista." << endl;
        cout << "5. Vaciar la lista" << endl;
        cout << "6. Salir" << endl;
        cin >> opc;

        switch (opc)
        {
        case 1:
            cout << "Digite el elemento a ingresar: ";
            cin >> dato;
            insertarlista(lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 2:
            cout << "Digite el elemento a buscar: ";
            cin >> dato;
            buscarlista(lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 3:
            cout << "\tMostrando elementos de la lista\n"
                << endl;
            mostrarlista(lista);
            cout << "\n";
            system("pause");
            break;
        case 4:
            cout << "Digite el elemento a eliminar de la lista: ";
            cin >> dato;
            eliminarnodo(lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 5:
            eliminarlista(lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 6:
            break;
        }
        system("cls");
    } while (opc != 6);
}

void insertarlista(Nodo *&lista, int n)
{
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while ((aux1 != NULL) && (aux1->dato < n))
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (lista == aux1)
    {
        lista = nuevo_nodo;
    }
    else
    {
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;

    cout << n << " se ha agregado correctamente a la lista." << endl;
}

void eliminarnodo(Nodo *&lista, int n)
{
    if (lista != NULL)
    {
        Nodo *aux_borrar;
        Nodo *anterior = NULL;

        aux_borrar = lista;

        while ((aux_borrar != NULL) && (aux_borrar->dato != n))
        {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        if (aux_borrar == NULL)
        {
            cout << "<<Elemento no encontrado>>";
        }
        else if (anterior == NULL)
        {
            lista = lista->siguiente;
            delete aux_borrar;
        }
        else
        {
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
    }
}

void buscarlista(Nodo *lista, int n)
{
    Nodo *actual = new Nodo();
    actual = lista;
    bool band = false;

    while ((actual != NULL) && (actual->dato <= n))
    {
        if (actual->dato == n)
        {
            band = true;
        }
        actual = actual->siguiente;
    }

    if (band == true)
    {
        cout << n << " se ha encontrado en la lista." << endl;
    }
    else
    {
        cout << n << " NO se ha encontrado en la lista." << endl;
    }
}

void mostrarlista(Nodo *lista)
{
    Nodo *actual = lista;

    while (actual != NULL)
    {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
}

void eliminarlista(Nodo *&lista, int &n)
{
    char opc;

    cout << "¿Seguro de eliminar todos los elementos de la lista? (S/N): ";
    cin >> opc;

    if (((opc == 'S') || (opc == 's')))

        while (lista != NULL)
        {
            Nodo *aux = lista;
            n = aux->dato;
            lista = aux->siguiente;
            delete aux;
        }
    if (((opc == 'S') || (opc == 's')))
    {
        cout << "\tTodos los elementos de la lista han sido eliminados.\n"<< endl;
    }
    else
    {
        cout << "\tVolver.\n" << endl;
    }
}
