//
// Created by Li on 5/25/2025.
//
//
// Created by Li on 5/24/2025.
//
#include "estructura.h"
#include <stdio.h>
#include <string.h>

void stockPorMarcaYPresentacion(producto inventario[], int cantidadAceites) {
    char marcaBuscada[20];
    int presentacionBuscada;
    int valorPre;
    int stockTotal = 0;
    int encontrado = 0;
//prueba

    do{
        printf("Ingrese la marca: ");
        scanf("%49s", marcaBuscada);
        printf("Elija la presentacion del Aceite:");
        printf("\n1. 500 ml");
        printf("\n2. 1000 ml");
        printf("\n3. 1500 ml");
        printf("\n4. 5000 ml");
        printf("\nResultado: ");
        scanf("%d", &valorPre);

        if (valorPre < 1 || valorPre > 4){
            printf("\nError: Ingrese una presentacion valida");
        }

    }while (valorPre < 1 || valorPre > 4);

    switch (valorPre){
        case 1:
            presentacionBuscada = 500;
            break;
        case 2:
            presentacionBuscada = 1000;
            break;
        case 3:
             presentacionBuscada = 1500;
            break;
        case 4:
            presentacionBuscada = 5000;
            break;
    }


    printf("\nResultados para marca '%s' y presentacion %d ml:\n", marcaBuscada, presentacionBuscada);
    printf("----------------------------------------------\n");
    printf("| Codigo | Tipo         | Precio | Stock |\n");
    printf("----------------------------------------------\n");

    for (int i = 0; i < cantidadAceites; i++) {
        if (strcmp(inventario[i].marca, marcaBuscada) == 0 &&
            inventario[i].presentacion == presentacionBuscada) {
            printf("| %6d | %s | %6.2f | %5d |\n",
                  inventario[i].codigo,
                  inventario[i].tipo,
                  inventario[i].precio,
                  inventario[i].stock);
            stockTotal = stockTotal + inventario[i].stock;
            encontrado = 1;
            }
    }

    printf("----------------------------------------------\n");
    if (encontrado) {
        printf("Stock total para marca '%s' y presentacion %d ml: %d unidades\n",
              marcaBuscada, presentacionBuscada, stockTotal);
    } else {
        printf("No se encontraron aceites con esas especificaciones\n");
    }
}



void cantidadUnidades1000ml(producto inventario[], int cantidadAceites) {
    int stockTotal =0;
    int bandera = 0;


    printf("\nResultados de Aceites de 1000 ml:\n");
    printf("---------------------------------------------------\n");
    printf("| Codigo | Tipo         | Precio | Stock |\n");
    printf("---------------------------------------------------\n");

    for (int i=0 ; i < cantidadAceites; i++) {
        if (inventario[i].presentacion==1000) {

            printf("| %6d | %s | %6.2f | %5d |\n",
                  inventario[i].codigo,
                  inventario[i].tipo,
                  inventario[i].precio,
                  inventario[i].stock);
            stockTotal = stockTotal + inventario[i].stock;
            bandera = 1;
        }
    }
    printf("--------------------------------------------------\n");
    if (bandera) {
        printf("Stock total de aceites de 1000 ml: '%d' \n", stockTotal);
    } else {
        printf("No se encontraron Aceites");
    }
}


void listadoStockPorTipo(producto inventario[], int cantidadAceites) {

    printf("--------------------------------------------------------------\n");
    printf("| Codigo | Marca        | Presentacion | Precio | Stock     |\n");
    printf("--------------------------------------------------------------\n");

    for (int i= 0; i < cantidadAceites; i++) {
            printf("| %6d | %s | %12d | %6.2f | %9d |\n",
                  inventario[i].codigo,
                  inventario[i].marca,
                  inventario[i].presentacion,
                  inventario[i].precio,
                  inventario[i].stock);
    }
    printf("--------------------------------------------------------------\n");

}
