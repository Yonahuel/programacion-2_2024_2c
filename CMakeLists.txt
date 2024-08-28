cmake_minimum_required(VERSION 3.29)
project(TP_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(headers)

add_executable(TP_1
        headers/Ejercicio_8_Header.h
        ejercicios/Ejercicio_8.c
    main.c
        ejercicios/Ejercicio_1.c
        headers/Ejercicio_1_Header.h
        test/TestEjercicio1.c
        headers/Ejercicio_2_Header.h
        headers/Ejercicio_3_Header.h
        headers/Ejercicio_4_Header.h
        headers/Ejercicio_5_Header.h
        headers/Ejercicio_6_Header.h
        headers/Ejercicio_7_Header.h
        headers/Ejercicio_9_Header.h
        headers/Ejercicio_10_Header.h)
