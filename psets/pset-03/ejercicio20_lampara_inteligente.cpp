
#include <iostream>
using namespace std;

// Primera interfaz
class Encendible {
public:
    virtual ~Encendible() {}
    virtual void encender() = 0;
    virtual void apagar() = 0;
    virtual bool estaEncendido() = 0;
};

// Segunda interfaz
class Regulable {
public:
    virtual ~Regulable() {}
    virtual int nivel() = 0;
    virtual void subir() = 0;
    virtual void bajar() = 0;
};

// Clase que implementa las dos interfaces
class LamparaInteligente : public Encendible, public Regulable {
private:
    bool encendida;
    int brillo;

public:
    LamparaInteligente() {
        encendida = false;
        brillo = 0;
    }

    void encender() override {
        encendida = true;

        if (brillo == 0) {
            brillo = 5;
        }
    }

    void apagar() override {
        encendida = false;
        brillo = 0;
    }

    bool estaEncendido() override {
        return encendida;
    }

    int nivel() override {
        return brillo;
    }

    void subir() override {
        if (encendida && brillo < 10) {
            brillo++;
        }
    }

    void bajar() override {
        if (encendida && brillo > 1) {
            brillo--;
        }
    }
};

// Funciones libres
void subirAlMaximo(Regulable* r) {
    while (r->nivel() < 10) {
        r->subir();
    }
}

void apagarSiEstaEncendido(Encendible* e) {
    if (e->estaEncendido()) {
        e->apagar();
    }
}

int main() {
    LamparaInteligente lampara;

    Encendible* interruptor = &lampara;
    Regulable* regulador = &lampara;

    cout << boolalpha;

    cout << "Encendida al inicio: "
         << interruptor->estaEncendido() << endl;

    regulador->subir();

    cout << "Nivel tras subir apagada: "
         << regulador->nivel() << endl;

    interruptor->encender();

    cout << "Nivel al encender: "
         << regulador->nivel() << endl;

    subirAlMaximo(regulador);

    cout << "Nivel al maximo: "
         << regulador->nivel() << endl;

    regulador->bajar();

    cout << "Nivel tras bajar: "
         << regulador->nivel() << endl;

    apagarSiEstaEncendido(interruptor);

    cout << "Encendida al final: "
         << interruptor->estaEncendido() << endl;

    cout << "Nivel al final: "
         << regulador->nivel() << endl;

    return 0;
}

