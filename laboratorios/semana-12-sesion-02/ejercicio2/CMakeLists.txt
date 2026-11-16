
# TODO 1: Configuracion del proyecto
cmake_minimum_required(VERSION 3.20)

project(PromedioMovil LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# TODO 2: Opcion para activar sanitizers
option(CON_SANITIZERS "Activar AddressSanitizer y UndefinedBehaviorSanitizer" OFF)

if(CON_SANITIZERS)
    add_compile_options(
        -fsanitize=address,undefined
        -fno-omit-frame-pointer
    )

    add_link_options(
        -fsanitize=address,undefined
    )
endif()


# TODO 3: Ejecutable principal
add_executable(promedios main.cpp)

target_compile_options(promedios PRIVATE -Wall -Wextra)


# Ejecutable de pruebas con GoogleTest
enable_testing()

find_package(GTest REQUIRED)

add_executable(pruebas test_lecturas.cpp)

target_link_libraries(pruebas PRIVATE GTest::gtest_main)

target_compile_options(pruebas PRIVATE -Wall -Wextra)

include(GoogleTest)

gtest_discover_tests(pruebas)
