#include <gtest/gtest.h>
#include <optional>
#include <stdexcept>

#include "estacionamiento.h"

// PRUEBA MODELO
TEST(Estacionamiento, PrimeraPlacaRecibePuestoCero) {
    Estacionamiento estacionamiento(3);

    std::optional<int> puesto = estacionamiento.asignarPuesto(4521);

    ASSERT_TRUE(puesto.has_value());
    EXPECT_EQ(*puesto, 0);
}

// TODO 1: LlenoDevuelveVacio
TEST(Estacionamiento, LlenoDevuelveVacio) {
    Estacionamiento estacionamiento(3);

    estacionamiento.asignarPuesto(4521);
    estacionamiento.asignarPuesto(7788);
    estacionamiento.asignarPuesto(3011);

    std::optional<int> puesto = estacionamiento.asignarPuesto(9090);

    EXPECT_FALSE(puesto.has_value());
}

// TODO 2: PlacaRepetidaLanza
TEST(Estacionamiento, PlacaRepetidaLanza) {
    Estacionamiento estacionamiento(3);

    estacionamiento.asignarPuesto(7788);

    EXPECT_THROW(
        estacionamiento.asignarPuesto(7788),
        std::invalid_argument
    );
}

// TODO 3: PuestoLiberadoSeReusa
TEST(Estacionamiento, PuestoLiberadoSeReusa) {
    Estacionamiento estacionamiento(3);

    estacionamiento.asignarPuesto(4521);
    estacionamiento.asignarPuesto(7788);
    estacionamiento.asignarPuesto(3011);

    estacionamiento.liberar(7788);

    std::optional<int> puesto = estacionamiento.asignarPuesto(9090);

    ASSERT_TRUE(puesto.has_value());
    EXPECT_EQ(*puesto, 1);
}
