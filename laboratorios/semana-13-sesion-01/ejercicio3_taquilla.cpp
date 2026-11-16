#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// Clase Taquilla
class Taquilla {
private:
    std::vector<int> asientos;
    std::mutex mtx;

public:
    // Constructor: todos los asientos empiezan libres
    Taquilla(int cantidad) {
        asientos.resize(cantidad, 0);
    }

    // Reservar un asiento
    bool reservar(int asiento, int comprador) {
        std::lock_guard<std::mutex> lock(mtx);

        if (asiento < 0 || asiento >= (int)asientos.size()) {
            return false;
        }

        if (asientos[asiento] != 0) {
            return false;
        }

        asientos[asiento] = comprador;
        return true;
    }

    // Reservar dos asientos juntos
    bool reservarPar(int a, int b, int comprador) {
        std::lock_guard<std::mutex> lock(mtx);

        if (a < 0 || a >= (int)asientos.size() ||
            b < 0 || b >= (int)asientos.size()) {
            return false;
        }

        if (asientos[a] != 0 || asientos[b] != 0) {
            return false;
        }

        asientos[a] = comprador;
        asientos[b] = comprador;

        return true;
    }

    // Consultar dueño de un asiento
    int duenoDe(int asiento) {
        std::lock_guard<std::mutex> lock(mtx);

        if (asiento < 0 || asiento >= (int)asientos.size()) {
            return 0;
        }

        return asientos[asiento];
    }

    // Contar asientos vendidos
    int vendidos() {
        std::lock_guard<std::mutex> lock(mtx);

        int total = 0;

        for (int i = 0; i < (int)asientos.size(); i++) {
            if (asientos[i] != 0) {
                total++;
            }
        }

        return total;
    }
};

// Vendedor individual
void vendedor(Taquilla* taquilla, int comprador, int* logradas) {
    for (int asiento = 0; asiento < 20000; asiento++) {
        if (taquilla->reservar(asiento, comprador)) {
            *logradas = *logradas + 1;
        }
    }
}

// Vendedor de pares
void vendedorDePares(Taquilla* taquilla, int comprador, int* logradas) {
    for (int asiento = 0; asiento < 20000; asiento = asiento + 2) {
        if (taquilla->reservarPar(asiento, asiento + 1, comprador)) {
            *logradas = *logradas + 2;
        }
    }
}

int main() {
    Taquilla taquilla(20000);
    int logradas[5] = {0, 0, 0, 0, 0};

    std::thread v1(vendedor, &taquilla, 1, &logradas[0]);
    std::thread v2(vendedor, &taquilla, 2, &logradas[1]);
    std::thread v3(vendedor, &taquilla, 3, &logradas[2]);
    std::thread v4(vendedor, &taquilla, 4, &logradas[3]);
    std::thread v5(vendedorDePares, &taquilla, 5, &logradas[4]);

    v1.join();
    v2.join();
    v3.join();
    v4.join();
    v5.join();

    int total = 0;
    for (int i = 0; i < 5; i++) {
        total = total + logradas[i];
    }

    int aMedias = 0;
    for (int asiento = 0; asiento < 20000; asiento = asiento + 2) {
        bool primero = taquilla.duenoDe(asiento) == 5;
        bool segundo = taquilla.duenoDe(asiento + 1) == 5;

        if (primero != segundo) {
            aMedias = aMedias + 1;
        }
    }

    std::cout << "Reservas aceptadas: " << total << std::endl;
    std::cout << "Asientos vendidos: " << taquilla.vendidos() << std::endl;
    std::cout << "Pares a medias: " << aMedias << std::endl;

    return 0;
}

