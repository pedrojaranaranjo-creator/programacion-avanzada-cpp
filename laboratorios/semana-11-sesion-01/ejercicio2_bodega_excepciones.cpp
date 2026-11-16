
#include <iostream>
#include <map>
#include <stdexcept>

class Bodega {
private:
    std::map<int, int> stock;

public:
    void ingresar(int codigo, int cantidad) {
        stock[codigo] = stock[codigo] + cantidad;
    }

    
    void retirar(int codigo, int cantidad) {

        if (cantidad <= 0) {
            throw std::invalid_argument("cantidad no positiva");
        }

        if (stock.count(codigo) == 0) {
            throw std::out_of_range("codigo desconocido");
        }

        if (stock.at(codigo) < cantidad) {
            throw std::runtime_error("stock insuficiente");
        }

        stock[codigo] = stock[codigo] - cantidad;
    }

    
    int stockDe(int codigo) {
        return stock.at(codigo);
    }

    void imprimirStock() {
        std::cout << "Stock:";

        for (auto par : stock) {
            std::cout << " " << par.first << "=" << par.second;
        }

        std::cout << std::endl;
    }
};

int main() {
    Bodega bodega;

    bodega.ingresar(305, 10);
    bodega.ingresar(120, 2);
    bodega.ingresar(210, 5);

    bodega.imprimirStock();

    int codigos[5] = {120, 305, 999, 120, 210};
    int cantidades[5] = {1, 0, 1, 5, 5};

    
    for (int i = 0; i < 5; i++) {

        std::cout << "Pedido de " << cantidades[i]
                  << " x " << codigos[i] << ": ";

        try {
            bodega.retirar(codigos[i], cantidades[i]);
            std::cout << "despachado" << std::endl;
        }
        catch (const std::invalid_argument& e) {
            std::cout << "rechazado, " << e.what() << std::endl;
        }
        catch (const std::out_of_range& e) {
            std::cout << "rechazado, " << e.what() << std::endl;
        }
        catch (const std::runtime_error& e) {
            std::cout << "rechazado, " << e.what() << std::endl;
        }
    }

    bodega.imprimirStock();

    
    try {
        std::cout << "Stock de 305: "
                  << bodega.stockDe(305) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Stock de 305: no registrado" << std::endl;
    }

    try {
        std::cout << "Stock de 999: "
                  << bodega.stockDe(999) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Stock de 999: no registrado" << std::endl;
    }

    return 0;
}

