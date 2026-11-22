#include <iostream>
#include <map>
using namespace std;

class Inventario {
private:
    map<int, int> stockPorCodigo;

public:
    // Ingresar unidades al inventario
    void ingresar(int codigo, int unidades) {
        if (unidades <= 0) {
            return;
        }

        stockPorCodigo[codigo] += unidades;
    }

    // Retirar unidades del inventario
    bool retirar(int codigo, int unidades) {
        auto it = stockPorCodigo.find(codigo);

        if (it == stockPorCodigo.end() || unidades <= 0 ||
            it->second < unidades) {
            return false;
        }

        it->second -= unidades;
        return true;
    }

    // Consultar stock de un codigo
    int stockDe(int codigo) {
        auto it = stockPorCodigo.find(codigo);

        if (it == stockPorCodigo.end()) {
            return 0;
        }

        return it->second;
    }

    // Contar codigos agotados
    int agotados() {
        int contador = 0;

        for (auto it = stockPorCodigo.begin();
             it != stockPorCodigo.end(); it++) {

            if (it->second == 0) {
                contador++;
            }
        }

        return contador;
    }

    // Cantidad de codigos registrados
    int codigos() {
        return stockPorCodigo.size();
    }

    // Imprimir inventario en orden de codigo
    void imprimir() {
        for (auto it = stockPorCodigo.begin();
             it != stockPorCodigo.end(); it++) {

            cout << it->first << ": "
                 << it->second << endl;
        }
    }
};

int main() {

    Inventario inventario;

    // Ingresar productos
    inventario.ingresar(300, 40);
    inventario.ingresar(120, 15);
    inventario.ingresar(450, 5);
    inventario.ingresar(999, -3);

    // Retirar productos
    cout << "Retirar 15 del 120: "
         << inventario.retirar(120, 15) << endl;

    cout << "Retirar 10 del 450: "
         << inventario.retirar(450, 10) << endl;

    cout << "Retirar 1 del 777: "
         << inventario.retirar(777, 1) << endl;

    // Consultas
    cout << "Stock del 999: "
         << inventario.stockDe(999) << endl;

    cout << "Codigos registrados: "
         << inventario.codigos() << endl;

    cout << "Agotados: "
         << inventario.agotados() << endl;

    // Imprimir inventario
    inventario.imprimir();

    return 0;
}

