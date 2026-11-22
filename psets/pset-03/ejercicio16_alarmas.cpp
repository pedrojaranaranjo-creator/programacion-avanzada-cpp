#include <iostream>
using namespace std;

class Alarma {
public:
    virtual ~Alarma() {}

    virtual int segundosDeAviso() {
        return 10;
    }

    int prioridad() {
        return 1;
    }
};

class AlarmaDeIncendio : public Alarma {
private:
    int pisos;

public:
    AlarmaDeIncendio(int p) {
        pisos = p;
    }

    int segundosDeAviso() override {
        return pisos * 15;
    }

    int prioridad() {
        return 3;
    }
};

class AlarmaDeIntrusion : public Alarma {
private:
    int sensores;

public:
    AlarmaDeIntrusion(int s) {
        sensores = s;
    }

    int segundosDeAviso() override {
        return sensores * 4;
    }
};

int main() {
    AlarmaDeIncendio incendio(4);
    AlarmaDeIntrusion intrusion(9);

    Alarma* alarma = &incendio;

    cout << "Incendio por puntero, aviso: "
         << alarma->segundosDeAviso() << endl;

    cout << "Incendio por puntero, prioridad: "
         << alarma->prioridad() << endl;

    cout << "Incendio directa, prioridad: "
         << incendio.prioridad() << endl;

    alarma = &intrusion;

    cout << "Intrusion por puntero, aviso: "
         << alarma->segundosDeAviso() << endl;

    Alarma comun;

    alarma = &comun;

    cout << "Alarma comun por puntero, aviso: "
         << alarma->segundosDeAviso() << endl;

    return 0;
}

