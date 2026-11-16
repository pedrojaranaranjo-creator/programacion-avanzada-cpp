
#include <iostream>

#include "cola_impresion.h"

int main() {

    ColaDeImpresion cola;

    cola.agregar(12);
    cola.agregar(45);
    cola.agregar(8);
    cola.agregar(30);

    // Dividir los trabajos de mas de 20 paginas.
    cola.dividirGrandes();

    // Mostrar todos los trabajos.
    std::cout << "Cola:";

    for (int i = 0; i < cola.cantidad(); i++) {
        std::cout << " " << cola.paginasDe(i);
    }

    std::cout << std::endl;

    // Mostrar minutos de impresion de 25 paginas.
    std::cout << "Minutos de 25 paginas: "
              << minutosDeImpresion(25) << std::endl;

    // Mostrar minutos totales.
    std::cout << "Minutos totales: "
              << cola.minutosTotales() << std::endl;

    return 0;
}
