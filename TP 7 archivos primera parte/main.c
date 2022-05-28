#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///CONSTANTES

///const char archivoInt = 'archivoInt.bin';
#define archivoInt "archivoInt.bin"

///PROTOTIPADOS
void cargaArchivoInt(char nombreArch[30]);
void muestraArchvoInt(char nombreArch[]);
int cuentaArchvoInt(char nombreArch[]);

int main()
{
    srand(time(NULL));
    int cont = 0;

    ///EJERCICIO1
    ///cargaArchivoInt(archivoInt);
    printf("Se a cargado un archivo de enteros.\n\n");

    ///EJERCICIO 2
    printf("Este es el archivo de enteros:\n");
    muestraArchvoInt(archivoInt);

    ///EJERCICIO 3
    cont = cuentaArchvoInt(archivoInt);
    printf("\n\nEn el archivo 'archivoInt.bin' se ecnuentran %d elementos.\n\n", cont);

    return 0;
}


///EJERCICIO 1
///funcion que carga x datos int a un archivo de manera random

void cargaArchivoInt(char nombreArch[30])
{
    int num = 0;

    FILE *arch = fopen(nombreArch, "ab");

    if(arch != NULL)
    {
        for(int i = 0; i<15; i++)
        {
            num = rand()%51;
            fwrite(&num, sizeof(int), 1, arch);
        }
        fclose(arch);
    }
}


///EJERCICIO 2
///funcion que muestra por pantalla el contenido de una archivo de enteros

void muestraArchvoInt(char nombreArch[])
{
    int num = 0;

    FILE *arch = fopen(nombreArch, "rb");

    if(arch)
    {
        while(fread(&num, sizeof(int), 1, arch) > 0)
        {
            printf(" %d - ", num);
        }
        fclose(arch);
    }
}

///EJERCICIO 3
///funcion que muestra por pantalla la cantidad de elementos de una archivo de enteros

int cuentaArchvoInt(char nombreArch[])
{
    int  num = 0, cont = 0;

    FILE *arch = fopen(nombreArch, "rb");

    if(arch)
    {
        while(fread(&num, sizeof(int), 1, arch) > 0)
        {
            cont++;
        }
        fclose(arch);
    }
    return cont;
}
























