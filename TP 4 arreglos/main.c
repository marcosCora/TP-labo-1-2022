#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "pila.h"


///CONSTANTES

const int ESC = 27;
const int DIM = 15;

///FUNCIONES
void muestraMenu();
int cargaArreglo(int a[], int dim);
void muestraArreglo(int a[], int v);
int sumaArray(int a[], int v);
void arreglo2Pila(int a[], int v, Pila *p);
int cargaArregloRandom(int a[], int dim);
int cargaArregloFloat(float a[], int dim);
void muestraArregloFloat(float a[], int v);
float sumaArrayFloat(float a[], int v);
int cargaArregloChar(char a[], int dim);
void muestraArregloChar(char a[], int v);
int buscaElementoArrayChar(char a[], int v, char elemento);
int insertElementoArrayChar(char arrayOrdenado[], int v, char aInsertar);
int insertElementoArrayInt(int arrayOrdenado[], int v, int aInsertar);
int buscaMayotArray(int array[], int v);
char buscaMayotArrayChar(char array[], int v);
int capicua(int array[], int v);
void intercambioVariables(int *a, int *b);
void invierteArrayInt(int array[], int v);
int buscaMenorPosArray(int array[], int v, int i);
int ordenamientoSeleccionArrayInt(int array[], int v);
void ordenamientoInsercionArrayInt(int array[], int v);
void insertDatoArrayInt(int array[], int v, int dato);
int intercaloArreglosCharOrdenado(char ordenado1[], char ordenado2[], char destino[], int vOrdenado1, int vOrdenado2, int dimDestino);
int sumaAnterioresArray(int array[], int sumado[], int vArray, int dimSumado);


