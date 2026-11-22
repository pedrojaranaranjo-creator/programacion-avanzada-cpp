#include <iostream>
using namespace std;

class Vehiculo {
private:
    double tarifaBase;

public:
    Vehiculo() {
        tarifaBase = 0;
    }

    void setTarifaBase(double t) {
        tarifaBase = t;
    }

    double getTarifaBase() {
        return tarifaBase;
    }

    virtual ~Vehiculo() {}

    virtual double peaje() {
        return tarifaBase;
    }
};

class Camion : public Vehiculo {
private:
    int ejes;

public:
    Camion(double tarifa, int e) {
        setTarifaBase(tarifa);
        ejes = e;
    }

    double peaje() override {
        return getTarifaBase() + 1.5 * ejes;
    }
};

class Bus : public Vehiculo {
private:
    int pasajeros;

public:
    Bus(double tarifa, int p) {
        setTarifaBase(tarifa);
        pasajeros = p;
    }

    double peaje() override {
        if (pasajeros > 30) {
            return getTarifaBase() * 2;
        }

        return getTarifaBase();
    }
};

double recaudacion(Vehiculo* fila[], int cantidad) {
    double total = 0;

    for (int i = 0; i < cantidad; i++) {
        total += fila[i]->peaje();
    }

    return total;
}

int main() {
    Vehiculo vehiculo;
    vehiculo.setTarifaBase(1);

    Camion camion(2, 4);

    Bus bus1(2, 45);

    Bus bus2(2, 12);

    Vehiculo* fila[4] = {
        &vehiculo,
        &camion,
        &bus1,
        &bus2
    };

    for (int i = 0; i < 4; i++) {
        cout << "Vehiculo " << i << " paga: "
             << fila[i]->peaje() << endl;
    }

    cout << "Recaudacion: "
         << recaudacion(fila, 4) << endl;

    return 0;
}

