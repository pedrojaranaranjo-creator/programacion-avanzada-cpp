
#include <iostream>
#include <optional>
#include <stdexcept>

#include "estacionamiento.h"

int main() {
    Estacionamiento estacionamiento(3);

    int llegadas[5] = {4521, 7788, 3011, 9090, 7788};

    // Registrar la llegada de los vehículos
    for (int i = 0; i < 5; i++) {
        try {
            std::optional<int> puesto =
                estacionamiento.asignarPuesto(llegadas[i]);

            if (puesto.has_value()) {
                std::cout << "Placa " << llegadas[i]
                          << ": puesto " << puesto.value() << std::endl;
            } else {
                std::cout << "Placa " << llegadas[i]
                          << ": sin puesto, estacionamiento lleno"
                          << std::endl;
            }

        } catch (const std::invalid_argument& e) {
            std::cout << "Placa " << llegadas[i]
                      << ": error, " << e.what() << std::endl;
        }
    }

    // Liberar el puesto del vehículo 4521
    std::optional<int> liberado = estacionamiento.liberar(4521);

    if (liberado.has_value()) {
        std::cout << "Placa 4521 sale del puesto "
                  << liberado.value() << std::endl;
    }

    // Intentar ingresar nuevamente el vehículo 9090
    std::optional<int> nuevo = estacionamiento.asignarPuesto(9090);

    if (nuevo.has_value()) {
        std::cout << "Placa 9090: puesto "
                  << nuevo.value() << std::endl;
    }

    return 0;
}

