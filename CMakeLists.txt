cmake_minimum_required(VERSION 3.30)
project(Stock-Aceites C)

set(CMAKE_C_STANDARD 17)

add_executable( Stock-Aceites main.c

        estructura.h
        estructuraFecha.h

        otrasFunciones.c
        otrasFunciones.h

        consultasBasicas.c
        consultasBasicas.h

        consultasConAgregaciones.c
        consultasConAgregaciones.h

        busquedaConFiltros.c
        busquedaConFiltros.h

        ordenamientoYBuscado.c
        ordenamientoYBuscado.h


)