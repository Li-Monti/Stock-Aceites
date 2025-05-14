/* Un supermercadi quiere implementar un software que le permita tener un control sobre el stock de aceites comestibles 
en us locales.
Busca una solucion informatica para lograr eficiencia y rapidez a la hora de manipular la informacion de los productos 
considerados 

Desde la captura de requerimientos que realizo nuestro companero de equipo, pudo detectar 
que en la cadena de supermercados el aceute se caracteriza por:
    a)Codigo
    b)Marca
    c)Presentacion (500,1000,1500,5000 ml)
    d)Tipo de aceite: girasol, oliva, maiz, mezcla
    e)Precio
    f)Fecha de vencimiento (aaaammdd)
    g)Stock (unidades)

El cliente en principio no conoce la cantidad de aceites a cargar, por lo que el software deberia permitirle cargar
hasta donde lo desee

Las funcionabilidades de interes que pretende resolver el cliente a partir del software son:asm
    1.Stock disponible por marca y presentacion
    2.Stock disponible por tipo de aceite en litros
    3.Marca del aceite mas barato
    4.Stock del aceite marca "Cocinero" con fecha de vencimiento anterior al 12/09/2025
    5.Cantidad total de unidades de 1000ml
    6.Porcentaje de aceites de 1500 ml que cuestan menos de $4800
    7.Listado de stock por tipo de aceite
    8.Listado del stock por marca y presentacion ordenados por fecha de vencimiento
*/
#include<stdio.h>
#include<time.h>

    struct Producto{
        int codigo;
        char marca[15];
        int presentacion[4]; 
        char tipoAceite[4][10];
        float precio;
        time_t fechaVencimineto;
        int stock;
    } Producto;

int main(void){
    struct Producto p;
    int i=0;
    int presentaciones[] = {500, 1000, 1500, 5000};
    
    for (i; i < 6; i++){
        p.presentacion[i] = presentaciones[i];
    }
    
    char tipos[4][10]= {"girasol", "oliva", "maiz", "mezcla"};
    for (i; i < 6; i++){
        snprintf(p.tipoAceite[i], sizeof(p.tipoAceite[i]), "%s", tipos[i]);
    }

    for (i ; i < 4 ; i++){
        
        printf("* %d ml \n", p.presentacion[i]);
    }
    for (i ; i < 5 ; i++){
        
        printf("* %s ml \n", p.tipoAceite[i]);
    }
}


