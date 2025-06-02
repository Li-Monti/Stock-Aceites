
#include <stdio.h>
#include <string.h>
#include "estructura.h"
#include "estructuraFecha.h"
void ordenarPorVencimiento(producto inventario[], int cantidadAceites) {
    producto aux;


    for (int i = 0; i < cantidadAceites - 1; i++) {
        for (int j = 0; j < cantidadAceites - i - 1; j++) {

            Fecha f1 = inventario[j].fechaVencimiento;
            Fecha f2 = inventario[j + 1].fechaVencimiento;

            int fecha1 = f1.anio * 10000 + f1.mes * 100 + f1.dia;
            int fecha2 = f2.anio * 10000 + f2.mes * 100 + f2.dia;

            if (fecha1 > fecha2) {
                aux = inventario[j];
                inventario[j] = inventario[j + 1];
                inventario[j + 1] = aux;
            }
        }
    }
    printf("-----------------------------------------------------------\n");
    printf("| Codigo | Tipo         | Precio | Stock |   Fecha       |\n");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < cantidadAceites; i++) {
        printf("| %6d | %s | %.2f | %d | %d-%d-%d |\n",
                  inventario[i].codigo,
                  inventario[i].tipoOriginal,
                  inventario[i].precio,
                  inventario[i].stock,
                  inventario[i].fechaVencimiento.anio,
                  inventario[i].fechaVencimiento.mes,
                  inventario[i].fechaVencimiento.dia);

    }

    printf("-----------------------------------------------------------\n");
}

int compararFechas(Fecha f1, Fecha f2) {
    if (f1.anio < f2.anio) {
        return -1;
    }
    if (f1.anio > f2.anio) {
        return 1;
    }

    if (f1.mes < f2.mes) {
        return -1;
    }
    if (f1.mes > f2.mes) {
        return 1;
    }

    if (f1.dia < f2.dia) {
        return -1;
    }
    if (f1.dia > f2.dia) {
        return 1;
    }

    return 0;
}

void stockCocineroVencimiento(producto inventario[], int cantidadAceites) {
    Fecha limite = {2025, 9, 12};
    int stockTotal = 0;
    int encontrado = 0;

    printf("\nAceites 'Cocinero' con vencimiento anterior al 12/09/2025:\n");
    printf("------------------------------------------------------------------\n");
    printf("| Codigo | Tipo         | Precio | Stock | Vencimiento |\n");
    printf("------------------------------------------------------------------\n");

    for (int i = 0; i < cantidadAceites; i++) {
        if (strcmp(inventario[i].marca, "cocinero") == 0 &&
            compararFechas(inventario[i].fechaVencimiento, limite) < 0) {

            printf("| %d | %s | %.2f | %5d | %d/%d/%d |\n",
                inventario[i].codigo,
                inventario[i].tipoOriginal,
                inventario[i].precio,
                inventario[i].stock,
                inventario[i].fechaVencimiento.dia,
                inventario[i].fechaVencimiento.mes,
                inventario[i].fechaVencimiento.anio
            );

            stockTotal += inventario[i].stock;
            encontrado = 1;
            }
    }

    printf("------------------------------------------------------------------\n");

    if (encontrado) {
        printf("Stock total de aceites 'Cocinero' con vencimiento anterior a 12/09/2025: %d unidades\n", stockTotal);
    } else {
        printf("No se encontraron aceites 'Cocinero' con esa condición.\n");
    }
}