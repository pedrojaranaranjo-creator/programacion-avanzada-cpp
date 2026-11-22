#include <iostream>
#include <list>
#include <set>
using namespace std;

class ListaDeReproduccion {
private:
    list<int> pendientes;
    set<int> reproducidas;

public:
    // Agregar cancion al final
    void agregarAlFinal(int id) {
        pendientes.push_back(id);
    }

    // Agregar cancion al principio
    void agregarSiguiente(int id) {
        pendientes.push_front(id);
    }

    // Reproducir primera cancion
    int reproducir() {
        if (pendientes.empty()) {
            return -1;
        }

        int id = pendientes.front();

        pendientes.pop_front();

        reproducidas.insert(id);

        return id;
    }

    // Comprobar si una cancion ya sono
    bool yaSono(int id) {
        return reproducidas.find(id) != reproducidas.end();
    }

    // Quitar todas las apariciones de una cancion
    int quitarTodas(int id) {
        int contador = 0;

        auto it = pendientes.begin();

        while (it != pendientes.end()) {
            if (*it == id) {
                it = pendientes.erase(it);
                contador++;
            } else {
                it++;
            }
        }

        return contador;
    }

    // Cantidad de canciones pendientes
    int pendientesPorSonar() {
        return pendientes.size();
    }
};

int main() {

    ListaDeReproduccion lista;

    // Agregar canciones al final
    lista.agregarAlFinal(11);
    lista.agregarAlFinal(22);
    lista.agregarAlFinal(11);
    lista.agregarAlFinal(33);

    // Agregar cancion siguiente
    lista.agregarSiguiente(44);

    // Reproducir dos canciones
    cout << "Suena: " << lista.reproducir() << endl;
    cout << "Suena: " << lista.reproducir() << endl;

    // Quitar todas las apariciones de la cancion 11
    cout << "Quitadas: " << lista.quitarTodas(11) << endl;

    // Consultar pendientes
    cout << "Pendientes: "
         << lista.pendientesPorSonar() << endl;

    // Consultar si ya sonaron
    cout << "La 44 ya sono: "
         << lista.yaSono(44) << endl;

    cout << "La 33 ya sono: "
         << lista.yaSono(33) << endl;

    // Reproducir dos canciones mas
    cout << "Suena: " << lista.reproducir() << endl;
    cout << "Suena: " << lista.reproducir() << endl;

    return 0;
}

