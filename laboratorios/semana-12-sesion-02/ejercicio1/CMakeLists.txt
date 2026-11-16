
# TODO 1: Configuracion del proyecto

cmake_minimum_required(VERSION 3.20)

project(Estacionamiento LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# TODO 2: Ejecutable principal

add_executable(estacionamiento main.cpp)

target_compile_options(estacionamiento PRIVATE -Wall -Wextra)


# TODO 3: Ejecutable de pruebas con GoogleTest

enable_testing()

find_package(GTest REQUIRED)

add_executable(pruebas test_estacionamiento.cpp)

target_link_libraries(pruebas PRIVATE GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(pruebas)


# TODO 4: Ejecutable reporte de tiempos

add_executable(reporte_tiempos reporte_tiempos.cpp)

target_compile_options(reporte_tiempos PRIVATE -Wall -Wextra)

