
#include <gtest/gtest.h>
#include <stdexcept>

#include "bodega.h"


TEST(Bodega, IngresarDosVecesAcumula) {
    Bodega bodega;

    bodega.ingresar(305, 10);
    bodega.ingresar(305, 5);

    EXPECT_EQ(bodega.stockDe(305), 15);
}


TEST(Bodega, RetirarTodoElStockLoDejaEnCero) {
    Bodega bodega;

    bodega.ingresar(210, 5);

    EXPECT_NO_THROW(bodega.retirar(210, 5));

    EXPECT_EQ(bodega.stockDe(210), 0);
}


TEST(Bodega, RetirarMasDelStockLanzaYNoCambiaNada) {
    Bodega bodega;

    bodega.ingresar(120, 2);

    EXPECT_THROW(
        bodega.retirar(120, 5),
        std::runtime_error
    );

    EXPECT_EQ(bodega.stockDe(120), 2);
}


TEST(Bodega, CantidadCeroLanza) {
    Bodega bodega;

    bodega.ingresar(305, 10);

    EXPECT_THROW(
        bodega.retirar(305, 0),
        std::invalid_argument
    );
}


TEST(Bodega, CodigoDesconocidoLanzaYNoSeCrea) {
    Bodega bodega;

    bodega.ingresar(305, 10);

    EXPECT_THROW(
        bodega.retirar(999, 1),
        std::out_of_range
    );

    EXPECT_THROW(
        bodega.stockDe(999),
        std::out_of_range
    );
}

