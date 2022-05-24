#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>

///CONSTANTES

const int ESC = 27;
const int DIM = 20;

///PROTOTIPADOS

void mustraMenu();
int cargaRegistros(int legajo[], int anios[], int caracteres, char nombre[][caracteres], int dim);
void muestraRegistros(int legajos[], int anios[], int caracteres, char nombre[][caracteres], int v);
int buscaPosLegajo(int legajos[], int v, int legajoABuscar);
void muestraRegistroElejido(int legajos[], int anios[], int caracteres, char nombre[][caracteres], int v);
int buscaPosMenorNombre(int caracteres, char nombre[][caracteres], int v, int i);
int ordenamientoXSeleccionRegistros(int legajos[], int anios[], int caracteres, char nombres[][caracteres], int v);


int main()
{
    char opcion;

    ///arreglos
    int legajos[DIM];
    int anios[DIM];
    char nombre[DIM][30];
    int vArreglos = 0;

    do
    {
        system("cls");
        mustraMenu();
        opcion=getch();
        system("cls");

        switch (opcion)
        {

        case 49:

            printf("Cargando registros:\n\n");
            vArreglos = cargaRegistros(legajos, anios, 30, nombre, DIM);
            ///opcion = getch();
            break;
        case 50:

            printf("Registros:\n\n");
            muestraRegistros(legajos, anios, 30, nombre, vArreglos);
            opcion = getch();
            break;
        case 51:

            muestraRegistroElejido(legajos, anios, 30, nombre, vArreglos);

            break;
        case 52:

            vArreglos = ordenamientoXSeleccionRegistros(legajos, anios, 30, nombre, vArreglos);
            printf("Estos son los arreglos ordenados:\n\n");
            muestraRegistros(legajos, anios, 30, nombre, vArreglos);
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
    printf("1. Carga arreglos paralelos (ejercicio 1)\n");
    printf("2. Muestra arreglos paralelos de alumnos (ejercicio 5)\n");
    printf("3. Busca alumno por legajo\n");
    printf("4. Ordena los arreglos por seleccion\n");
    printf("\n");
    printf("ingrese numero de funcion o ESC para salir: ");

}


///EJERCICIO 1
///carga 3 arreglos en paralelos
///retorna los validos de los 3
int cargaRegistros(int legajo[], int anios[], int caracteres, char nombre[][caracteres], int dim)
{
    int v = 0;
    char opcion = 'NULL';

    while(v<dim && opcion != ESC)
    {
        printf("\nNUMERO DE LEGAJO.............: ");
        fflush(stdin);
        scanf("%d", &legajo[v]);

        printf("NOMBRE.......................: ");
        fflush(stdin);
        ///scanf("%s", &nombre[v]);
        gets(nombre[v]);

        printf("a%co:.........................: ", 164);
        fflush(stdin);
        scanf("%d", &anios[v]);

        printf("ESC para salir \n");
        opcion = getch();
        v++;
    }

    return v;
}

///EJERCICIO 5
///funcion que muestra todos los paralelos como registros

void muestraRegistros(int legajos[], int anios[], int caracteres, char nombre[][caracteres], int v)
{
    int i = 0;

    for(i = 0; i<v; i++)
    {
        printf("------------------------------------------------------\n");
        printf("LEGAJO.............: %d\n", legajos[i]);
        printf("NOMBRE.............: %s\n", nombre[i]);
        printf("a%co...............: %d\n", 164, anios[i]);
    }
    printf("------------------------------------------------------\n");
}

///EJERCICIO 2
///funcion funcion que busca dentro del arreglo de legajos el menor
///retorna la posicion del menor

int buscaPosLegajo(int legajos[], int v, int legajoABuscar)
{
    int i = 0;
    int flag = 0;
    int posBuscado = -1;///se almacena la posicion del elemento que se busca

    while(i<v && flag == 0)
    {
        if(legajos[i] == legajoABuscar)
        {
            posBuscado = i;
            flag = 1;
        }
        i++;
    }

    return posBuscado;///si retorna -1 significa que no se encuentra ese numero de legajo
}


///EJERCICIO 3
///invoca al ejercicio 2 y muestra por pantalla

void muestraRegistroElejido(int legajos[], int anios[], int caracteres, char nombre[][caracteres], int v)
{
    char opcion = 'NULL';
    int legajoABuscar = 0;
    int posLegajo = 0;

    while(opcion != ESC)
    {
        ///system("cls");
        printf("Ingrese el numero de legajo a buscar: ");
        scanf("%d", &legajoABuscar);
        system("cls");

        posLegajo = buscaPosLegajo(legajos, v, legajoABuscar);

        if(posLegajo != -1)
        {
            printf("Este es el registro del alumno:\n");
            printf("LEGAJO.............: %d\n", legajos[posLegajo]);
            printf("NOMBRE.............: %s\n", nombre[posLegajo]);
            printf("a%co...............: %d\n", 164, anios[posLegajo]);
        }
        else
        {
            printf("El alumno con el legajo que usted busca no se encuentra.\n\n");
        }

        printf("ESC para salir - OTRA para seguir buscando.\n");
        ///system("cls");
        opcion = getch();

    }
}



///EJERCICIO 4

int buscaPosMenorNombre(int caracteres, char nombre[][caracteres], int v, int i)
{
    int posMenor = i;


    for(i = i+1; i<v; i++)
    {
        if(strcmpi(nombre[posMenor], nombre[i]) > 0)
        {
            posMenor = i;
        }
    }

    return posMenor;
}


int ordenamientoXSeleccionRegistros(int legajos[], int anios[], int caracteres, char nombres[][caracteres], int v)
{
    int i = 0;
    int posMenor = 0;
    int aux = 0;
    char auxNombre[20][caracteres];

    for(i = 0; i<v; i++)
    {
        posMenor = buscaPosMenorNombre(caracteres, nombres, v, i);
        aux = legajos[i];
        legajos[i] = legajos[posMenor];
        legajos[posMenor] = aux;

        aux = anios[i];
        anios[i] = anios[posMenor];
        anios[posMenor] = aux;

        strcpy(auxNombre, nombres[i]);
        strcpy(nombres[i], nombres[posMenor]);
        strcpy(nombres[posMenor], auxNombre);
    }

    return i;
}




















































