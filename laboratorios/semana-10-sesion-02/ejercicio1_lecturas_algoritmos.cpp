#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>

int main() {
    std::vector<double> temperaturas = {
        21.5, 23.0, 19.5, 23.0, 25.5, 22.0, 18.5
    };

    
    double suma = std::accumulate(
        temperaturas.begin(), temperaturas.end(), 0.0
    );

    std::cout << "Suma: " << suma << std::endl;

    
    double maxima = *std::max_element(
        temperaturas.begin(), temperaturas.end()
    );

    std::cout << "Maxima: " << maxima << std::endl;

    
    int vecesEn23 = std::count(
        temperaturas.begin(), temperaturas.end(), 23.0
    );

    std::cout << "Dias en 23.0: " << vecesEn23 << std::endl;

    
    auto encontrado = std::find(
        temperaturas.begin(), temperaturas.end(), 25.5
    );

    int posicion = -1;

    if (encontrado != temperaturas.end()) {
        posicion = encontrado - temperaturas.begin();
    }

    if (posicion == -1) {
        std::cout << "25.5 no aparece" << std::endl;
    } else {
        std::cout << "25.5 aparece en la posicion "
                  << posicion << std::endl;
    }

    
    std::list<double> lista(
        temperaturas.begin(), temperaturas.end()
    );

    double sumaLista = std::accumulate(
        lista.begin(), lista.end(), 0.0
    );

    std::cout << "Suma (lista): "
              << sumaLista << std::endl;

    double maximaLista = *std::max_element(
        lista.begin(), lista.end()
    );

    std::cout << "Maxima (lista): "
              << maximaLista << std::endl;

    int vecesEn23Lista = std::count(
        lista.begin(), lista.end(), 23.0
    );

    std::cout << "Dias en 23.0 (lista): "
              << vecesEn23Lista << std::endl;

    // Paso 6: accumulate con valor inicial 0
    auto sumaConCero = std::accumulate(
        temperaturas.begin(), temperaturas.end(), 0
    );

    std::cout << "Suma con 0 como valor inicial: "
              << sumaConCero << std::endl;

    return 0;
}