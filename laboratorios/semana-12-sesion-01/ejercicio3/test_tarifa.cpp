#include <gtest/gtest.h>
#include <stdexcept>

#include "tarifa.h"


TEST(TarifaTest, MinutosNegativos) {
    EXPECT_THROW(
        tarifaEnCentavos(-1),
        std::invalid_argument
    );

    EXPECT_THROW(
        tarifaEnCentavos(-10),
        std::invalid_argument
    );
}


TEST(TarifaTest, TiempoGratis) {
    EXPECT_EQ(tarifaEnCentavos(0), 0);
    EXPECT_EQ(tarifaEnCentavos(1), 0);
    EXPECT_EQ(tarifaEnCentavos(10), 0);
    EXPECT_EQ(tarifaEnCentavos(15), 0);
}


TEST(TarifaTest, PrimeraHora) {
    EXPECT_EQ(tarifaEnCentavos(16), 50);
    EXPECT_EQ(tarifaEnCentavos(30), 50);
    EXPECT_EQ(tarifaEnCentavos(60), 50);
}

TEST(TarifaTest, HorasAdicionales) {
    EXPECT_EQ(tarifaEnCentavos(61), 100);
    EXPECT_EQ(tarifaEnCentavos(90), 100);
    EXPECT_EQ(tarifaEnCentavos(120), 100);

    EXPECT_EQ(tarifaEnCentavos(121), 150);
    EXPECT_EQ(tarifaEnCentavos(180), 150);
}


TEST(TarifaTest, PrecioMaximo) {
    EXPECT_EQ(tarifaEnCentavos(600), 500);
    EXPECT_EQ(tarifaEnCentavos(1000), 500);
    EXPECT_EQ(tarifaEnCentavos(2000), 500);
}


TEST(TarifaTest, LimiteTiempoGratis) {
    EXPECT_EQ(tarifaEnCentavos(15), 0);
    EXPECT_EQ(tarifaEnCentavos(16), 50);
}


TEST(TarifaTest, LimitesDeHora) {
    EXPECT_EQ(tarifaEnCentavos(60), 50);
    EXPECT_EQ(tarifaEnCentavos(61), 100);

    EXPECT_EQ(tarifaEnCentavos(120), 100);
    EXPECT_EQ(tarifaEnCentavos(121), 150);
}
