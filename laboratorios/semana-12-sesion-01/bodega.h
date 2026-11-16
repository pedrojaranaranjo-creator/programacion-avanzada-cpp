#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

#include "bodega.h"

// PRUEBA 1: Ingresar productos nuevos
TEST(BodegaTest, IngresarProductoNuevo) {
    Bodega bodega;

    bodega.ingresar(100, 10);

    EXPECT_EQ(bodega.stockDe(100), 10);
}

// PRUEBA 2: Ingresar suma al stock existente
TEST(BodegaTest, IngresarProductoExistente) {
    Bodega bodega;

    bodega.ingresar(100, 10);
    bodega.ingresar(100, 5);

    EXPECT_EQ(bodega.stockDe(100), 15);
}

// PRUEBA 3: Retirar una cantidad valida
TEST(BodegaTest, RetirarCantidadValida) {
    Bodega bodega;

    bodega.ingresar(100, 20);
    bodega.retirar(100, 5);

    EXPECT_EQ(bodega.stockDe(100), 15);
}

// PRUEBA 4: Retirar todo el stock
TEST(BodegaTest, RetirarTodoElStock) {
    Bodega bodega;

    bodega.ingresar(100, 10);
    bodega.retirar(100, 10);

    EXPECT_EQ(bodega.stockDe(100), 0);
}

// PRUEBA 5: Cantidad negativa o cero
TEST(BodegaTest, CantidadNoPositiva) {
    Bodega bodega;

    bodega.ingresar(100, 10);

    EXPECT_THROW(
        bodega.retirar(100, 0),
        std::invalid_argument
    );

    EXPECT_THROW(
        bodega.retirar(100, -5),
        std::invalid_argument
    );

    EXPECT_EQ(bodega.stockDe(100), 10);
}

// PRUEBA 6: Verificar el mensaje de la excepcion
TEST(BodegaTest, MensajeCantidadNoPositiva) {
    Bodega bodega;

    try {
        bodega.retirar(100, 0);
        FAIL() << "Debia lanzar invalid_argument";
    }
    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "cantidad no positiva");
    }
}

// PRUEBA 7: Codigo desconocido
TEST(BodegaTest, CodigoDesconocido) {
    Bodega bodega;

    EXPECT_THROW(
        bodega.retirar(999, 5),
        std::out_of_range
    );
}

// PRUEBA 8: Verificar mensaje de codigo desconocido
TEST(BodegaTest, MensajeCodigoDesconocido) {
    Bodega bodega;

    try {
        bodega.retirar(999, 5);
        FAIL() << "Debia lanzar out_of_range";
    }
    catch (const std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "codigo desconocido");
    }
}

// PRUEBA 9: Stock insuficiente
TEST(BodegaTest, StockInsuficiente) {
    Bodega bodega;

    bodega.ingresar(100, 5);

    EXPECT_THROW(
        bodega.retirar(100, 10),
        std::runtime_error
    );

    EXPECT_EQ(bodega.stockDe(100), 5);
}

// PRUEBA 10: Verificar mensaje de stock insuficiente
TEST(BodegaTest, MensajeStockInsuficiente) {
    Bodega bodega;

    bodega.ingresar(100, 5);

    try {
        bodega.retirar(100, 10);
        FAIL() << "Debia lanzar runtime_error";
    }
    catch (const std::runtime_error& e) {
        EXPECT_STREQ(e.what(), "stock insuficiente");
    }

    EXPECT_EQ(bodega.stockDe(100), 5);
}

// PRUEBA 11: Stock de codigo desconocido
TEST(BodegaTest, StockDeCodigoDesconocido) {
    Bodega bodega;

    EXPECT_THROW(
        bodega.stockDe(999),
        std::out_of_range
    );
}

// PRUEBA 12: Retiro rechazado no modifica la bodega
TEST(BodegaTest, RetiroRechazadoNoModificaStock) {
    Bodega bodega;

    bodega.ingresar(100, 20);
    bodega.ingresar(200, 30);

    EXPECT_THROW(
        bodega.retirar(100, 25),
        std::runtime_error
    );

    EXPECT_EQ(bodega.stockDe(100), 20);
    EXPECT_EQ(bodega.stockDe(200), 30);
}
