#include <iostream>
using namespace std;

class Envio {
public:
    virtual ~Envio() {}

    virtual double costo() = 0;
};

class EnvioNacional : public Envio {
private:
    double pesoKg;

public:
    EnvioNacional(double peso) {
        if (peso < 0) {
            pesoKg = 0;
        } else {
            pesoKg = peso;
        }
    }

    double costo() override {
        return 2 + 1.5 * pesoKg;
    }
};

class EnvioInternacional : public Envio {
private:
    double pesoKg;

public:
    EnvioInternacional(double peso) {
        if (peso < 0) {
            pesoKg = 0;
        } else {
            pesoKg = peso;
        }
    }

    double costo() override {
        return 10 + 4 * pesoKg;
    }
};

void imprimirCosto(Envio* envio) {
    cout << "Costo: " << envio->costo() << endl;
}

Envio* masBarato(Envio* a, Envio* b) {
    if (a->costo() <= b->costo()) {
        return a;
    }

    return b;
}

int main() {
    EnvioNacional nacional(3);
    EnvioInternacional internacional(0.5);
    EnvioNacional nacionalNegativo(-4);

    imprimirCosto(&nacional);
    imprimirCosto(&internacional);
    imprimirCosto(&nacionalNegativo);

    Envio* barato = masBarato(&nacional, &internacional);

    cout << "El mas barato cuesta " << barato->costo() << endl;

    return 0;
}

