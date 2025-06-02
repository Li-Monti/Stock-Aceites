
#include<stdio.h>
#include <string.h>
#include "estructura.h"
#include "consultasBasicas.h"
#include "consultasConAgregaciones.h"
#include "busquedaConFiltros.h"
#include "ordenamientoYBuscado.h"
#include "otrasFunciones.h"
#include "cargarAceitesDePueba.h"
#define max_Aceites 50

int cargarAceite(producto inventario[max_Aceites], int cantidadAceites) {
    int valorPre;
    int tipoAceite;
    int valido;
    do{


    printf("Ingrese el codigo del Aceite: ");

        valido = scanf("%d", &inventario[cantidadAceites].codigo);

        if(valido!=1){
        printf("Error: Ingrese un codigo valido\n\n");
            while (getchar() != '\n');
        }

    }while (valido!=1);

    do {
        printf("Ingrese la marca (sin espacios vacios): ");

        valido = scanf("%49s", inventario[cantidadAceites].marcaOriginal);
        strcpy(inventario[cantidadAceites].marca, inventario[cantidadAceites].marcaOriginal ) ;
        minuscula(inventario[cantidadAceites].marca);

        if(valido!=1){
            printf("Error: Ingrese una marca valida\n\n");
            while (getchar() != '\n');
        } else {
            while (getchar() != '\n');
        }

    }while (valido!=1);

    do {
        printf("Elija la presentacion del Aceite:");
        printf("\n1. 500 ml");
        printf("\n2. 1000 ml");
        printf("\n3. 1500 ml");
        printf("\n4. 5000 ml");
        printf("\nResultado: ");
        scanf("%d", &valorPre);

        if (valorPre < 1 || valorPre > 4) {
            printf("Ingrese una presentacion valida\n");
        }
    } while (valorPre < 1 || valorPre > 4);

    switch (valorPre) {
        case 1:
            inventario[cantidadAceites].presentacion = 500;
            break;
        case 2:
            inventario[cantidadAceites].presentacion = 1000;
            break;
        case 3:
            inventario[cantidadAceites].presentacion = 1500;
            break;
        case 4:
            inventario[cantidadAceites].presentacion = 5000;
            break;
    }

    do{
    printf("Ingrese el tipo: ");
    printf("\n1. Girasol");
    printf("\n2. Oliva");
    printf("\n3. Maiz");
    printf("\n4. Mezcla");
    printf("\nResultado: ");
    scanf("%d", &tipoAceite);


    if ( tipoAceite > 4 || tipoAceite < 1 ) {
        printf("Error: Ingrese un valor valido\n\n");
    }
}while (tipoAceite < 1 || tipoAceite >4);

    switch (tipoAceite) {
        case 1:
            strcpy(inventario[cantidadAceites].tipoOriginal, "Girasol");

            strcpy(inventario[cantidadAceites].tipo, inventario[cantidadAceites].tipoOriginal ) ;

            minuscula(inventario[cantidadAceites].tipo);

            break;
        case 2:
            strcpy(inventario[cantidadAceites].tipoOriginal, "Oliva");

            strcpy(inventario[cantidadAceites].tipo, inventario[cantidadAceites].tipoOriginal ) ;

            minuscula(inventario[cantidadAceites].tipo);
            break;
        case 3:
            strcpy(inventario[cantidadAceites].tipoOriginal, "Maiz");

            strcpy(inventario[cantidadAceites].tipo, inventario[cantidadAceites].tipoOriginal ) ;

            minuscula(inventario[cantidadAceites].tipo);
            break;
        case 4:
            strcpy(inventario[cantidadAceites].tipoOriginal, "Mezcla");

            strcpy(inventario[cantidadAceites].tipo, inventario[cantidadAceites].tipoOriginal ) ;

            minuscula(inventario[cantidadAceites].tipo);
            break;
    }


    printf("Ingrese el precio: $");
    scanf("%f", &inventario[cantidadAceites].precio);

    printf("Ingrese el anio de vencimiento: ");
    scanf("%d", &inventario[cantidadAceites].fechaVencimiento.anio);
do {
    printf("Ingrese el mes de vencimiento: ");
    scanf("%d", &inventario[cantidadAceites].fechaVencimiento.mes);

    if (inventario[cantidadAceites].fechaVencimiento.mes > 12 || inventario[cantidadAceites].fechaVencimiento.mes < 1) {
        printf("Ingrese un mes valido\n\n");
    }
    }while (inventario[cantidadAceites].fechaVencimiento.mes > 12 || inventario[cantidadAceites].fechaVencimiento.mes < 1);

    do{
    printf("Ingrese el dia de vencimiento: ");
    scanf("%d", &inventario[cantidadAceites].fechaVencimiento.dia);

    if (inventario[cantidadAceites].fechaVencimiento.dia > 31 || inventario[cantidadAceites].fechaVencimiento.dia < 1) {
        printf("Ingrese un dia valido\n\n");
    }
    }while (inventario[cantidadAceites].fechaVencimiento.dia > 31 || inventario[cantidadAceites].fechaVencimiento.dia < 1);

    do{
    printf("Ingrese la cantidad de unidades en stock: ");
    scanf("%d", &inventario[cantidadAceites].stock);

    if (inventario[cantidadAceites].stock <1) {
        printf("Error: Ingrese un numero valido");
    }
        }while (inventario[cantidadAceites].stock <1);

    cantidadAceites = cantidadAceites + 1;
    printf("\nAceite agregado correctamente. Total de aceites: %d\n", cantidadAceites);

    return cantidadAceites;
}

