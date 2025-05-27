//
// Created by Li on 5/25/2025.
//
#include<ctype.h>

void miniscula(char *cadena){
    for(int i=0; cadena[i] != '\0'; i++){
        cadena[i] = tolower(cadena[i]);
    }
}
