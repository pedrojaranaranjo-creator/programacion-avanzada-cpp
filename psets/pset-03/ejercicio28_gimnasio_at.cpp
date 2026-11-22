#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>
using namespace std;

class Gimnasio {
private:
    vector<int> cuposPorHorario;
    map<int, double> precioPorPlan;

public:
    // Constructor
    Gimnasio() {
        cuposPorHorario = {12, 0, 6, 20, 3};

        precioPorPlan[1] = 30;
        precioPorPlan[2] = 45;
        precioPorPlan[3] = 60;
    }

    // Consultar cupos
    int cuposEn(int horario) {
        return cuposPorHorario.at(horario);
    }

    // Consultar precio
    double precioDe(int plan) {
        return precioPorPlan.at(plan);
    }

    // Inscribir personas
    double inscribir(int horario, int plan, int personas) {

        int cupos = cuposEn(horario);
        double precio = precioDe(plan);

        if (personas <= 0) {
            throw invalid_argument("personas no positivas");
        }

        if (personas > cupos) {
            throw runtime_error("sin cupos");
        }

        cuposPorHorario.at(horario) -= personas;

        return personas * precio;
    }
};

// Funcion libre para atender solicitudes
void atender(Gimnasio* gimnasio, int horario, int plan, int personas) {

    try {
        double total = gimnasio->inscribir(horario, plan, personas);

        cout << "Inscritas " << personas
             << " personas, total " << total << endl;
    }
    catch (const out_of_range& e) {
        cout << "Rechazada: horario o plan inexistente" << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Rechazada: " << e.what() << endl;
    }
    catch (const runtime_error& e) {
        cout << "Rechazada: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Rechazada: error inesperado" << endl;
    }
}

int main() {

    Gimnasio gimnasio;

    // Atender solicitudes
    atender(&gimnasio, 0, 2, 4);
    atender(&gimnasio, 1, 1, 1);
    atender(&gimnasio, 9, 1, 1);
    atender(&gimnasio, 3, 5, 2);
    atender(&gimnasio, 2, 3, -1);
    atender(&gimnasio, 2, 3, 6);
    atender(&gimnasio, 2, 3, 1);

    // Consultar cupos restantes
    cout << "Cupos en el horario 0: "
         << gimnasio.cuposEn(0) << endl;

    cout << "Cupos en el horario 2: "
         << gimnasio.cuposEn(2) << endl;

    return 0;
}

