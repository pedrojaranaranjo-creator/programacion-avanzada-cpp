
#pragma once

#include <vector>
#include <stdexcept>

// Promedio movil de las lecturas del sensor de temperatura.

std::vector<double> promedioMovil(std::vector<double> lecturas, int ventana) {

    std::vector<double> promedios;

    int cantidad = lecturas.size();

    // Validar que la ventana sea positiva.
    if (ventana <= 0) {
        throw std::invalid_argument("La ventana debe ser positiva");
    }

    // Validar que existan suficientes lecturas.
    if (ventana > cantidad) {
        return promedios;
    }

    // Recorrer solamente las ventanas completas.
    for (int inicio = 0; inicio <= cantidad - ventana; inicio++) {

        double suma = 0.0;

        // Sumar las lecturas de cada ventana.
        for (int j = 0; j < ventana; j++) {
            suma = suma + lecturas[inicio + j];
        }

        // Calcular y guardar el promedio.
        promedios.push_back(suma / ventana);
    }

    return promedios;
}

