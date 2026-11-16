#include <iostream>
#include <mutex>
#include <thread>

class TarjetaDelComedor {
private:
    int saldo;
    int aceptados;
    int rechazados;
    std::mutex mtx; 

public:
    TarjetaDelComedor(int inicial) {
        saldo = inicial;
        aceptados = 0;
        rechazados = 0;
    }

    void cobrar(int monto) {
        
        std::lock_guard<std::mutex> lock(mtx);

        if (saldo >= monto) {
            saldo = saldo - monto;
            aceptados = aceptados + 1;
        } else {
            rechazados = rechazados + 1;
        }
    }

    int getSaldo() {
        std::lock_guard<std::mutex> lock(mtx);
        return saldo;
    }

    int getAceptados() {
        std::lock_guard<std::mutex> lock(mtx);
        return aceptados;
    }

    int getRechazados() {
        std::lock_guard<std::mutex> lock(mtx);
        return rechazados;
    }
};

void caja(TarjetaDelComedor* tarjeta, int intentos) {
    for (int i = 0; i < intentos; i++) {
        tarjeta->cobrar(1);
    }
}

int main() {
    TarjetaDelComedor tarjeta(100000);

    
    std::thread caja1(caja, &tarjeta, 60000);
    std::thread caja2(caja, &tarjeta, 60000);

    
    caja1.join();
    caja2.join();

    std::cout << "Saldo final: " << tarjeta.getSaldo() << std::endl;
    std::cout << "Cobros aceptados: " << tarjeta.getAceptados() << std::endl;
    std::cout << "Cobros rechazados: " << tarjeta.getRechazados() << std::endl;

    return 0;
}
