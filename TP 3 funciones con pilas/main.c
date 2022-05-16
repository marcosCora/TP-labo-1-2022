#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include "pila.h"

///PROTOTIPADOS

void muestraMenu();
void cargaPila(Pila * p);
void cargaPilaRand(Pila *p);
void pila2Pila(Pila * origen, Pila * destino);
void pila2PilaMismoOrden(Pila *origen, Pila *destino);
int buscaMenorPila(Pila *p);
void ordenamientoPilaXSeleccion(Pila *origen, Pila *ordenada);
void insertNumPilaOrdenada(Pila *origen, int numInsert);
void ordenamientoPilaXInsercion(Pila *origen, Pila *ordenada);
int sumaPrimeros2ElemtnosPila(Pila origen);
int sumaPila(Pila origen);
int cuentaElementosPila(Pila origen);
float promedio(int cont, int suma);
float promedioPila(Pila origen);

///CONSTANTES
const int ESC = 27;

int main()
{
    char opcion;

    Pila origen, destino, ordenada, numInsert;
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&ordenada);
    inicpila(&numInsert);

    int menorPila = 0;
    int num = 0;
    int suma = 0;
    float promedioDePila = 0;


    do
    {
        system("cls");
        muestraMenu();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case 49:

            printf("CARGANDO PILITA\n\n");
            cargaPila(&origen);

            break;
        case 50:

            cargaPilaRand(&origen);
            printf("La pila fue cargada de manera random\n");
            opcion = getch();

            break;
        case 51:

            printf("Esta es la pila origen:");
            mostrar(&origen);
            opcion = getch();

            break;
        case 52:

            pila2Pila(&origen, &destino);
            printf("PILA DESTINO:");
            mostrar(&destino);
            opcion = getch();

            break;
        case 53:

            pila2PilaMismoOrden(&origen, &destino);
            printf("PILA DESTINO (MISMO ORDEN QUE ORIGEN):");
            mostrar(&destino);
            opcion = getch();

            break;
        case 54:

            printf("Esta es la pila origen:");
            mostrar(&origen);

            menorPila = buscaMenorPila(&origen);
            printf("El menor de la pila origen es %d\n", menorPila);
            opcion = getch();

            break;
        case 55:
            printf("Esta es la pila origen:");
            mostrar(&origen);

            ordenamientoPilaXSeleccion(&origen, &ordenada);

            printf("Esta es la pila ordenada por seleccion:");
            mostrar(&ordenada);

            opcion = getch();


            break;
        case 56:

            printf("PILA ORIGEN ORDENADA:");
            mostrar(&origen);

            printf("\nIngrese numero a insertar en pila origen: ");
            scanf("%d", &num);
            apilar(&numInsert, num);
            insertNumPilaOrdenada(&origen, &numInsert);

            printf("PILA ORIGEN CON EL NUMERO INSERTADO:");
            mostrar(&origen);

            opcion = getch();

            break;
        case 57:

            printf("PILA ORIGEN:");
            mostrar(&origen);

            ordenamientoPilaXInsercion(&origen, &ordenada);

            printf("PILA ORDENADA:");
            mostrar(&ordenada);

            opcion = getch();

            break;
        case 97:

            printf("PILA ORIGEN:");
            mostrar(&origen);

            suma = sumaPrimeros2ElemtnosPila(origen);

            printf("La suma de los primeros dos elementos de la pila es de %d\n", suma);

            opcion = getch();

            break;
        case 98:

            printf("PILA ORIGEN:");
            mostrar(&origen);

            promedioDePila = promedioPila(origen);

            printf("El promedio de la pila origen es %.2f\n", promedioDePila);
            opcion = getch();

            break;
        case 99:

            break;
        }
    }
    while(opcion != ESC);



    return 0;
}


///funcion de muestra menu

void muestraMenu()
{
    printf("\t\t\t\tINGRESE EL EJERCICIO QUE QUIERE RESOLVER\n\n");
    printf("1. Hacer una funcion que permita ingresar varios elementos a una pila, tanto como quiera el usuario. \n");
    printf(" \n");
    printf("2. Carga pila de manera random.\n");
    printf(" \n");
    printf("3. Muestra pila.\n");
    printf(" \n");
    printf("4. Hacer una funcion que pase todos los elementos de una pila a otra. \n");
    printf(" \n");
    printf("5. Hacer una funcion que pase todos los elementos de una pila a otra, pero conservando el orden. \n");
    printf(" \n");
    printf("6. Hacer una funcion que encuentre el menor elemento de una pila y lo retorna.\n La misma debe eliminar ese dato de la pila. \n");
    printf(" \n");
    printf("7. Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una nueva\n pila ordenada. Usar la funcion del ejercicio 4. (Ordenamiento por selección) \n");
    printf(" \n");
    printf("8. Hacer una funcion que inserta en una pila ordenada un nuevo elemento, conservando el ordende ésta. \n");
    printf(" \n");
    printf("9. Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere unanueva pila ordenada. Usar la función del ejercicio 6. (Ordenamiento por inserción) \n");
    printf(" \n");
    printf("A. Hacer una funcion que sume y retorne los dos primeros elementos de una pila (tope y anterior),\nsin alterar su contenido.\n");
    printf(" \n");
    printf("B. Hacer una funcion que calcule el promedio de los elementos de una pila, para ello hacer tambiénuna\n función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatrofunciones, y la función que calcula el promedio invoca a las otras 3. \n");
    printf(" \n");
    printf("C. Hacer una funcion que reciba una pila con números de un solo dígito (es responsabilidad dequien\n usa el programa) y que transforme esos dígitos en un número decimal. Por ejemplo, la pila: \n");
    printf(" \n");
    printf("ESC PARA SALIR \n");
}

