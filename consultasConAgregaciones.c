
#include <stdio.h>
#include <string.h>
#include "estructura.h"

void stockPorTipoLitro(producto inventario[], int cantidadAceites) {
    int stockTotal = 0;
    int tipoAceite;
    int bandera = 0;
    float litros;
    char tipoBuscado[20];

do{
    printf("Ingrese el tipo: ");
    printf("\n1. Girasol");
    printf("\n2. Oliva");
    printf("\n3. Maiz");
    printf("\n4. Mezcla");
    printf("\nResultado: ");
    scanf("%d", &tipoAceite);

    if (tipoAceite < 1 || tipoAceite > 4) {
        printf("Ingrese una presentacion valida\n");
    }
} while (tipoAceite < 1 || tipoAceite > 4);

    switch (tipoAceite){
        case 1:
            strcpy(tipoBuscado, "girasol");
            break;
        case 2:
            strcpy(tipoBuscado, "oliva");
            break;
        case 3:
            strcpy(tipoBuscado, "maiz");
            break;
        case 4:
            strcpy(tipoBuscado, "mezcla");
            break;
    }

    printf("\nResultados para tipo: '%s' ml:\n", tipoBuscado);
    printf("---------------------------------------------------\n");
    printf("| Codigo | Litros | Tipo         | Precio | Stock |\n");
    printf("---------------------------------------------------\n");

    for (int i=0 ; i < cantidadAceites; i++) {
        if (strcmp(inventario[i].tipo, tipoBuscado) == 0) {
            litros = (float)inventario[i].presentacion / 1000;

            printf("|  %d  | %.2f L | %s | %.2f | %d |\n",
                  inventario[i].codigo,
                  litros,
                  inventario[i].tipoOriginal,
                  inventario[i].precio,
                  inventario[i].stock);
            stockTotal = stockTotal + inventario[i].stock;
            bandera = 1;
            }
    }
    printf("--------------------------------------------------\n");
    if (bandera) {
        printf("Stock total: '%d' \n", stockTotal);
    } else {
        printf("No se encontraron aceites de tipo: '%s'\n", tipoBuscado);
    }
}


void porcentajesAceites(producto inventario[], int cantidadAceites) {
    float stockTotal =0;
    float porcentaje;
    float contador=0;

    printf("\nResultados de Aceites de 1500 ml y menores a $4800:\n");
    printf("----------------------------------------------\n");
    printf("| Codigo | Tipo         | Precio | Stock |\n");
    printf("----------------------------------------------\n");

    for (int i=0 ; i < cantidadAceites; i++) {

        if (inventario[i].presentacion == 1500 && inventario[i].precio < 4800) {

            printf("| %6d | %s | %.2f | %d |\n",
                  inventario[i].codigo,
                  inventario[i].tipoOriginal,
                  inventario[i].precio,
                  inventario[i].stock);

            contador = contador + 1;

        }
        stockTotal = stockTotal + 1;
    }
    printf("--------------------------------------------------\n");
    porcentaje = (contador / stockTotal)  * 100;
    printf("El porcentaje de Aceites de 1500 ml y menores a 4800 es del '%f'%", porcentaje);

}
