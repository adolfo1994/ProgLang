#include <stdlib.h>
#include <stdio.h> 
#include <string.h>


int main(int argc, char const *argv[])
{
    char *str;
    str = (char *) malloc(15);
    strcpy(str, "Hola Mundo\n");
    printf("Data: %s", str);
    free(str); // Si esta implentado free
    printf("Data: %s", str); //imprime Vacio ya que str no tiene contenido

    return 0;
}