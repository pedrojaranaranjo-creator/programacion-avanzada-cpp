#include <atomic>
#include <iostream>
#include <thread>



class TarjetaAtomica {
    private:
        std::atomic<int> saldo;
        std::atomic<int> aceptados;
        std::atomic<int> rechazados;

    public:
        TarjetaAtomica() {
            saldo = 50;
            aceptados = 0;
            rechazados = 0;
        }

        void cobrarIngenuo(int monto) {
            if (saldo >= monto) {
                saldo -= monto;
                aceptados++;
            } else {
                rechazados++;
            }
        }

        
        void cobrar(int monto) {

            
            int actual = saldo;

            
            while (true) {

                
                if (actual < monto) {
                    rechazados++;
                    break;
                }

                
                if (saldo.compare_exchange_weak(actual, actual - monto)) {
                    aceptados++;
                    break;
                }

                
            }
        }

        int getSaldo() {
            return saldo;
        }

        int getAceptados() {
            return aceptados;
        }

        int getRechazados() {
            return rechazados;
        }
};

const int TARJETAS = 2000;

void cajaIngenua(TarjetaAtomica* tarjetas, int intentos) {
    for (int t = 0; t < TARJETAS; t++) {
        for (int i = 0; i < intentos; i++) {
            tarjetas[t].cobrarIngenuo(1);
        }
    }
}

void caja(TarjetaAtomica* tarjetas, int intentos) {
    for (int t = 0; t < TARJETAS; t++) {
        for (int i = 0; i < intentos; i++) {
            tarjetas[t].cobrar(1);
        }
    }
}

int enNegativo(TarjetaAtomica* tarjetas) {
    int total = 0;

    for (int t = 0; t < TARJETAS; t++) {
        if (tarjetas[t].getSaldo() < 0) {
            total = total + 1;
        }
    }

    return total;
}

TarjetaAtomica ingenuas[TARJETAS];
TarjetaAtomica tarjetas[TARJETAS];

int main() {

    std::thread a(cajaIngenua, ingenuas, 40);
    std::thread b(cajaIngenua, ingenuas, 40);

    a.join();
    b.join();

    std::cout << "Ingenuo, tarjetas en negativo: "
              << enNegativo(ingenuas) << std::endl;

    std::thread c(caja, tarjetas, 40);
    std::thread d(caja, tarjetas, 40);

    c.join();
    d.join();

    int aceptados = 0;
    int rechazados = 0;

    for (int t = 0; t < TARJETAS; t++) {
        aceptados = aceptados + tarjetas[t].getAceptados();
        rechazados = rechazados + tarjetas[t].getRechazados();
    }

    std::cout << "Correcto, tarjetas en negativo: "
              << enNegativo(tarjetas) << std::endl;

    std::cout << "Correcto, cobros aceptados: "
              << aceptados << std::endl;

    std::cout << "Correcto, cobros rechazados: "
              << rechazados << std::endl;

    return 0;
}

