
#include <stdio.h>
#include <string.h>
#include "estructura.h"
void marcaBarata(producto inventario[], int cantidadAceites) {
    float precioMin = inventario[0].precio;
    int piboteMin = 0;

    for (int i=1 ; i<cantidadAceites; i++) {

        if (inventario[i].precio > 0 && inventario[i].precio < precioMin){
            precioMin = inventario[i].precio;
            piboteMin = i;

        }


        printf("\nResultado del Aceite mas barato:\n");
        printf("----------------------------------------------\n");
        printf("| Marca        | Precio  | Stock |\n");
        printf("----------------------------------------------\n");
        printf("| %s | %.2f | %5d |\n",
               inventario[piboteMin].marcaOriginal,
               inventario[piboteMin].precio,
               inventario[piboteMin].stock);
        printf("----------------------------------------------\n");
    }
}

void stockCocinero(producto inventario[], int cantidadAceites) {
    char marcaBuscada[20] = "cocinero";
    int stockTotal=0;
    int encontrado = 0;


    printf("\nResultados para marca '%s' y presentacion %d ml:\n", marcaBuscada);


    printf("--------------------------------------------------------------\n");
    printf("| Codigo | Marca        | Presentacion | Precio | Stock     |\n");
    printf("--------------------------------------------------------------\n");

    for (int i= 0; i < cantidadAceites; i++) {
        if ((inventario[i].fechaVencimiento.anio < 2025) || (inventario[i].fechaVencimiento.anio == 2025 && inventario[i].fechaVencimiento.mes < 9) ||
                (inventario[i].fechaVencimiento.anio == 2025 && inventario[i].fechaVencimiento.mes == 9 && inventario[i].fechaVencimiento.dia < 12)) { {
                    printf("| %6d | %-12s | %12d | %6.2f | %9d |\n",
                        inventario[i].codigo,
                         inventario[i].marcaOriginal,
                         inventario[i].presentacion,
                         inventario[i].precio,
                         inventario[i].stock);
                }
                }
        if (encontrado == 0) {
            printf("No se encontraron aceites válidos\n");
        }

        printf("--------------------------------------------------------------\n");
        printf("Stock total: %d unidades\n", stockTotal);
    }

    }
}
