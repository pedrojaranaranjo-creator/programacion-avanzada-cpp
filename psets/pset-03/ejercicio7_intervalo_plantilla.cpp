#include <iostream>

template <typename T>
class Intervalo {
private:
    T inicio;
    T fin;

public:
    Intervalo(T a, T b) {
        if (a <= b) {
            inicio = a;
            fin = b;
        } else {
            inicio = b;
            fin = a;
        }
    }

    T getInicio() {
        return inicio;
    }

    T getFin() {
        return fin;
    }

    T ancho() {
        return fin - inicio;
    }

    bool contiene(T valor) {
        return valor >= inicio && valor <= fin;
    }

    bool seCruzaCon(Intervalo<T> otro) {
        return inicio <= otro.fin && otro.inicio <= fin;
    }
};

int main() {
    Intervalo<int> horario(17, 8);

    std::cout << "Horario: " << horario.getInicio()
              << " a " << horario.getFin()
              << ", ancho " << horario.ancho() << std::endl;

    std::cout << "Contiene 12: " << horario.contiene(12) << std::endl;
    std::cout << "Contiene 18: " << horario.contiene(18) << std::endl;

    Intervalo<double> temperatura(15.5, 24.0);

    std::cout << "Temperatura: " << temperatura.getInicio()
              << " a " << temperatura.getFin()
              << ", ancho " << temperatura.ancho() << std::endl;

    std::cout << "Contiene 15.5: "
              << temperatura.contiene(15.5) << std::endl;

    Intervalo<int> almuerzo(12, 14);
    Intervalo<int> noche(19, 22);

    std::cout << "Se cruzan: "
              << horario.seCruzaCon(almuerzo) << std::endl;

    std::cout << "Se cruzan: "
              << horario.seCruzaCon(noche) << std::endl;

    return 0;
}
