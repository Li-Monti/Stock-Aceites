
#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#ifndef ESTRUCT_H
#define ESTRUCT_H

#define max_Aceites 50
#include "estructuraFecha.h"

    typedef struct {
        int codigo;
        char marca[max_Aceites];
        char marcaOriginal[max_Aceites];
        int presentacion;
        char tipo[20] ;
        char tipoOriginal[20];
        float precio;
        Fecha fechaVencimiento;
        int stock;
    } producto;

#endif //ESTRUCT_H
#endif //ESTRUCTURA_H
