#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

bool esLenta(int milisegundos) {
    return milisegundos > 100;
}

bool contiene(std::vector<int> tiempos, int valor) {
    // Busca el valor y comprueba si fue encontrado.
    return std::find(tiempos.begin(), tiempos.end(), valor) != tiempos.end();
}

int posicionDe(std::vector<int> tiempos, int valor) {
    // Busca el valor.
    auto resultado = std::find(tiempos.begin(), tiempos.end(), valor);

    // Si no existe, devuelve -1.
    if (resultado == tiempos.end()) {
        return -1;
    }

    // Calcula la posicion.
    return resultado - tiempos.begin();
}

int vecesQueAparece(std::vector<int> tiempos, int valor) {
    return std::count(tiempos.begin(), tiempos.end(), valor);
}

int maximo(std::vector<int> tiempos) {
    // Comprueba si el vector esta vacio.
    if (tiempos.empty()) {
        return 0;
    }

    auto resultado = std::max_element(tiempos.begin(), tiempos.end());

    return *resultado;
}

int cuantasLentas(std::vector<int> tiempos) {
    return std::count_if(tiempos.begin(), tiempos.end(), esLenta);
}

int total(std::vector<int> tiempos) {
    return std::accumulate(tiempos.begin(), tiempos.end(), 0);
}

std::vector<int> ordenados(std::vector<int> tiempos) {
    std::sort(tiempos.begin(), tiempos.end());
    return tiempos;
}

int main() {
    std::vector<int> tiempos = {120, 40, 15, 90, 210, 40, 65, 165, 125};

    std::cout << "Hay un tiempo de 90: " << contiene(tiempos, 90) << std::endl;
    std::cout << "Posicion del primer 90: " << posicionDe(tiempos, 90) << std::endl;
    std::cout << "Hay un tiempo de 55: " << contiene(tiempos, 55) << std::endl;
    std::cout << "Veces que aparece 40: " << vecesQueAparece(tiempos, 40) << std::endl;
    std::cout << "Tiempo maximo: " << maximo(tiempos) << std::endl;
    std::cout << "Respuestas lentas: " << cuantasLentas(tiempos) << std::endl;
    std::cout << "Total: " << total(tiempos) << std::endl;

    std::vector<int> enOrden = ordenados(tiempos);
    std::cout << "Ordenados:";
    for (int t : enOrden) {
        std::cout << " " << t;
    }
    std::cout << std::endl;
    return 0;
}

