#include <iostream>

class Instrumento {
public:
    virtual ~Instrumento() {}

    virtual int notasPorMinuto() {
        return 60;
    }

    int volumen() {
        return 5;
    }
};

class Guitarra : public Instrumento {
private:
    int cuerdas;

public:
    Guitarra(int c) {
        cuerdas = c;
    }

    int notasPorMinuto() override {
        return cuerdas * 20;
    }

    int volumen() {
        return 8;
    }
};

class Bateria : public Instrumento {
private:
    int tambores;

public:
    Bateria(int t) {
        tambores = t;
    }

    int notasPorMinuto() override {
        return tambores * 30;
    }
};

int main() {
    Guitarra guitarra(6);
    Bateria bateria(5);

    Instrumento* instrumento = &guitarra;

    std::cout << "Guitarra por puntero, notas por minuto: "
              << instrumento->notasPorMinuto() << std::endl;

    std::cout << "Guitarra por puntero, volumen: "
              << instrumento->volumen() << std::endl;

    std::cout << "Guitarra directa, volumen: "
              << guitarra.volumen() << std::endl;

    instrumento = &bateria;

    std::cout << "Bateria por puntero, notas por minuto: "
              << instrumento->notasPorMinuto() << std::endl;

    return 0;
}

