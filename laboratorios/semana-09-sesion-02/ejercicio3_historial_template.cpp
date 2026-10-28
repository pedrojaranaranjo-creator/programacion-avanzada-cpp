#include <iostream>
#include <memory>

template <typename T>
class Historial {
    private:
        std::unique_ptr<T[]> valores;
        int capacidad;
        int usadas;

    public:
        Historial(int capacidadInicial) {
            capacidad = capacidadInicial;
            usadas = 0;
            valores = std::make_unique<T[]>(capacidad);
        }

        bool agregar(T valor) {
            if (usadas >= capacidad) {
                return false;
            }

            valores[usadas] = valor;
            usadas++;
            return true;
        }

        T obtener(int indice) {
            return valores[indice];
        }

        T ultimo() {
            return valores[usadas - 1];
        }

        int getUsadas() {
            return usadas;
        }

        int getCapacidad() {
            return capacidad;
        }
};

int main() {
    Historial<int> pasos(5);
    pasos.agregar(4200);
    pasos.agregar(1800);
    pasos.agregar(3300);

    std::cout << "Pasos guardados: " << pasos.getUsadas()
              << " de " << pasos.getCapacidad() << std::endl;
    std::cout << "Ultimo dia: " << pasos.ultimo() << std::endl;

    Historial<double> temperaturas(3);
    temperaturas.agregar(20.5);
    temperaturas.agregar(21.5);
    temperaturas.agregar(22.5);

    bool aceptada = temperaturas.agregar(23.5);

    std::cout << "Temperaturas guardadas: " << temperaturas.getUsadas()
              << " de " << temperaturas.getCapacidad() << std::endl;
    std::cout << "Agregar una cuarta temperatura: ";

    if (aceptada) {
        std::cout << "aceptado" << std::endl;
    } else {
        std::cout << "rechazado" << std::endl;
    }

    std::cout << "Primera temperatura: "
              << temperaturas.obtener(0) << std::endl;

    Historial<char> teclas(4);
    teclas.agregar('w');
    teclas.agregar('s');

    std::cout << "Teclas guardadas: " << teclas.getUsadas()
              << " de " << teclas.getCapacidad() << std::endl;
    std::cout << "Ultima tecla: " << teclas.ultimo() << std::endl;

    return 0;
}
