//
// Created by Li on 5/25/2025.
//
#include <stdio.h>
#include <string.h>
#include "estructura.h"
void marcaBarata(producto inventario[], int cantidadAceites) {
    int i= 0;
    float aceiteBarato=0;
    char marcaBarata[20];
    int stockTotal = 0;
    int encontrado = 0;

    if (cantidadAceites == 0) {
        printf("\"No se cargo ningun aceite en el sistema. \n");
        return;
    }

    printf("\nResultado del Aceite mas barato: \n");
    printf("----------------------------------------------\n");
    printf("| Marca   | Precio | Stock |\n");
    printf("----------------------------------------------\n");

    for (i ; i<cantidadAceites; i++) {

        if (aceiteBarato==0) {
            strcpy(marcaBarata , inventario[i].marca);
            aceiteBarato = inventario[i].precio;
            stockTotal = inventario[i].stock;
        }else if (inventario[i].precio < aceiteBarato) {
            strcpy(marcaBarata , inventario[i].marca);
            aceiteBarato = inventario[i].precio;
            stockTotal = inventario[i].stock;

        }
        printf("| %s  | %6.2f | %5d |\n",
                  marcaBarata,
                  aceiteBarato,
                  stockTotal);

        encontrado = 1;
    }
    printf("--------------------------------------------------\n");
    if (encontrado == 0) {
        printf("No se encontraron aceites \n");
    }
}

void stockCocinero(producto inventario[], int cantidadAceites) {
    char marcaBuscada[20] = "Cocinero";
    int presentacionBuscada;
    int i = 0;

    if (cantidadAceites == 0) {
        printf("\nNo hay aceites cargados en el sistema.\n");
        return;
    }

    printf("\nResultados para marca '%s' y presentacion %d ml:\n", marcaBuscada, presentacionBuscada);


    printf("--------------------------------------------------------------\n");
    printf("| Codigo | Marca        | Presentacion | Precio | Stock     |\n");
    printf("--------------------------------------------------------------\n");

    for (i; i < cantidadAceites; i++) {
        if (strcmp(inventario[i].marca, marcaBuscada) == 0 && inventario[i].fechaVencimiento.dia <12 && inventario[i].fechaVencimiento.mes<=9 && inventario[i].fechaVencimiento.anio <=2025 ) {
            printf("| %6d | %-12s | %12d | %6.2f | %9d |\n",
                  inventario[i].codigo,
                  inventario[i].marca,
                  inventario[i].presentacion,
                  inventario[i].precio,
                  inventario[i].stock);

        }
    }
    printf("--------------------------------------------------------------\n");


}
