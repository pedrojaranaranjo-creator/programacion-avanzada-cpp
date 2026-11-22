#include <iostream>
#include <stdexcept>
using namespace std;

class Ascensor {
private:
    int pisoActual;
    double cargaKg;

public:
    // Constructor
    Ascensor() {
        pisoActual = 0;
        cargaKg = 0;
    }

    // Subir una persona
    void subirPersona(double kg) {
        if (kg <= 0) {
            throw invalid_argument("peso no positivo");
        }

        if (cargaKg + kg > 450) {
            throw runtime_error("sobrecarga");
        }

        cargaKg += kg;
    }

    // Bajar una persona
    void bajarPersona(double kg) {
        if (kg <= 0) {
            throw invalid_argument("peso no positivo");
        }

        if (kg > cargaKg) {
            throw runtime_error("no hay tanto peso a bordo");
        }

        cargaKg -= kg;
    }

    // Cambiar de piso
    void irA(int piso) {
        if (piso < 0 || piso > 10) {
            throw out_of_range("piso inexistente");
        }

        pisoActual = piso;
    }

    // Obtener piso actual
    int getPiso() {
        return pisoActual;
    }

    // Obtener carga actual
    double getCarga() {
        return cargaKg;
    }
};

int main() {

    Ascensor ascensor;

    // 1. Subir personas
    try {
        ascensor.subirPersona(80);
        ascensor.subirPersona(95);
        ascensor.subirPersona(120);

        cout << "Carga: " << ascensor.getCarga() << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // 2. Intentar sobrecargar el ascensor
    try {
        ascensor.subirPersona(200);
        ascensor.irA(7);
    }
    catch (const runtime_error& e) {
        cout << "No se pudo: " << e.what() << endl;
    }

    cout << "Piso actual: " << ascensor.getPiso() << endl;

    // 3. Intentar ir a un piso inexistente
    try {
        ascensor.irA(12);
    }
    catch (const out_of_range& e) {
        cout << "Fuera de rango: " << e.what() << endl;
    }

    // 4. Intentar bajar un peso negativo
    try {
        ascensor.bajarPersona(-60);
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // 5. Ir al piso 4
    ascensor.irA(4);

    cout << "Piso " << ascensor.getPiso()
         << ", carga " << ascensor.getCarga() << endl;

    return 0;
}