int main()
{
    char opcion;
    srand(time(NULL));
    int suma = 0;///contiene la suma de una arreglo
    float sumaArregloFloat = 0; ///contiene la suma de un arreglo de tipo floar
    int flag = 0;///bandera = 0 negativo // 1 = positivo
    char elemento;
    int elementoInt = 0;

    ///arrays
    int array[DIM];
    int vArray = 0;
    float arrayFloat[DIM];
    int vArrayFloat = 0;
    char arrayChar[DIM];
    int vArrayChar = 0;
    char ordenado1[4] = {'a', 'c', 'e', 'g'};
    char ordenado2[4] = {'b', 'd', 'f', 'h'};
    int vOrdenado1 = 4;
    int vOrdenado2 = 4;
    char destino[DIM];
    int vDestino = 0;
    int arraySumado[DIM];
    int vArraySumado = 0;




    ///pilas
    Pila dada;
    inicpila(&dada);

    do
    {
        system("cls");
        muestraMenu();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case 49:

            vArray = cargaArreglo(array, DIM);

            break;
        case 50:

            printf("ESTE ES EL ARREGLO:\n\n");
            muestraArreglo(array, vArray);
            opcion = getch();

            break;
        case 51:

            suma = sumaArray(array, vArray);
            printf("La suma del arreglo es de %d\n", suma);

            opcion = getch();

            break;
        case 52:

            arreglo2Pila(array, vArray, &dada);
            printf("Esta es la pila con los elementos del array:");
            mostrar(&dada);
            opcion = getch();

            break;
        case 53:

            vArray = cargaArregloRandom(array, DIM);
            printf("El arreglo se cargor random");
            opcion = getch();

            break;
        case 54:

            vArrayFloat = cargaArregloFloat(arrayFloat, DIM);

            break;
        case 55:

            printf("ESTE ES EL ARREGLO FLOAT:\n\n");
            muestraArregloFloat(arrayFloat, vArrayFloat);
            opcion = getch();

            break;
        case 56:

            sumaArregloFloat = sumaArrayFloat(arrayFloat, vArrayFloat);
            printf("La suma del arreglo de tipo FLOAT es de %.2f\n", sumaArregloFloat);
            opcion = getch();

            break;
        case 57:

            vArrayChar = cargaArregloChar(arrayChar, DIM);

            break;
        case 97:

            printf("Este es el arreglo de tipo char:");
            muestraArregloChar(arrayChar, vArrayChar);
            opcion = getch();

            break;
        case 98:

            printf("Ingrese letra a buscar: ");
            fflush(stdin);
            scanf("%c", &elemento);

            flag = buscaElementoArrayChar(arrayChar, vArrayChar, elemento);

            if(flag == 1)
            {
                printf("\nEl elemento %c se encuentra en arreglo\n", elemento);
            }
            else
            {
                printf("\nEl elemento %c NO se enceuntra en el arreglo\n", elemento);
            }
            opcion = getch();

            break;
        case 99:

            muestraArregloChar(arrayChar, vArrayChar);

            printf("Ingrese una letra a insertar en el arreglo: ");
            fflush(stdin);
            scanf("%c", &elemento);

            vArrayChar = insertElementoArrayChar(arrayChar, vArrayChar, elemento);

            printf("\n\nEste es el arreglo con el elemento insertado:\n");
            muestraArregloChar(arrayChar, vArrayChar);
            opcion = getch();

            break;
        case 100:

            muestraArreglo(array, vArray);

            printf("\nIngrese el numero a insertar en el arreglo: ");
            scanf("%d", &elementoInt);

            vArray = insertElementoArrayInt(array, vArray, elementoInt);
            printf("\n\nEste es el arreglo con el elemento insertado:\n");
            muestraArreglo(array, vArray);
            opcion = getch();

            break;
        case 101:

            elemento = buscaMayotArrayChar(arrayChar, vArrayChar);
            printf("\nEl mayor elemento del arreglo es %c\n", elemento);

            opcion = getch();

            break;
        case 102:

            printf("Este es el arreglo:");
            muestraArreglo(array, vArray);

            flag = capicua(array, vArray);

            if(flag == 1)
            {
                printf("\nEl arreglo es capicua\n");
            }
            else
            {
                printf("\nEl arreglo NO es capicua\n");
            }

            opcion = getch();
            break;
        case 103:

            printf("Arreglo original:");
            muestraArreglo(array, vArray);

            invierteArrayInt(array, vArray);

            printf("\n\nArreglo invertido:");
            muestraArreglo(array, vArray);
            opcion = getch();

            break;
        case 104:

            printf("Array desordenado:\n");

            muestraArreglo(array, vArray);

            vArray = ordenamientoSeleccionArrayInt(array, vArray);

            printf("\n\nArray ordenado por seleccion:\n");
            muestraArreglo(array, vArray);

            opcion = getch();

            break;
        case 105:

            printf("Array desordenado:\n");

            muestraArreglo(array, vArray);

            ordenamientoInsercionArrayInt(array, vArray);

            printf("\n\nArray ordenado por insercion:\n");
            muestraArreglo(array, vArray);

            opcion = getch();

            break;
        case 106:

            printf("Arreglo ordenado 1:");
            muestraArregloChar(ordenado1, vOrdenado1);
            printf("\nArreglo ordenado 2:");
            muestraArregloChar(ordenado2, vOrdenado2);

            vDestino = intercaloArreglosCharOrdenado(ordenado1, ordenado2, destino, vOrdenado1, vOrdenado2, DIM);
            printf("\nArreglo detino ordenado:");
            muestraArregloChar(destino, vDestino);


            opcion = getch();

            break;
        case 107:

            printf("Arreglo sins sumar:");
            muestraArreglo(array, vArray);

            vArraySumado = sumaAnterioresArray(array, arraySumado, vArray, DIM);

            printf("\nArreglo nuevo ya sumado:");
            muestraArreglo(arraySumado, vArraySumado);


            opcion = getch();

            break;

        }
        ///opcion = getch();
    }

    while(opcion != ESC);

    return 0;
}



void muestraMenu()
{
    printf("\t\t\tSELECCIONE UNA OPCION\n\n");
    printf("1. Carga un array INT por teclado (ejercicio 1)\n");
    printf("2. Muestra un array(ejercicio 2)\n");
    printf("3. Suma un array de enteros (ejercicio 3\n");
    printf("4. Copia un array en una pila (ejercicio 4)\n");
    printf("5. Carga array random \n");
    printf("6. Carga un array de tipo FLOAT\n");
    printf("7. Muestra un array de tipo FLOAT\n");
    printf("8. Suma arrey de tipo float\n");
    printf("9. Carga un array de tipo CHAR\n");
    printf("A. Muestra un array de tipo CHAR\n");
    printf("B. Busca un elemento en el arreglo de caracteres (ejercicio 6)\n");
    printf("C. Inserta un elemento en un arreglo char ordenado ABC (ejercicio 7)\n");
    printf("D. Inserta un elemento en un arreglo int ordenado\n");
    printf("E. Realizar una funcion que obtenga el maximo caracter de un arreglo dado. (ejercicio 8)\n");
    printf("F. Realizar una funcion que determine si un arreglo es capicua. (ejercicio 9)\n");
    printf("G. Realizar una funcion que invierta los elementos de un arreglo. (sin utilizar un arreglo auxiliar) (ejercicio 10)\n");
    printf("H. Ordenamiento por seleccion array INT (ejercicio 10).\n");
    printf("I. Ordenamiento por insercion array INT (ejercicio 10).\n");
    printf("J. intercala dos arreglos char ordenados (ejercicio 12)\n");
    printf("K. ejercicio 13\n");
    printf("\n");


    printf("ESC PARA SALIR");
}


