#include <iostream>
#include <vector>
#include <optional>



class Producto {
    private:
        int codigo;
        double precio;
        std::optional<double> descuento;

    public:
        Producto(int nuevoCodigo, double nuevoPrecio) {
            codigo = nuevoCodigo;
            precio = nuevoPrecio;
            descuento = std::nullopt;
        }

        int getCodigo() {
            return codigo;
        }

        double getPrecio() {
            return precio;
        }

        void setDescuento(double fraccion) {
            descuento = fraccion;
        }

        
        double precioFinal() {
            return precio * (1 - descuento.value_or(0.0));
        }
};

class Catalogo {
    private:
        std::vector<Producto> productos;

    public:
        void agregar(Producto producto) {
            productos.push_back(producto);
        }

        int cantidad() {
            return productos.size();
        }

        
        std::optional<Producto> buscar(int codigo) {
            for (int i = 0; i < cantidad(); i++) {
                if (productos[i].getCodigo() == codigo) {
                    return productos[i];
                }
            }

            return std::nullopt;
        }
};

int main() {
    Catalogo catalogo;

    catalogo.agregar(Producto(305, 0.25));
    catalogo.agregar(Producto(210, 3.5));

    
    std::optional<Producto> encontrado = catalogo.buscar(210);

    Producto cable(120, 28.0);

    
    cable.setDescuento(0.1);

    catalogo.agregar(cable);
    catalogo.agregar(Producto(410, 12.0));

    
    if (encontrado.has_value()) {
        std::cout << "Producto 210: precio "
                  << encontrado->getPrecio()
                  << ", precio final "
                  << encontrado->precioFinal()
                  << std::endl;
    } else {
        std::cout << "Producto 210: no existe en el catalogo" << std::endl;
    }

    int consultas[3] = {120, 999, 305};

    for (int i = 0; i < 3; i++) {

        std::optional<Producto> producto = catalogo.buscar(consultas[i]);

        if (producto.has_value()) {
            std::cout << "Producto " << consultas[i]
                      << ": precio " << producto->getPrecio()
                      << ", precio final " << producto->precioFinal()
                      << std::endl;
        } else {
            std::cout << "Producto " << consultas[i]
                      << ": no existe en el catalogo"
                      << std::endl;
        }
    }

    std::cout << "Productos en el catalogo: "
              << catalogo.cantidad() << std::endl;

    return 0;
}

