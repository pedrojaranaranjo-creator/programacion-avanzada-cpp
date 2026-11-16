
#pragma once

#include <vector>

// Calcula los minutos necesarios para imprimir.
int minutosDeImpresion(int paginas) {
    return (paginas + 9) / 10;
}

class ColaDeImpresion {
private:
    std::vector<int> trabajos;

public:
    // Agregar un trabajo al final.
    void agregar(int paginas) {
        trabajos.push_back(paginas);
    }

    // Cantidad de trabajos.
    int cantidad() {
        return trabajos.size();
    }

    // Obtener paginas de una posicion.
    int paginasDe(int posicion) {
        return trabajos.at(posicion);
    }

    // Dividir trabajos grandes.
    void dividirGrandes() {
        std::vector<int> nuevos;

        for (int i = 0; i < trabajos.size(); i++) {

            int paginas = trabajos[i];

            while (paginas > 20) {
                nuevos.push_back(paginas - 20);
                paginas = 20;
            }

            trabajos[i] = paginas;
        }

        // Agregar los trabajos restantes al final.
        for (int i = 0; i < nuevos.size(); i++) {
            trabajos.push_back(nuevos[i]);
        }
    }

    // Sumar los minutos de todos los trabajos.
    int minutosTotales() {
        int total = 0;

        for (int i = 0; i < cantidad(); i++) {
            total = total + minutosDeImpresion(trabajos[i]);
        }

        return total;
    }
};

