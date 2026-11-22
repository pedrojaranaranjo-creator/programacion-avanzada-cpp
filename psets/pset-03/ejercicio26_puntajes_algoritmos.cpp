#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// 1. Posicion del primer 100
int posicionDelPrimerPerfecto(vector<int> puntajes) {
    auto it = find(puntajes.begin(), puntajes.end(), 100);

    if (it == puntajes.end()) {
        return -1;
    }

    return it - puntajes.begin();
}

// 2. Contar aprobados
int aprobados(vector<int> puntajes, int minimo) {
    return count_if(puntajes.begin(), puntajes.end(),
        [minimo](int nota) {
            return nota >= minimo;
        });
}

// 3. Encontrar el mayor
int mejor(vector<int> puntajes) {
    if (puntajes.empty()) {
        return 0;
    }

    return *max_element(puntajes.begin(), puntajes.end());
}

// 4. Calcular promedio
double promedio(vector<int> puntajes) {
    if (puntajes.empty()) {
        return 0;
    }

    double suma = accumulate(
        puntajes.begin(),
        puntajes.end(),
        0.0
    );

    return suma / puntajes.size();
}

// 5. Encontrar el primer puntaje bajo
int primeroBajo(vector<int> puntajes, int limite) {
    auto it = find_if(puntajes.begin(), puntajes.end(),
        [limite](int nota) {
            return nota < limite;
        });

    if (it == puntajes.end()) {
        return -1;
    }

    return *it;
}

// 6. Crear podio de los tres mejores
vector<int> podio(vector<int> puntajes) {
    sort(puntajes.begin(), puntajes.end(),
        [](int a, int b) {
            return a > b;
        });

    if (puntajes.size() > 3) {
        puntajes.resize(3);
    }

    return puntajes;
}

int main() {

    vector<int> puntajes = {
        72, 100, 45, 88, 100, 59, 91, 64
    };

    cout << "Primer perfecto en la posicion: "
         << posicionDelPrimerPerfecto(puntajes) << endl;

    cout << "Aprobados con 70: "
         << aprobados(puntajes, 70) << endl;

    cout << "Mejor: "
         << mejor(puntajes) << endl;

    cout << "Promedio: "
         << promedio(puntajes) << endl;

    cout << "Primero bajo 60: "
         << primeroBajo(puntajes, 60) << endl;

    cout << "Podio: ";

    vector<int> resultado = podio(puntajes);

    for (int nota : resultado) {
        cout << nota << " ";
    }

    cout << endl;

    // Probar con vector vacio
    vector<int> vacio;

    cout << "Vacio, mejor: "
         << mejor(vacio) << endl;

    cout << "Vacio, promedio: "
         << promedio(vacio) << endl;

    return 0;
}

