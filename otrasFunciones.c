
#include<ctype.h>

void minuscula(char *cadena){
    for(int i=0; cadena[i] != '\0'; i++){
        cadena[i] = tolower(cadena[i]);
    }
}