///funcion que carga una pila por teclado

void cargaPila(Pila * p)
{
    char opcion;
    int num = 0;

    do
    {
        printf("Ingrese numero a cargar en la pila: ");
        scanf("%d", &num);
        apilar(p, num);

        printf("ESC para salir\n");
        opcion = getch();

    }
    while(opcion != ESC);
}


///fundion que carga pila random con 15 elementos

void cargaPilaRand(Pila *p)
{
    srand(time(NULL));

    for(int i=0; i<10; i++)
    {
        apilar(p, (rand()%50)+1);
    }
}


///funcion de pasaje de pilas
///pasa los valores de una pila a otra

void pila2Pila(Pila *origen, Pila *destino)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }

}

///funcion de pasaje de pilas
///pasa los valores de una pila a otra conservando el orden

void pila2PilaMismoOrden(Pila *origen, Pila *destino)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(origen))
    {
        apilar(&aux, desapilar(origen));
    }

    while(!pilavacia(&aux))
    {
        apilar(destino, desapilar(&aux));
    }

}

///funcion que buca menor elemento en una pila
///retorna el menor valor de pila

int buscaMenorPila(Pila *p)
{
    int menor = 0;
    Pila aux, pilaMenor;
    inicpila(&aux);
    inicpila(&pilaMenor);

    if(!pilavacia(p))
    {
        apilar(&pilaMenor, desapilar(p));

        while(!pilavacia(p))
        {
            if(tope(p) < tope(&pilaMenor))
            {
                apilar(&aux, desapilar(&pilaMenor));
                apilar(&pilaMenor, desapilar(p));
            }
            else
            {
                apilar(&aux, desapilar(p));
            }
        }
    }

    menor = tope(&pilaMenor);
    pila2Pila(&aux, p);

    return menor;
}



///funcion que ordena una pila por seleccion

void ordenamientoPilaXSeleccion(Pila *origen, Pila *ordenada)
{
    int menor = 0;

    while(!pilavacia(origen))
    {
        menor = buscaMenorPila(origen);
        apilar(ordenada, menor);
    }
}

///funcion que inserta un elemento en una pila ordenada

void insertNumPilaOrdenada(Pila *origen, int numInsert)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(origen) && tope(origen) > numInsert)
    {
       apilar(&aux, desapilar(origen));
    }

    apilar(origen, numInsert);

    pila2Pila(&aux, origen);
}

///funcion de ordenameinto por insercion
///recibe la pila desordenada y la pila a cargar ordenada

void ordenamientoPilaXInsercion(Pila *origen, Pila *ordenada)
{
    Pila aux;
    inicpila(&aux);
    int numInsert = 0;

    while(!pilavacia(origen))
    {
        numInsert = desapilar(origen);
        insertNumPilaOrdenada(ordenada, numInsert);
    }
}


///funcion que suma primeros dos elementos de una pila
///retorna la suma

int sumaPrimeros2ElemtnosPila(Pila origen)
{
    int suma = 0;
    Pila aux;
    inicpila(&aux);
    int cont = 0;

    while(!pilavacia(&origen) && cont<2)
    {
        suma += tope(&origen);
        apilar(&aux, desapilar(&origen));
        cont++;
    }

    pila2Pila(&aux, &origen);

    return suma;
}

///funcion que suma una pila
///retorna la suma

int sumaPila(Pila origen)
{
    int suma = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&origen))
    {
        suma += tope(&origen);
        apilar(&aux, desapilar(&origen));
    }

    pila2Pila(&aux, &origen);

    return suma;
}

///funcion que cuenta la cantidad de elementos que contiene una pila

int cuentaElementosPila(Pila origen)
{
    int cont = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&origen))
    {
        cont++;
        apilar(&aux, desapilar(&origen));
    }
    pila2Pila(&aux, &origen);

    return cont;
}

///funcion que calcula un promedio

float promedio(int cont, int suma)
{
    float promedio = (float) suma/cont;

    return promedio;
}


///funcion que calcula el promedio de una pila

float promedioPila(Pila origen)
{
    int suma = sumaPila(origen);
    int cont = cuentaElementosPila(origen);
    float promedioLocal = promedio(cont, suma);

    return promedioLocal;
}


















