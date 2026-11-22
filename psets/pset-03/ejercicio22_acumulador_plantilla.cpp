#include <iostream>
using namespace std;

template <typename T>
class Acumulador {
private:
    T total;
    T maximo;
    int cantidad;

public:
    // Constructor
    Acumulador() {
        total = T();
        maximo = T();
        cantidad = 0;
    }

    // Agregar un valor
    void agregar(T valor) {
        total = total + valor;

        if (cantidad == 0 || valor > maximo) {
            maximo = valor;
        }

        cantidad++;
    }

    // Obtener el total
    T getTotal() {
        return total;
    }

    // Obtener el maximo
    T getMaximo() {
        return maximo;
    }

    // Obtener la cantidad
    int getCantidad() {
        return cantidad;
    }

    // Calcular el promedio
    double promedio() {
        if (cantidad == 0) {
            return 0;
        }

        return static_cast<double>(total) / cantidad;
    }

    // Reiniciar el acumulador
    void reiniciar() {
        total = T();
        maximo = T();
        cantidad = 0;
    }
};

int main() {

    // Acumulador de goles
    Acumulador<int> goles;

    goles.agregar(2);
    goles.agregar(0);
    goles.agregar(5);
    goles.agregar(1);

    cout << "Goles: " << goles.getTotal()
         << " en " << goles.getCantidad()
         << " partidos, maximo " << goles.getMaximo()
         << ", promedio " << goles.promedio() << endl;

    // Acumulador de diferencias de tiempo
    Acumulador<double> tiempos;

    tiempos.agregar(-3.5);
    tiempos.agregar(-1.25);
    tiempos.agregar(-2.0);

    cout << "Diferencias: total " << tiempos.getTotal()
         << ", maximo " << tiempos.getMaximo() << endl;

    // Reiniciar goles
    goles.reiniciar();

    cout << "Despues de reiniciar: "
         << goles.getCantidad()
         << " partidos, promedio "
         << goles.promedio() << endl;

    return 0;
}

