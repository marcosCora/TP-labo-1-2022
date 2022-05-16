#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include "pila.h"

/**
se ncesita de la libreria time

Esto se usa para generar un numero random sin necesidad que cada corrida
de programa sea igual a todas usando srand

srand(time(NULL));

rand() %10

*/

///ALGORITMO QUE GENERA UN NUMERO RANDOM
/**
int num = 0;

for(int i = 0; i<10; i++)
{
    num = rand()%11;
}
*/

const int ESC = 27;


int main()
{
    char opcion;
    int elementos = 0; ///dato a apilar en la pila
    int num = 0;///variable para generar numero random

    srand(time(NULL));





    /**
    CICLO DE CARGA DE UNA PILA
    do
    {


     printf("\nESC para salir\n");
     opcion = getch();
     system("cls");

    }while(opcion != ESC);
    */

    /**
        1. Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres primeros elementos que se
        encuentren en el tope a la pila AUX1 y los restantes a la pila AUX2, ambas pilas inicializadas.
    */

    /**
    Pila DADA, aux1, aux2;
    inicpila(&DADA);
    inicpila(&aux1);
    inicpila(&aux2);

    int i;
    int elementos = 0;
    int cont = 0;

    for(i=0; i<5; i++)
    {
        printf("Ingrese elemento %d: ", i+1);
        scanf("%d", &elementos);

        apilar(&DADA, elementos);

    }

    printf("<<<<<<<<<<PILA DADA>>>>>>>>>>");
    mostrar(&DADA);

    while(!pilavacia(&DADA))
    {

        /**
        apilar(&aux1, desapilar(&DADA));
        apilar(&aux1, desapilar(&DADA));
        apilar(&aux1, desapilar(&DADA));
        apilar(&aux2, desapilar(&DADA));
        apilar(&aux2, desapilar(&DADA));


        if(cont < 3)
        {
            apilar(&aux1, desapilar(&DADA));
        }
        else
        {
            apilar(&aux2, desapilar(&DADA));
        }
        cont++;

    printf("<<<<<<<<<<PILA AUX1>>>>>>>>>>");
    mostrar(&aux1);
    printf("<<<<<<<<<<PILA AUX2>>>>>>>>>>");
    mostrar(&aux2);

    */


    /**
        2. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar todos los
        elementos de la pila ORIGEN a la pila DESTINO.
    */
    /**
    Pila origen, destino;
    inicpila(&origen);
    inicpila(&destino);



    do
    {
        printf("Ingrese un elemento a cargar en la pila: ");
        scanf("%d", &elementos);

        apilar(&origen, elementos);

        printf("\nESC para salir\n");
        opcion = getch();
        system("cls");

    }while(opcion != ESC);

    printf("<<<<<<<<<<<<<<<<<<<<<PILA ORIGEN>>>>>>>>>>>>>>>>>>>>>>>>>>");
    mostrar(&origen);


    while(!pilavacia(&origen))
    {
        apilar(&destino, desapilar(&origen));
    }

    printf("<<<<<<<<<<<<<<<<<<<<<PILA DESTINO>>>>>>>>>>>>>>>>>>>>>>>>>>");
    mostrar(&destino);
    */

    /**
    3. Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al
    valor 8.
    */
    /**
    Pila dada, destino, pilaOcho;

    int aux = 0;

    inicpila(&dada);
    inicpila(&destino);
    inicpila(&pilaOcho);

    do
    {
        printf("\Ingrese los elementos: ");
        scanf("%d", &elementos);

        apilar(&dada, elementos);

        printf("ESC para salir\n");
        opcion = getch();

    }while(opcion != ESC);

    printf("<<<<<<<<<<<<<<<<Pila Dada>>>>>>>>>>>>>>>>>>>>>>");
    mostrar(&dada);

    while(!pilavacia(&dada))
    {
        aux = tope(&dada);

        if(aux == 8) ///tope(&dada) == 8
        {
            apilar(&pilaOcho, desapilar(&dada));
        }
        else
        {
            apilar(&destino, desapilar(&dada));
        }
    }

    printf("<<<<<<<<<<<<<Pila Destino>>>>>>>>>>>>>>>>>");
    mostrar(&destino);
    printf("\n<<<<<<<<<<<<<Pila Ocho>>>>>>>>>>>>>>>>>");
    mostrar(&pilaOcho);
    */

    /**

    4. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar los elementos de
    la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden.

    */
    /**
    Pila origen, destino, aux1;

    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux1);

    do
    {
        printf("\nCargue la pila origen: ");
        scanf("%d", &elementos);

        apilar(&origen, elementos);

        printf("ESC para salir\n");
        opcion = getch();

    }while(opcion != ESC);

    printf("\n<<<<<<<<<<<<<<<<PILA ORIGEN>>>>>>>>>>>>>>>>");
    mostrar(&origen);

    while(!pilavacia(&origen))
    {
        apilar(&aux1, desapilar(&origen));
    }
    while(!pilavacia(&aux1))
    {
        apilar(&destino, desapilar(&aux1));
    }

    printf("\n<<<<<<<<<<<<<<<<PILA DESTINO>>>>>>>>>>>>>>>>");
    mostrar(&destino);
    */


    /**
        5. Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA contenga los elementos
        cargados originalmente en ella, pero en orden inverso.
    */
    /**
    Pila dada, aux1, aux2;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    for(int i = 0; i<10; i++)
    {
        num = rand()%11;
        apilar(&dada, num);
    }

    printf("<<<<<<<<<<<<<<PILA DADA>>>>>>>>>>>>>>>>");
    mostrar(&dada);

    while(!pilavacia(&dada))
    {
        apilar(&aux1, desapilar(&dada));
    }
    while(!pilavacia(&aux1))
    {
        apilar(&aux2, desapilar(&aux1));
    }
    while(!pilavacia(&aux2))
    {
        apilar(&dada, desapilar(&aux2));
    }

    printf("<<<<<<<<<<<<<<PILA DADA>>>>>>>>>>>>>>>>");
    mostrar(&dada);
    */

    /**
    6. Pasar el primer elemento (tope) de la pila DADA a su última posición (base), dejando
    los restanteselementos en el mismo orden.
    */
    /**
    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);

    int topePila = 0;

    for(int i = 0; i<10; i++)
    {
        num = rand()%11;
        apilar(&dada, num);
    }
    printf("PILA DADA:");
    mostrar(&dada);

    if(!pilavacia(&dada))
    {
        topePila = desapilar(&dada);
    }

    while(!pilavacia(&dada))
    {
        apilar(&aux, desapilar(&dada));
    }

    apilar(&dada, topePila);

     while(!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    printf("PILA DADA FINAL:");
    mostrar(&dada);
    */

    /**
    7. Pasar el último elemento (base) de la pila DADA a su primera posición (tope), dejando los
    restanteselementos en el mismo orden.
    */
    /**
    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);

    int basePila = 0;

    for(int i = 0; i<10; i++)
    {
        num = rand()%11;
        apilar(&dada, num);
    }
    printf("PILA DADA:");
    mostrar(&dada);

    while(!pilavacia(&dada))
    {
        apilar(&aux, desapilar(&dada));
    }

    if(!pilavacia(&aux))
    {
        basePila = desapilar(&aux);///alamaceno la base de la pila en una variable entera
    }

    while(!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }
    apilar(&dada, basePila);///aca pongo el numero base de la pila dada en el tope

    printf("PILA DADA FINAL:");
    mostrar(&dada);
    */

    /**
    8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa
    */
    /**
    Pila mazo, jug1, jug2;
    inicpila(&mazo);
    inicpila(&jug1);
    inicpila(&jug2);

    for(int i = 0; i<10; i++)
    {
        num = rand()%11;
        apilar(&mazo, num);
    }
    printf("MAZO:");
    mostrar(&mazo);

    while(!pilavacia(&mazo))
    {
        apilar(&jug1, desapilar(&mazo));
        apilar(&jug2, desapilar(&mazo));
    }
    printf("JUGADOR 1:");
    mostrar(&jug1);
    printf("JUGADOR 2:");
    mostrar(&jug2);
    */

    /**
    9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado
    */
    /**
    Pila pilaA, pilaB, auxA, auxB;
    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&auxA);
    inicpila(&auxB);

    ///variables que almaceenan la cantidad de datos de la pila a y b
    int contA=0;
    int contB=0;

    for(int i = 0; i<18; i++)
    {
        num = rand()%11;
        apilar(&pilaA, num);
    }

    for(int i = 0; i<10; i++)
    {
        num = rand()%11;
        apilar(&pilaB, num);
    }
    printf("PILA A:");
    mostrar(&pilaA);
    printf("\nPILA B:");
    mostrar(&pilaB);

    while(!pilavacia(&pilaA))
    {
        apilar(&auxA, desapilar(&pilaA));
        contA++;
    }

    while(!pilavacia(&pilaB))
    {
        apilar(&auxB, desapilar(&pilaB));
        contB++;
    }

    printf("\nLa pila A contiene %d elementos mientras que la B %d\n", contA, contB);
    */

    /**
    10. Cargar las pilas A y B, y luego compararlas, evaluando si son completamente iguales (en cantidad de
    elementos, valores que contienen y posición de los mismos). Mostrar por pantalla el resultado.
    */
    /**
    Pila pilaA, pilaB, auxA, auxB;
    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&auxA);
    inicpila(&auxB);

    int contA = 0;
    int contB = 0;
    int flag = 0; ///utilizo esta variables para salir de un siclo 1 que salga 0 que se mantenga

    printf("CARGANDO PILA A:\n\n");
    do
    {
        printf("Ingrese un numero:");
        scanf("%d", &num);
        apilar(&pilaA, num);

        printf("ESC para salir\n\n");
        opcion = getch();
    }
    while(opcion != ESC);
    system("cls");
    printf("CARGANDO PILA B:\n\n");

    do
    {
        printf("Ingrese un numero:");
        scanf("%d", &num);
        apilar(&pilaB, num);

        printf("ESC para salir\n\n");
        opcion = getch();
    }
    while(opcion != ESC);

    system("cls");

    printf("PILA A:");
    mostrar(&pilaA);
    printf("\nPILA B:");
    mostrar(&pilaB);


    ///en los proximos dos while los utilizo para contar la cantidad de valores que contine cada pila
    while(!pilavacia(&pilaA))
    {
        apilar(&auxA, desapilar(&pilaA));
        contA++;


    }
    while(!pilavacia(&pilaB))
    {
        apilar(&auxB, desapilar(&pilaB));
        contB++;
    }

    ///en los proximos 2 while devuelvo los valores a las pilas a y b ya que fueron pasados a aux para ser contados

    while(!pilavacia(&auxA))
    {
        apilar(&pilaA, desapilar(&auxA));

    }
    while(!pilavacia(&auxB))
    {
        apilar(&pilaB, desapilar(&auxB));
    }

    printf("\n\nLa pila A Contiene %d elementos.\n", contA);
    printf("La pila B Contiene %d elementos.\n", contB);

    if(contA == contB)
    {
        while(!pilavacia(&pilaA) && !pilavacia(&pilaB) && flag == 0)
        {

            if(tope(&pilaA) == tope(&pilaB))
            {
                apilar(&auxA, desapilar(&pilaA));
                apilar(&auxB, desapilar(&pilaB));
            }
            else
            {
                flag = 1;
            }

        }
        if(flag == 0)
        {
            printf("Las pilas A y B son completamente iguales\n");
        }
        else
        {
            printf("Las pilas A y B contienen la misma cantidad de elementos pero no son iguales");
        }
    }
    else
    {
        printf("\nLas pilas A y B no contienen la misma cantidad de elementos.\n");
    }
    */


    /**
    11. Suponiendo la existencia de una pila MODELO que no esté vacía, eliminar de la pila DADA todos los
    elementos que sean iguales al tope de la pila MODELO.
    */
    /**

    Pila modelo, dada, auxDada, aux;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&auxDada);
    inicpila(&aux);///en esta se almacena los numeros iguales al tope de modelo


    for(int i = 0; i<10; i++)
    {
        num = rand()%11;
        apilar(&modelo, num);
    }

    printf("PILA MODELO:");
    mostrar(&modelo);


    do
    {
        printf("\nIngrese los valores a cargar en DADA: ");
        scanf("%d", &elementos);
        apilar(&dada, elementos);

        printf("ESC para salir\n");
        opcion = getch();

    }
    while(opcion != ESC);

    printf("PILA DADA");
    mostrar(&dada);

    if(!pilavacia(&modelo))
    {


        while(!pilavacia(&dada))
        {
            if(tope(&modelo) == tope(&dada))
            {
                apilar(&aux, desapilar(&dada));
            }
            else
            {
                apilar(&auxDada, desapilar(&dada));
            }
        }
    }

    while(!pilavacia(&auxDada))
    {
        apilar(&dada, desapilar(&auxDada));
    }

    printf("PILA DADA SIN ELEMENTOS IGUALES AL TOPE DE MODELO");
    mostrar(&dada);
    */

    /**
    12. Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila DADA todos los
    elementos que existan en MODELO.
    */
    /**
    Pila modelo, dada, auxDada, auxModelo, basura;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&auxDada);
    inicpila(&auxModelo);
    inicpila(&basura);///en esta se almacena los numeros iguales de ambas pilas


    for(int i = 0; i<10; i++)
    {
        num = rand()%11;
        apilar(&modelo, num);
    }

    printf("PILA MODELO:");
    mostrar(&modelo);


    do
    {
        //en este siclo de carga con tocar cualquier tecla carga un numero random
        //printf("\nIngrese los valores a cargar en DADA: ");
        //scanf("%d", &elementos);
        apilar(&dada, rand()%11);

        printf("ESC para salir\n");
        opcion = getch();

    }
    while(opcion != ESC);

    printf("PILA MODELO:");
    mostrar(&modelo);

    printf("\nPILA DADA");
    mostrar(&dada);

    while(!pilavacia(&modelo))
    {
        while(!pilavacia(&dada))
        {
            if(tope(&modelo) == tope(&dada))///si los topes son iguales hace el pasaje
            {
                apilar(&basura, desapilar(&dada));
            }
            else
            {
                apilar(&auxDada, desapilar(&dada));
            }
        }

        while(!pilavacia(&auxDada))///vuelvo a pasar todo a aux para que se vuelva a comparar
        {
            apilar(&dada, desapilar(&auxDada));
        }

        apilar(&auxModelo, desapilar(&modelo));
    }

    while(!pilavacia(&auxDada))
    {
        apilar(&dada, desapilar(&auxDada));
    }

    printf("PILA DADA");
    mostrar(&dada);

    */

    /**
    13. Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila DADA que sean mayores
    o iguales que el tope de LIMITE a la pila MAYORES, y los elementos que sean menores a la pila MENORES.
    */
    /**
    Pila limite, dada, menores, mayores;
    inicpila(&limite);
    inicpila(&dada);
    inicpila(&menores);
    inicpila(&mayores);


    for(int i=0; i<10; i++)
    {
        apilar(&limite, rand()%11);
    }
    do
    {
        apilar(&dada, rand()%11);
        printf("ESC para salir otro para cargar\n");
        opcion = getch();

    }while(opcion != ESC);

    printf("PILA LIMITE:");
    mostrar(&limite);

    printf("PILA DADA:");
    mostrar(&dada);

    if(!pilavacia(&limite))
    {
       while(!pilavacia(&dada))
       {
           if(tope(&dada) >= tope(&limite))
           {
               apilar(&mayores, desapilar(&dada));
           }
           else
           {
               apilar(&menores, desapilar(&dada));
           }
       }
    }

    printf("PILA DADA:");
    mostrar(&dada);
    printf("PILA MAYORES:");
    mostrar(&mayores);
    printf("PILA MENORES:");
    mostrar(&menores);
    */







    return 0;

}














































































