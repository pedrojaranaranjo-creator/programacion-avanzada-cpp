#include <iostream>
using namespace std;

// Plantilla 1: devuelve el menor de tres valores
template <typename T>
T menorDeTres(T a, T b, T c) {
    T menor = a;

    if (b < menor) {
        menor = b;
    }

    if (c < menor) {
        menor = c;
    }

    return menor;
}

// Plantilla 2: suma los elementos de un arreglo
template <typename T>
T sumarArreglo(T valores[], int cantidad) {
    if (cantidad == 0) {
        return T();
    }

    T suma = valores[0];

    for (int i = 1; i < cantidad; i++) {
        suma = suma + valores[i];
    }

    return suma;
}

// Plantilla 3: intercambia dos valores usando punteros
template <typename T>
void intercambiar(T* a, T* b) {
    T temporal = *a;
    *a = *b;
    *b = temporal;
}

int main() {

    // Menor de tres
    cout << "Menor de 14, 9 y 30: "
         << menorDeTres(14, 9, 30) << endl;

    cout << "Menor de 0.75, 1.5 y 0.25: "
         << menorDeTres(0.75, 1.5, 0.25) << endl;

    cout << "Menor de q, c y x: "
         << menorDeTres('q', 'c', 'x') << endl;

    // Sumar arreglos
    int enteros[] = {4, 8, 15, 16, 23, 42};

    double decimales[] = {1.5, 2.25, 0.25};

    cout << "Suma de enteros: "
         << sumarArreglo(enteros, 6) << endl;

    cout << "Suma de decimales: "
         << sumarArreglo(decimales, 3) << endl;

    // Intercambiar enteros
    int x = 3;
    int y = 7;

    intercambiar(&x, &y);

    cout << "Intercambio de enteros: "
         << x << " " << y << endl;

    // Intercambiar decimales
    double a = 1.5;
    double b = 9.5;

    intercambiar(&a, &b);

    cout << "Intercambio de decimales: "
         << a << " " << b << endl;

    // Menor mezclando int y double
    cout << "Menor de 5, 2.5 y 4: "
         << menorDeTres<double>(5, 2.5, 4) << endl;

    return 0;
}