int main(){

    producto inventario[max_Aceites] ;
    int cantidadAceites = 0 ;
    int valorMenu;

    do {
    printf("\n Bienvenido al Menu Principal:");
    printf("\n Ingrese un valor segun la accion que desee: ");
    printf("\n 1. Ingrese un nuevo aceite");
    printf("\n 2. Mostrar Stock por marca y presentacion");
    printf("\n 3. Stock disponible por tipo de aceite en litros");
    printf("\n 4. Marca de aceite mas barato");
    printf("\n 5. Stock de aceite marca cocinero, con fecha de vencimiento anterior a 12/09/2025");
    printf("\n 6. Cantidad total de unidades de 1000 ml");
    printf("\n 7. Porcentaje de aceite de 1500 ml que cuestan menoos de $4800");
    printf("\n 8. Listado de stock por tipo de aceite");
    printf("\n 9. Listado del stock por marca y presentacion ordenados por fecha de vencimineto");
    printf("\n 0. Salir del programa");
        printf("\n Resultado: ");
        scanf("%d", &valorMenu);

    switch(valorMenu){
        case 1:
            if (cantidadAceites >= max_Aceites) {
                printf("Error: Inventario lleno. No se pueden agregar mas aceites.\n");
            } else {
                cantidadAceites = cargarAceitesDePrueba(inventario);
            }

            break;
        case 2:
            if (cantidadAceites == 0) {
                printf("No hay aceites registrados en el inventario.\n");
            } else {
                stockPorMarcaYPresentacion(inventario, cantidadAceites);
            }
            break;
        case 3:
            if (cantidadAceites == 0) {
                printf("No hay aceites registrados en el inventario.\n");
            } else {
                stockPorTipoLitro(inventario,cantidadAceites);
            }
            break;
        case 4 :
            if (cantidadAceites == 0) {
                printf("No hay aceites registrados en el inventario.\n");
            } else {
                marcaBarata(inventario, cantidadAceites);
            }
        break;
        case 5 :
            if (cantidadAceites == 0) {
                printf("No hay aceites registrados en el inventario.\n");
            } else {
            stockCocineroVencimiento(inventario, cantidadAceites);
            }
        break;
        case 6 :
            if (cantidadAceites == 0) {
                printf("No hay aceites registrados en el inventario.\n");
            } else {
            cantidadUnidades1000ml(inventario, cantidadAceites);
                }
        break;
        case 7 :
            if (cantidadAceites == 0) {
                printf("No hay aceites registrados en el inventario.\n");
            } else {
                porcentajesAceites(inventario, cantidadAceites);
            }
        break;
        case 8 :
            if (cantidadAceites == 0) {
                printf("No hay aceites registrados en el inventario.\n");
            } else {
                listadoStockPorTipo(inventario, cantidadAceites);
            }
        break;
        case 9 :
            if (cantidadAceites == 0) {
                printf("No hay aceites registrados en el inventario.\n");
            } else {
                ordenarPorVencimiento(inventario, cantidadAceites);
            }
        break;
        case 0 :
        printf("\nSaliendo del programa.\n");
        break;
      default :
        printf("\nOpcion no valida. Intente de nuevo. \n");
        break;
    }

    if (valorMenu != 0) {
            printf("\nPresione enter para volver al menu");
            getchar();
            getchar();

        }

    } while (valorMenu != 0);

    return 0;
}



