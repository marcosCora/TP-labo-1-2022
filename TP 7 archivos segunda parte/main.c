#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>

///ESTRUCTURA

typedef struct
{
    int legajo;
    char nombreYapellido[50];
    int edad;
    int anio;
} stAlumno;

///CONSTANTES

const int ESC = 27;
const int DIM = 15;
#define archiAlumnos "archivoAlumnos.bin"

///PROTOTIPADOS

void mustraMenu();
stAlumno cargaUnAlumno();
void cargaAlumnosArchi(char nombreArch[]);
void muestraArchDeAlumnos(char nombreArch[]);
void agregaUnAlumnoArchivo(char nombreArch[]);


int main()
{
    char opcion;

    do
    {
        system("cls");
        mustraMenu();
        opcion=getch();
        system("cls");

        switch (opcion)
        {

        case 49:

            cargaAlumnosArchi(archiAlumnos);

            break;
        case 50:

            printf("Este es el archivo de alumnos:\n\n");
            muestraArchDeAlumnos(archiAlumnos);
            opcion = getch();
            break;
        case 51:

            agregaUnAlumnoArchivo(archiAlumnos);
            printf("\n\nSe agrego el alumno al final del archivo.\n");
            opcion = getch();
            break;

        }



    }
    while (opcion!=ESC);

    return 0;
}

///muestra el menu

void mustraMenu()
{
    printf("\t\t\t\t QUE FUNCION DESEA RELIZAR?\n\n");
    printf("1. Carga archivo de alumnos. (4)\n");
    printf("2. Muestra archivo de alumnos. (5)\n");
    printf("3. Agrega UN alumno al final del archivo. (6)\n ");
    printf("\n ");
    printf("\n ");
    printf("\n");
    printf("\n");
    printf("ingrese numero de funcion o ESC para salir: ");

}

///funcion que carga un alumno

stAlumno cargaUnAlumno()
{
    stAlumno a;

    printf("Ingrese el numero de legajo....: "),
    scanf("%d", &a.legajo);

    printf("Ingrese nombre y apellido......: ");
    fflush(stdin);
    gets(a.nombreYapellido);

    printf("Ingrese su edad................: ");
    scanf("%d", &a.edad);

    printf("Ingrese el a%co................:  ", 164);
    scanf("%d", &a.anio);

    return a;

}

///EJERCICIO 4
///carga en un archivo binario regustros de tipo alumno

void cargaAlumnosArchi(char nombreArch[])
{
    stAlumno a;
    FILE *arch = fopen(nombreArch, "ab");
    char opcion = 'NULL';

    if(arch)
    {
        while(opcion != ESC)
        {
            a = cargaUnAlumno();
            fwrite(&a, sizeof(stAlumno), 1, arch);

            printf("\nESC para salir // OTRO para continuar la carga.\n\n");
            opcion = getch();
        }


        fclose(arch);
    }
}


///funcion que muestra un alumno

void muestraUnAlumno(stAlumno a)
{
    printf("----------------------------------------\n");
    printf("LEGAJO..............: %d \n", a.legajo);
    printf("NOMBRE Y APELLIDO...: %s \n", a.nombreYapellido);
    printf("EDAD................: %d \n", a.edad);
    printf("A%cO.................: %d \n", 164, a.anio);
    printf("----------------------------------------\n");
}

///EJERCICIO 5

void muestraArchDeAlumnos(char nombreArch[])
{
    stAlumno a;
    FILE *arch = fopen(nombreArch, "rb");

    if(arch)
    {

        while(fread(&a, sizeof(stAlumno), 1, arch) > 0)
        {
            muestraUnAlumno(a);
        }

        fclose(arch);
    }
}


///EJERCICIO 6

void agregaUnAlumnoArchivo(char nombreArch[])
{
    stAlumno a;
    FILE *arch = fopen(nombreArch, "ab");

    if(arch)
    {
        a = cargaUnAlumno();
        fwrite(&a, sizeof(stAlumno), 1, arch);
        fclose(arch);
    }
}

















