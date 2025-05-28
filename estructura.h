//
// Created by Li on 5/24/2025.
//

#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

//
// Created by Li on 5/24/2025.
//

#ifndef ESTRUCT_H
#define ESTRUCT_H

#define max_Aceites 50
#include "estructuraFecha.h"

    typedef struct {
        int codigo;
        char marca[50];
        int presentacion;
        char tipo[20] ;
        float precio;
        Fecha fechaVencimiento;
        int stock;
    } producto;

#endif //ESTRUCT_H


#endif //ESTRUCTURA_H