///funcion que carga por teclado un arreglo
///recibe el arreglo y su dimension

int cargaArreglo(int a[], int dim)
{
    int v = 0;///validos del arreglo
    char opcion = 'NULL';


    while(v < dim && opcion != ESC)
    {
        printf("Ingrese un numero a cargar en el array: ");
        scanf("%d", &a[v]);

        printf("ESC para salir\n");
        opcion = getch();
        v++;
    }
    return v;
}

///funcion que muestra un arreglo
///recibe validos y el arreglo

void muestraArreglo(int a[], int v)
{

    for(int i = 0; i<v; i++)
    {
        printf("|%d| ", a[i]);
    }
}



///funcion que suma los elementos de un arreglo de enteros
///recibe el arreglo y los validos

int sumaArray(int a[], int v)
{
    int suma = 0;

    for(int i = 0; i<v; i++)
    {
        suma += a[i];
    }

    return suma;
}

///funcion que pasa de un arreglo a una pila
///recibe un arreglo, validos y la pila

void arreglo2Pila(int a[], int v, Pila *p)
{

    for(int i = 0; i<v; i++)
    {
        apilar(p, a[i]);
    }
}


///funcion que carga un arreglo random

int cargaArregloRandom(int a[], int dim)
{
    int v = 0;

    for(v = 0; v<dim; v++)
    {

        a[v] = rand()%21;
    }

    return v;
}

///funcion que carga por teclado un arreglo de tipo FLOAT
///recibe el arreglo y su dimension

int cargaArregloFloat(float a[], int dim)
{
    int v = 0;///validos del arreglo
    char opcion = 'NULL';


    while(v < dim && opcion != ESC)
    {
        printf("Ingrese un numero a cargar en el array: ");
        scanf("%f", &a[v]);

        printf("ESC para salir\n");
        opcion = getch();
        v++;
    }
    return v;
}

///funcion que muestra un arreglo de tipo FLOAT
///recibe validos y el arreglo

void muestraArregloFloat(float a[], int v)
{

    for(int i = 0; i<v; i++)
    {
        printf("|%.2f| ", a[i]);
    }
}

///funcion que suma los elementos de un arreglo de tipo float
///recibe el arreglo y los validos

float sumaArrayFloat(float a[], int v)
{
    float suma = 0;

    for(int i = 0; i<v; i++)
    {
        suma += a[i];
    }

    return suma;
}


///funcion que carga un array de tipo char
///recibe el array y su dimension

int cargaArregloChar(char a[], int dim)
{
    int v = 0;
    char opcion = 'NULL';

    while(v<dim && opcion != ESC)
    {
        printf("Ingrese una letra: ");
        fflush(stdin);
        scanf("%c", &a[v]);

        printf("ESC para salir\n");
        opcion = getch();
        v++;
    }

    return v;
}


///funcion que muestra un arreglo de tipo char
///recibe validos y el arreglo

void muestraArregloChar(char a[], int v)
{
    printf("\n");
    for(int i = 0; i<v; i++)
    {
        printf("|%c| ", a[i]);
    }
    printf("\n");
}


///funcion que busca un elemento en un arreglo de caracteres
///recibe el arreglo y sus validos
///retorna

int buscaElementoArrayChar(char a[], int v, char elemento)
{

    int flag = 0;///0 no se encuentra el elemento 1 se encuentra el elemento
    int i = 0;

    while(i<v && flag == 0)
    {
        if(a[i] == elemento)
        {
            flag = 1;
        }
        i++;
    }

    return flag;
}


///funcion que inserta un caracter en un arreglo ordenado
///ejercicio 7
///recibo el arreglo ordenado y retorna sus validos


int insertElementoArrayChar(char arrayOrdenado[], int v, char aInsertar)
{

    int i = 0;
    int f = v-1; ///varibale que contiene la posicion del ultimo elemento cargado en el arreglo osea validos -1

    while(i<=f && arrayOrdenado[f] > aInsertar)
    {
        arrayOrdenado[f+1] = arrayOrdenado[f];
        f--;
    }

    arrayOrdenado[f+1] = aInsertar;

    return v+1;
}


///funcion que inserta un entero en un arreglo ordenado
///recibo el arreglo ordenado y retorna sus validos


