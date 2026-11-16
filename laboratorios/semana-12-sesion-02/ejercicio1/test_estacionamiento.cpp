
#ifndef ESTACIONAMIENTO_H
#define ESTACIONAMIENTO_H

#include <vector>
#include <optional>
#include <stdexcept>

class Estacionamiento {
private:
    std::vector<std::optional<int>> puestos;

public:
    Estacionamiento(int capacidad) {
        puestos.resize(capacidad);
    }

    std::optional<int> asignarPuesto(int placa) {

        // Comprobar si la placa ya está registrada.
        for (int i = 0; i < puestos.size(); i++) {
            if (puestos[i].has_value() &&
                puestos[i].value() == placa) {
                throw std::invalid_argument("Placa repetida");
            }
        }

        // Buscar el primer puesto disponible.
        for (int i = 0; i < puestos.size(); i++) {
            if (!puestos[i].has_value()) {
                puestos[i] = placa;
                return i;
            }
        }

        // Si todos los puestos están ocupados.
        return std::nullopt;
    }

    void liberar(int placa) {

        // Buscar la placa y liberar su puesto.
        for (int i = 0; i < puestos.size(); i++) {
            if (puestos[i].has_value() &&
                puestos[i].value() == placa) {
                puestos[i] = std::nullopt;
                return;
            }
        }
    }
};

#endif
