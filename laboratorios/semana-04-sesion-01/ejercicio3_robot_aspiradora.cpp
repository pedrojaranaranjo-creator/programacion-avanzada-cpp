#include <iostream>

class DispositivoElectronico {
    private:
        int numeroSerie;
        bool encendido;
    public:
        DispositivoElectronico() {
            numeroSerie = 0;
            encendido = false;
        }

        bool setNumeroSerie(int nuevoNumero) {
            if (nuevoNumero <= 0) { return false; }
            numeroSerie = nuevoNumero;
            return true;
        }

        void encender() {
            encendido = true;
        }

        void apagar() {
            encendido = false;
        }

        void describir() {
            std::cout << "Dispositivo #" << numeroSerie << ", encendido: " << (encendido ? "si" : "no") << std::endl;
        }
};

class RobotAspiradora: public DispositivoElectronico {
    public:
        void aspirar() {
            std::cout << "Aspirando el polvo del piso" << std::endl;
        }

        void moverse(int distanciaCm) {
            std::cout << "Moviendose " << distanciaCm << " cm hacia adelante" << std::endl;
        }
};

int main() {
    RobotAspiradora r;
    r.setNumeroSerie(77);
    r.encender();
    r.describir();
    r.aspirar();
    r.moverse(150);
    return 0;
}