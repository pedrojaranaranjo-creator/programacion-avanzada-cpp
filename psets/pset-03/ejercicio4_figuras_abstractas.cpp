#include <iostream>

class Figura {
public:
    virtual ~Figura() {}

    virtual double area() = 0;
};

class Rectangulo : public Figura {
private:
    double base;
    double altura;

public:
    Rectangulo(double b, double h) {
        base = (b < 0) ? 0 : b;
        altura = (h < 0) ? 0 : h;
    }

    double area() override {
        return base * altura;
    }
};

class Triangulo : public Figura {
private:
    double base;
    double altura;

public:
    Triangulo(double b, double h) {
        base = (b < 0) ? 0 : b;
        altura = (h < 0) ? 0 : h;
    }

    double area() override {
        return base * altura / 2;
    }
};

void imprimirArea(Figura* figura) {
    std::cout << "Area: " << figura->area() << std::endl;
}

Figura* mayorArea(Figura* a, Figura* b) {
    if (a->area() >= b->area()) {
        return a;
    }

    return b;
}

int main() {
    Rectangulo rectangulo(3, 4);
    Triangulo triangulo(5, 3);
    Rectangulo invalido(-2, 6);

    imprimirArea(&rectangulo);
    imprimirArea(&triangulo);
    imprimirArea(&invalido);

    Figura* mayor = mayorArea(&triangulo, &rectangulo);
    std::cout << "La de mayor area es la figura con area "
              << mayor->area() << std::endl;

    return 0;
}