int insertElementoArrayInt(int arrayOrdenado[], int v, int aInsertar)
{

    int i = 0;
    int f = v-1; ///varibale que contiene la posicion del ultimo elemento cargado en el arreglo osea validos -1

    while(i <= f && arrayOrdenado[f] > aInsertar)
    {
        arrayOrdenado[f+1] = arrayOrdenado[f];
        f--;
    }

    arrayOrdenado[f+1] = aInsertar;

    return v+1;
}


///funcion que busca el mayor elemento de un arreglo int
///retorna el mayor elemento

int buscaMayotArray(int array[], int v)
{
    int i = 0;///subindice del arreglo
    int mayor = array[i];

    for(i = 1; i<v; i++)
    {
        if(mayor < array[i])
        {
            mayor = array[i];
        }
    }
    return mayor;
}


///ejercicio 8
///funcion que busca el mayor elemento de un arreglo char
///retorna el mayor elemento

char buscaMayotArrayChar(char array[], int v)
{
    int i = 0;///subindice del arreglo
    char mayor = array[i];

    for(i = 1; i<v; i++)
    {
        if(mayor < array[i])
        {
            mayor = array[i];
        }
    }
    return mayor;
}




///ejercicio 9
///funcion que determina si un arreglo es capicua
///retorna 1 si es capicua 0 si no es capicua

int capicua(int array[], int v)
{
    int flag = 1;
    int i = 0;
    int f = v-1;

    while(i < v && f >= 0 && flag == 1)
    {
        if(array[i] == array[f])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        i++;
        f--;
    }
    return flag;
}

///ejercicio 10
///funcion que invierte un arreglo
///retorna sus validos

void invierteArrayInt(int array[], int v)
{

    int i = 0;
    int f = v-1;
    int flag = 1;
    int aux = 0;


    while(i<v && flag == 1)
    {
        aux = array[i];
        array[i] = array[f];
        array[f] = aux;

        i++;
        f--;

        if(i == f)
        {
            flag = 0;
        }

    }

}

///funcion de intercambio de variables

void intercambioVariables(int *a, int *b)
{
    int aux = 0;
    aux = *a;
    *a = *b;
    *b = aux;
}


///ejercicio 10
///A

///funcion que busca la posicion donde se encuentra el menor elemenro de un arreglo de eneteros
///recibe el array, sus validos y la posisicion

int buscaMenorPosArray(int array[], int v, int i)
{
    int menor = array[i];
    int posMenor = i;

    for(i = i+1; i<v; i++)
    {
        if(menor > array[i])
        {
            menor = array[i];
            posMenor = i;
        }
    }
    return posMenor;
}

///funcion que ordena el arreglo llamando a la funcion que busca la posicion del menor

int ordenamientoSeleccionArrayInt(int array[], int v)
{
    int i = 0;
    int posMenor = 0;
    int aux = 0;

    while(i < v)
    {
        posMenor = buscaMenorPosArray(array, v, i);
        aux = array[i];///alameceno el menor del arreglo
        array[i] = array[posMenor];
        array[posMenor] = aux;


        i++;
    }

    return v;
}


///B

///funcion que inserta elemento en array

void insertDatoArrayInt(int array[], int v, int dato)
{
    int i = v;

    while(i>=0 && array[i] > dato)
    {
        array[i+1] = array[i];
        i--;
    }

    array[i+1] = dato;

}


///funcion que ordena un arreglo por insercion

void ordenamientoInsercionArrayInt(int array[], int v)
{
    int i = 0;

    while(i < v)
    {
        insertDatoArrayInt(array, i, i+1);
        i++;
    }

}

///ejercicio 12
///funcion que recibe dos arreglos ordenados y crea uno con los mismos valores intercalados entre si
///retorna los validos

int intercaloArreglosCharOrdenado(char ordenado1[], char ordenado2[], char destino[], int vOrdenado1, int vOrdenado2, int dimDestino)
{
    int i = 0;///sub indice ordenado 1
    int n = 0;///sub indice ordenado 2
    int vDestino = 0;///sub indice destino


    while(vDestino < dimDestino && i < vOrdenado1 && n < vOrdenado2)
    {
        destino[vDestino] = ordenado1[i];
        vDestino++;
        destino[vDestino] = ordenado2[n];
        vDestino++;
        i++;
        n++;
    }
    return vDestino;
}


///ejercicio 13

int sumaAnterioresArray(int array[], int sumado[], int vArray, int dimSumado)
{
    int i = 0;
    int vSumado = 0;

    while(i < vArray && vSumado < dimSumado)
    {
        if(vSumado == 0)
        {
            sumado[vSumado] = array[i];
            vSumado++;
            i++;
        }
        sumado[vSumado] = sumado[vSumado-1] + array[i];
        vSumado++;
        i++;
    }
   return vSumado;

}

















