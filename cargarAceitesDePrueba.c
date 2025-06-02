#include <string.h>
#include "estructura.h"
#include "estructura.h"
#include <stdio.h>
#include <string.h>
int cargarAceitesDePrueba(producto inventario[]) {
    // Caso 1
    inventario[0] = (producto){10, "cocinero", "Cocinero", 1000, "girasol", "Girasol", 4590.50, {2025, 9, 10}, 20};

    // Caso 2
    inventario[1] = (producto){1002, "natura", "Natura", 1500, "oliva", "Oliva", 4999.99, {2026, 1, 1}, 15};

    // Caso 3
    inventario[2] = (producto){1003, "cocinero", "Cocinero", 500, "maiz", "Maiz", 1999.99, {2025, 8, 30}, 30};

    // Caso 4
    inventario[3] = (producto){1004, "abc", "ABC", 5000, "mezcla", "Mezcla", 8500.00, {2026, 12, 31}, 10};

    // Caso 5
    inventario[4] = (producto){1005, "natura", "Natura", 750, "oliva", "Oliva", 3500.00, {2025, 9, 10}, 10};

    // Caso 6
    inventario[5] = (producto){1006, "", "", 1000, "girasol", "Girasol", 4800.00, {2025, 12, 12}, 12};

    // Caso 7
    inventario[6] = (producto){1007, "cocinero", "Cocinero", 1000, "ajonjoli", "Ajonjoli", 4700.00, {2025, 10, 15}, 8};

    // Caso 8 (precio negativo, útil para probar validaciones)
    inventario[7] = (producto){1008, "abc", "ABC", 1000, "maiz", "Maiz", -100.00, {2025, 9, 20}, 10};

    // Caso 9 (stock 0)
    inventario[8] = (producto){1009, "natura", "Natura", 1500, "mezcla", "Mezcla", 4999.00, {2025, 10, 10}, 0};

    // Caso 10 (fecha inválida: día 32, no lo uses en producción pero puede ser útil para probar validación de fecha si la tenés)
    inventario[9] = (producto){10, "cocinero", "Cocinero", 1000, "girasol", "Girasol", 4600.00, {2025, 1, 32}, 20};

    // Devuelve la cantidad cargada
    return 10;
}
