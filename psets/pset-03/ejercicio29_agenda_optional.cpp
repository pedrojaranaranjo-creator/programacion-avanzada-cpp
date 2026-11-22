#include <iostream>
#include <map>
#include <optional>
using namespace std;

class AgendaDelConsultorio {
private:
    map<int, int> pacientePorHora;

public:

    // Consultar paciente en una hora
    optional<int> pacienteEn(int hora) {
        auto it = pacientePorHora.find(hora);

        if (it == pacientePorHora.end()) {
            return nullopt;
        }

        return it->second;
    }

    // Buscar primera hora libre
    optional<int> primeraLibreDesde(int hora) {

        if (hora < 8) {
            hora = 8;
        }

        for (int h = hora; h <= 17; h++) {
            if (pacientePorHora.find(h) == pacientePorHora.end()) {
                return h;
            }
        }

        return nullopt;
    }

    // Agendar paciente
    optional<int> agendar(int paciente, int desde) {

        optional<int> hora = primeraLibreDesde(desde);

        if (!hora.has_value()) {
            return nullopt;
        }

        pacientePorHora[*hora] = paciente;

        return hora;
    }

    // Cancelar una cita
    bool cancelar(int hora) {

        auto it = pacientePorHora.find(hora);

        if (it == pacientePorHora.end()) {
            return false;
        }

        pacientePorHora.erase(it);

        return true;
    }
};

int main() {

    AgendaDelConsultorio agenda;

    // Agendar pacientes
    optional<int> h1 = agenda.agendar(501, 8);
    optional<int> h2 = agenda.agendar(502, 8);
    optional<int> h3 = agenda.agendar(503, 16);
    optional<int> h4 = agenda.agendar(504, 16);
    optional<int> h5 = agenda.agendar(504, 16);

    // Imprimir horas asignadas
    cout << "Paciente 501: ";
    if (h1.has_value()) cout << *h1 << endl;
    else cout << "sin hora" << endl;

    cout << "Paciente 502: ";
    if (h2.has_value()) cout << *h2 << endl;
    else cout << "sin hora" << endl;

    cout << "Paciente 503: ";
    if (h3.has_value()) cout << *h3 << endl;
    else cout << "sin hora" << endl;

    cout << "Paciente 504: ";
    if (h4.has_value()) cout << *h4 << endl;
    else cout << "sin hora" << endl;

    cout << "Paciente 504 otra vez: ";
    if (h5.has_value()) cout << *h5 << endl;
    else cout << "sin hora" << endl;

    // Consultar pacientes
    cout << "A las 9: ";

    if (agenda.pacienteEn(9).has_value()) {
        cout << *agenda.pacienteEn(9) << endl;
    }

    cout << "A las 12: "
         << agenda.pacienteEn(12).value_or(0) << endl;

    // Uso de value() y captura de excepciones
    try {
        cout << agenda.pacienteEn(13).value() << endl;
    }
    catch (const bad_optional_access& e) {
        cout << "Nadie a las 13" << endl;
    }

    // Cancelar cita de las 8
    agenda.cancelar(8);

    // Agendar paciente 505 desde las 7
    optional<int> h6 = agenda.agendar(505, 7);

    cout << "Paciente 505: ";

    if (h6.has_value()) {
        cout << *h6 << endl;
    }
    else {
        cout << "sin hora" << endl;
    }

    return 0;
}

