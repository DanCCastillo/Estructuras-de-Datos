#include <iostream>
#include <stack>

using namespace std;

void mostrarMenu() {
    cout << "Menu:" << endl;
    cout << "1. Insertar un caracter a la pila" << endl;
    cout << "2. Eliminar caracter a la pila" << endl;
    cout << "3. Mostrar todos los elementos de la pila" << endl;
    cout << "4. Salir" << endl;
}

int main() {
    stack<char> pila;
    int opcion;
    char elemento;

    do {
        mostrarMenu();
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el caracter a insertar: ";
                cin >> elemento;
                pila.push(elemento);
                cout << "Caracter insertado correctamente." << endl;
                break;
            case 2:
                if (!pila.empty()) {
                    cout << "Eliminando caracter de la pila: " << pila.top() << endl;
                    pila.pop();
                } else {
                    cout << "La pila está vacía." << endl;
                }
                break;
            case 3:
                if (!pila.empty()) {
                    cout << "Elementos de la pila:" << endl;
                    stack<char> pilaCopia = pila;
                    while (!pilaCopia.empty()) {
                        cout << pilaCopia.top() << endl;
                        pilaCopia.pop();
                    }
                } else {
                    cout << "La pila está vacía." << endl;
                }
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}
