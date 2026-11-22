#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include <optional>
#include <stdexcept>
#include <utility>
using namespace std;

// Clase abstracta Producto
class Producto {
private:
    int codigo;
    double precio;

public:
    void setDatos(int c, double p) {
        codigo = c;
        precio = p;
    }

    int getCodigo() {
        return codigo;
    }

    double getPrecio() {
        return precio;
    }

    virtual ~Producto() {}

    virtual double precioFinal() = 0;
};

// Producto normal
class ProductoNormal : public Producto {
public:
    ProductoNormal(int codigo, double precio) {
        setDatos(codigo, precio);
    }

    double precioFinal() override {
        return getPrecio();
    }
};

// Producto en oferta
class ProductoEnOferta : public Producto {
private:
    double porcentaje;

public:
    ProductoEnOferta(int codigo, double precio, double porcentaje) {
        setDatos(codigo, precio);
        this->porcentaje = porcentaje;
    }

    double precioFinal() override {
        return getPrecio() * (1 - porcentaje / 100);
    }
};

// Producto vendido por peso
class ProductoPorPeso : public Producto {
private:
    double kilos;

public:
    ProductoPorPeso(int codigo, double precioPorKilo, double kilos) {
        setDatos(codigo, precioPorKilo);
        this->kilos = kilos;
    }

    double precioFinal() override {
        return getPrecio() * kilos;
    }
};

// Plantilla para encontrar el mayor valor
template <typename T>
T mayorDe(vector<T> valores) {

    if (valores.empty()) {
        return T();
    }

    return *max_element(valores.begin(), valores.end());
}

// Clase Tienda
class Tienda {
private:
    vector<unique_ptr<Producto>> productos;

public:

    // Agregar producto
    void agregar(unique_ptr<Producto> producto) {

        if (producto->getPrecio() <= 0) {
            throw invalid_argument("precio no positivo");
        }

        for (int i = 0; i < static_cast<int>(productos.size()); i++) {
            if (productos[i]->getCodigo() == producto->getCodigo()) {
                throw invalid_argument("codigo repetido");
            }
        }

        productos.push_back(move(producto));
    }

    // Cantidad de productos
    int cantidad() {
        return static_cast<int>(productos.size());
    }

    // Buscar precio final por codigo
    optional<double> precioDe(int codigo) {

        for (int i = 0; i < static_cast<int>(productos.size()); i++) {
            if (productos[i]->getCodigo() == codigo) {
                return productos[i]->precioFinal();
            }
        }

        return nullopt;
    }

    // Obtener todos los precios finales
    vector<double> preciosFinales() {

        vector<double> precios;

        for (int i = 0; i < static_cast<int>(productos.size()); i++) {
            precios.push_back(productos[i]->precioFinal());
        }

        return precios;
    }

    // Sumar todos los precios
    double total() {
        vector<double> precios = preciosFinales();

        return accumulate(precios.begin(), precios.end(), 0.0);
    }

    // Contar productos debajo de un limite
    int cuantosBajo(double limite) {

        vector<double> precios = preciosFinales();

        return static_cast<int>(
            count_if(precios.begin(), precios.end(),
                [limite](double precio) {
                    return precio < limite;
                })
        );
    }

    // Codigo del producto mas caro
    optional<int> codigoMasCaro() {

        if (productos.empty()) {
            return nullopt;
        }

        int posicionMayor = 0;

        for (int i = 1; i < static_cast<int>(productos.size()); i++) {
            if (productos[i]->precioFinal() >
                productos[posicionMayor]->precioFinal()) {

                posicionMayor = i;
            }
        }

        return productos[posicionMayor]->getCodigo();
    }
};

int main() {

    Tienda tienda;

    // Agregar producto normal 101
    try {
        tienda.agregar(make_unique<ProductoNormal>(101, 2.5));
    }
    catch (const invalid_argument& e) {
        cout << "No se agrego: " << e.what() << endl;
    }

    // Agregar producto en oferta 205
    try {
        tienda.agregar(make_unique<ProductoEnOferta>(205, 10, 20));
    }
    catch (const invalid_argument& e) {
        cout << "No se agrego: " << e.what() << endl;
    }

    // Agregar producto por peso 310
    try {
        tienda.agregar(make_unique<ProductoPorPeso>(310, 4, 1.5));
    }
    catch (const invalid_argument& e) {
        cout << "No se agrego: " << e.what() << endl;
    }

    // Intentar agregar codigo repetido
    try {
        tienda.agregar(make_unique<ProductoNormal>(101, 3));
    }
    catch (const invalid_argument& e) {
        cout << "No se agrego: " << e.what() << endl;
    }

    // Intentar agregar precio no positivo
    try {
        tienda.agregar(make_unique<ProductoNormal>(400, 0));
    }
    catch (const invalid_argument& e) {
        cout << "No se agrego: " << e.what() << endl;
    }

    // Mostrar resultados
    cout << "Productos: " << tienda.cantidad() << endl;

    cout << "Total: " << tienda.total() << endl;

    cout << "Cuestan menos de 7: "
         << tienda.cuantosBajo(7) << endl;

    cout << "Mas caro: "
         << *tienda.codigoMasCaro() << endl;

    cout << "Precio del 310: "
         << tienda.precioDe(310).value_or(0) << endl;

    cout << "Precio del 999: ";

    if (tienda.precioDe(999).has_value()) {
        cout << *tienda.precioDe(999) << endl;
    }
    else {
        cout << "no existe" << endl;
    }

    // Encontrar el mayor precio final usando la plantilla
    cout << "Mayor precio final: "
         << mayorDe(tienda.preciosFinales()) << endl;

    return 0;
}

