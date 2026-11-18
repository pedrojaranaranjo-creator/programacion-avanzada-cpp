
#include <atomic>
#include <iostream>
#include <map>
#include <mutex>
#include <thread>



class CentroDeImpresion {
private:
    std::map<int, int> paginasEstudiante;
    std::mutex mtx;

    std::atomic<bool> cerrado;
    std::atomic<int> aceptados;
    std::atomic<int> rechazados;
    std::atomic<int> totalPaginas;

public:
    CentroDeImpresion() {
        cerrado = false;
        aceptados = 0;
        rechazados = 0;
        totalPaginas = 0;
    }

    bool enviar(int estudiante, int paginas) {

        std::lock_guard<std::mutex> lock(mtx);

        
        if (cerrado || paginas <= 0) {
            return false;
        }

        
        int actuales = paginasEstudiante[estudiante];

        
        if (actuales + paginas > 100) {
            rechazados++;
            return false;
        }

        
        paginasEstudiante[estudiante] += paginas;

        
        aceptados++;
        totalPaginas += paginas;

        return true;
    }

    void cerrar() {
        std::lock_guard<std::mutex> lock(mtx);
        cerrado = true;
    }

    bool estaCerrado() {
        return cerrado;
    }

    int trabajosAceptados() {
        return aceptados;
    }

    int rechazadosPorCuota() {
        return rechazados;
    }

    int paginasTotales() {
        return totalPaginas;
    }

    int paginasDe(int estudiante) {
        std::lock_guard<std::mutex> lock(mtx);

        auto it = paginasEstudiante.find(estudiante);

        if (it == paginasEstudiante.end()) {
            return 0;
        }

        return it->second;
    }
};

void computadora(CentroDeImpresion* centro) {
    for (int estudiante = 1; estudiante <= 50; estudiante++) {
        for (int i = 0; i < 10; i++) {
            centro->enviar(estudiante, 5);
        }
    }
}

int main() {
    CentroDeImpresion centro;

    std::thread pc1(computadora, &centro);
    std::thread pc2(computadora, &centro);
    std::thread pc3(computadora, &centro);
    std::thread pc4(computadora, &centro);

    pc1.join();
    pc2.join();
    pc3.join();
    pc4.join();

    int suma = 0;
    int sobreCuota = 0;

    for (int estudiante = 1; estudiante <= 50; estudiante++) {
        suma = suma + centro.paginasDe(estudiante);

        if (centro.paginasDe(estudiante) > 100) {
            sobreCuota = sobreCuota + 1;
        }
    }

    std::cout << "Trabajos aceptados: "
              << centro.trabajosAceptados() << std::endl;

    std::cout << "Rechazados por cuota: "
              << centro.rechazadosPorCuota() << std::endl;

    std::cout << "Paginas impresas: "
              << centro.paginasTotales() << std::endl;

    std::cout << "Suma por estudiante: "
              << suma << std::endl;

    std::cout << "Estudiantes sobre la cuota: "
              << sobreCuota << std::endl;

    centro.cerrar();

    std::cout << "Despues de cerrar, se acepta un trabajo: "
              << centro.enviar(7, 1) << std::endl;

    return 0;
}

