#include <iostream>
#include <map>

class ContadorDeVisitas {
private:
    std::map<int, int> visitasPorSala;

public:
    void registrar(int sala) {
        visitasPorSala[sala]++;
    }

    int visitasDe(int sala) {
        if (visitasPorSala.count(sala) == 0) {
            return 0;
        }

        return visitasPorSala[sala];
    }

    int cantidadDeSalas() {
        return visitasPorSala.size();
    }

    void imprimir() {
        for (auto it = visitasPorSala.begin();
             it != visitasPorSala.end(); it++) {

            std::cout << "Sala " << it->first
                      << ": " << it->second << std::endl;
        }
    }

    int masVisitada() {
        if (visitasPorSala.empty()) {
            return -1;
        }

        int salaMayor = visitasPorSala.begin()->first;
        int mayor = visitasPorSala.begin()->second;

        for (auto it = visitasPorSala.begin();
             it != visitasPorSala.end(); it++) {

            if (it->second > mayor) {
                mayor = it->second;
                salaMayor = it->first;
            }
        }

        return salaMayor;
    }
};

int main() {
    ContadorDeVisitas contador;

    contador.registrar(204);
    contador.registrar(310);
    contador.registrar(204);
    contador.registrar(101);
    contador.registrar(310);
    contador.registrar(204);

    std::cout << "Visitas a la sala 204: "
              << contador.visitasDe(204) << std::endl;

    std::cout << "Visitas a la sala 999: "
              << contador.visitasDe(999) << std::endl;

    std::cout << "Salas registradas: "
              << contador.cantidadDeSalas() << std::endl;

    contador.imprimir();

    std::cout << "Sala mas visitada: "
              << contador.masVisitada() << std::endl;

    return 0;
}

