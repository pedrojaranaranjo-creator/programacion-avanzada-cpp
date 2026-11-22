#include <iostream>
#include <vector>
using namespace std;

class HistorialDePasos {
private:
    vector<int> pasos;

public:
    // Registrar pasos
    bool registrar(int cantidad) {
        if (cantidad < 0) {
            return false;
        }

        pasos.push_back(cantidad);
        return true;
    }

    // Cantidad de dias registrados
    int dias() {
        return pasos.size();
    }

    // Calcular promedio
    double promedio() {
        if (pasos.empty()) {
            return 0;
        }

        int suma = 0;

        for (int i = 0; i < pasos.size(); i++) {
            suma += pasos[i];
        }

        return static_cast<double>(suma) / pasos.size();
    }

    // Contar dias que llegaron a la meta
    int diasSobreMeta(int meta) {
        int contador = 0;

        for (int i = 0; i < pasos.size(); i++) {
            if (pasos[i] >= meta) {
                contador++;
            }
        }

        return contador;
    }

    // Calcular la mejor racha consecutiva
    int mejorRacha(int meta) {
        int rachaActual = 0;
        int mejor = 0;

        for (int i = 0; i < pasos.size(); i++) {
            if (pasos[i] >= meta) {
                rachaActual++;

                if (rachaActual > mejor) {
                    mejor = rachaActual;
                }
            } else {
                rachaActual = 0;
            }
        }

        return mejor;
    }
};

int main() {

    HistorialDePasos historial;

    historial.registrar(8000);
    historial.registrar(12000);
    historial.registrar(10500);

    cout << "Registrar -50: "
         << historial.registrar(-50) << endl;

    historial.registrar(4000);
    historial.registrar(11000);
    historial.registrar(13000);
    historial.registrar(9999);
    historial.registrar(10000);

    int meta = 10000;

    cout << "Dias registrados: "
         << historial.dias() << endl;

    cout << "Promedio: "
         << historial.promedio() << endl;

    cout << "Dias con meta: "
         << historial.diasSobreMeta(meta) << endl;

    cout << "Mejor racha: "
         << historial.mejorRacha(meta) << endl;

    return 0;
}

