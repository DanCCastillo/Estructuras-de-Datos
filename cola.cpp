#include <iostream>
#include <queue>

using namespace std;

void insertarCaracter(queue<char> &cola) {
    char caracter;
    cout << "Ingrese un caracter: ";
    cin >> caracter;
    cola.push(caracter);
    cout << "Caracter insertado correctamente." << endl;
}

void eliminarCaracter(queue<char> &cola) {
    if (!cola.empty()) {
        cola.pop();
        cout << "Caracter eliminado correctamente." << endl;
    } else {
        cout << "La cola está vacía. No se puede eliminar ningún caracter." << endl;
    }
}

void mostrarCola(queue<char> cola) {
    if (!cola.empty()) {
        cout << "Elementos en la cola: ";
        while (!cola.empty()) {
            cout << cola.front() << " ";
            cola.pop();
        }
        cout << endl;
    } else {
        cout << "La cola está vacía." << endl;
    }
}

int main() {
    queue<char> cola;
    int opcion;

    do {
        cout << "\nMENU:\n";
        cout << "1. Insertar un caracter a una cola\n";
        cout << "2. Eliminar caracter a una cola\n";
        cout << "3. Mostrar todos los elementos de la cola\n";
        cout << "4. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                insertarCaracter(cola);
                system("pause");
                break;
            case 2:
                eliminarCaracter(cola);
                system("pause");
                break;
            case 3:
                mostrarCola(cola);
                system("pause");
                break;
            case 4:
                cout << "\nGracias por trabajar con el programa, Adios" << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
                system("pause");
        }
    } while (opcion != 4);

    return 0;
}