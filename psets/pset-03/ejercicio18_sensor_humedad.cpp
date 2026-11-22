#include <iostream>
#include <memory>
using namespace std;

class Sensor {
public:
    virtual ~Sensor() {
        cout << "Sensor apagado" << endl;
    }

    virtual double promedio() {
        return 0;
    }
};

class SensorDeHumedad : public Sensor {
private:
    double* lecturas;

public:
    SensorDeHumedad(double a, double b, double c) {
        lecturas = new double[3];

        lecturas[0] = a;
        lecturas[1] = b;
        lecturas[2] = c;
    }

    ~SensorDeHumedad() override {
        delete[] lecturas;
        cout << "Lecturas liberadas" << endl;
    }

    double promedio() override {
        return (lecturas[0] + lecturas[1] + lecturas[2]) / 3.0;
    }
};

int main() {
    {
        unique_ptr<Sensor> sensor =
            make_unique<SensorDeHumedad>(60, 72, 81);

        cout << "Humedad promedio: "
             << sensor->promedio() << endl;
    }

    cout << "Fin del programa" << endl;

    return 0;
}

