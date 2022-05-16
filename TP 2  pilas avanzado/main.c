#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include "pila.h"

void muestraMenu();

const int ESC = 27;

/** SICLO DE CARGA DE UNA PILA MANUAL
do
    {
        printf("Ingrese un numero:");
        scanf("%d", &num);
        apilar(&pilaA, num);

        printf("ESC para salir\n\n");
        opcion = getch();
    }
    while(opcion != ESC);

    ///SICLO DE CARGA DE UNA PILA RANDOM

    for(int i = 0; i<10; i++)
    {
        apilar(&modelo, rand()%11;
    }

    ///SICLO DE CARGA RANDOM DE UNA PILA HASTA CUANDO EL USUARIO DIGA

    do
    {
        apilar(&dada, rand()%11);
        printf("ESC para salir otro para cargar\n");
        opcion = getch();

    }while(opcion != ESC);
*/


int main()
{
    ///VARIABLES

    char opcion;
    int num = 0;///numero a almacenar en una pila
    int sumaPila = 0;///variable donde se va a almcenar las sumas de las pila
    int contPila = 0; ///variable donde cuenta la cantidad de elementos que contiene una pila
    float promedioPila = 0;///contiene el resultado del promedio de una pila
    int flag = 0; ///0 verdadero 1 falso

    srand(time(NULL));

    ///PILAS
    Pila dada, auxDada, numInsert, ordenada, basura, copiaDada, ordenada2, ordenadaFinal;
    inicpila(&dada);
    inicpila(&auxDada);
    inicpila(&numInsert);
    inicpila(&ordenada);
    inicpila(&ordenada2);
    inicpila(&ordenadaFinal);
    inicpila(&basura);
    inicpila(&copiaDada);

    Pila menor;
    inicpila(&menor);

    do
    {
        system("cls");
        muestraMenu();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case 49:

            ///carga de la pila a sumar

            do
            {
                printf("Ingrese un numero:");
                scanf("%d", &num);
                apilar(&dada, num);

                printf("ESC para salir\n\n");
                opcion = getch();
            }
            while(opcion != ESC);

            printf("PILA DADA:");
            mostrar(&dada);

            while(!pilavacia(&dada))
            {
                sumaPila += tope(&dada);
                apilar(&auxDada, desapilar(&dada));
            }
            while(!pilavacia(&auxDada))
            {
                apilar(&dada, desapilar(&auxDada));
            }
            printf("La suma de la pila DADA es de %d\n", sumaPila);

            opcion = getch();

            break;
        case 50:
            do
            {
                apilar(&dada, rand()%11);
                printf("ESC para salir otro para cargar\n");
                opcion = getch();

            }
            while(opcion != ESC);
            system("cls");

            printf("PILA DADA:");
            mostrar(&dada);

            while(!pilavacia(&dada))
            {
                contPila++;
                apilar(&auxDada, desapilar(&dada));
            }
            while(!pilavacia(&auxDada))
            {
                apilar(&dada, desapilar(&auxDada));
            }
            printf("La cantidad de elementos que contiene la pila es de %d\n", contPila);

            opcion = getch();



            break;
        case 51:
            do
            {
                apilar(&dada, rand()%11);
                printf("ESC para salir otro para cargar\n");
                opcion = getch();

            }
            while(opcion != ESC);
            system("cls");

            printf("PILA DADA:");
            mostrar(&dada);

            while(!pilavacia(&dada))
            {
                sumaPila += tope(&dada);
                contPila++;
                apilar(&auxDada, desapilar(&dada));
            }
            while(!pilavacia(&auxDada))
            {
                apilar(&dada, desapilar(&auxDada));
            }

            promedioPila = (float) sumaPila/contPila;

            printf("\nCANTIDAD....: %d", contPila);
            printf("\nSUMA........: %d", sumaPila);
            printf("\nPROMEDIO....: %.2f", promedioPila);

            opcion = getch();


            break;
        case 52:

            do
            {
                printf("Ingrese un numero:");
                scanf("%d", &num);
                apilar(&dada, num);

                printf("ESC para salir\n\n");
                opcion = getch();
            }
            while(opcion != ESC);
            system("cls");

            printf("PILA DADA:");
            mostrar(&dada);

            if(!pilavacia(&dada))
            {
                apilar(&menor, desapilar(&dada));

                while(!pilavacia(&dada))
                {
                    if(tope(&dada) < tope(&menor))
                    {
                        apilar(&auxDada, desapilar(&menor));
                        apilar(&menor, desapilar(&dada));
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

            printf("PILA CON EL MENOR ELEMENTO DE LA PILA DADA:");
            mostrar(&menor);

            opcion = getch();

            break;
        case 53:

            ///Cargo la pila dada manual ordenada
            apilar(&dada, 2);
            apilar(&dada, 4);
            apilar(&dada, 6);
            apilar(&dada, 8);
            apilar(&dada, 10);

            printf("PILA DADA ORDENADA:");
            mostrar(&dada);

            ///le pido un numero al usuario para insertar en la pila DADA
            printf("Ingrese un numero: ");
            scanf("%d", &num);
            apilar(&numInsert, num); ///la pila num insert contiene el numero a insertar en dada


            while(!pilavacia(&numInsert) && !pilavacia(&dada))
            {
                if(tope(&dada) > tope(&numInsert))
                {
                    apilar(&auxDada, desapilar(&dada));
                }
                else
                {
                    apilar(&dada, desapilar(&numInsert));
                }
            }
            while(!pilavacia(&auxDada))
            {
                apilar(&dada, desapilar(&auxDada));
            }

            printf("PILA DADA CON EL NUMERO INSERTADO");
            mostrar(&dada);
            opcion = getch();

            break;
        case 54:

            do
            {
                printf("Ingrese un numero:");
                scanf("%d", &num);
                apilar(&dada, num);

                printf("ESC para salir\n\n");
                opcion = getch();
            }
            while(opcion != ESC);
            system("cls");

            printf("PILA DADA:");
            mostrar(&dada);

            while(!pilavacia(&dada))
            {
                apilar(&menor, desapilar(&dada));

                while(!pilavacia(&dada))
                {
                    if(tope(&dada) < tope(&menor))
                    {
                        apilar(&auxDada, desapilar(&menor));
                        apilar(&menor, desapilar(&dada));
                    }
                    else
                    {
                        apilar(&auxDada, desapilar(&dada));
                    }
                }
                while(!pilavacia(&auxDada))
                {
                    apilar(&dada, desapilar(&auxDada));
                }

                apilar(&ordenada, desapilar(&menor));
            }

            printf("PILA ORDENADA:");
            mostrar(&ordenada);
            opcion = getch();

            break;
        case 55:

            for(int i = 0; i<10; i++)
            {
                apilar(&dada, rand()%11);
            }


            ///printf("PILA DADA CARGADA RANDOM:");
            ///mostrar(&dada);

            printf("Ingrese el numero que quiere buscar en la pila dada: ");
            scanf("%d", &num);

            while(!pilavacia(&dada) && flag == 0)///si flag de convierte en 1 es porq se encontro el elemento y finaliza la busqueda
            {
                if(tope(&dada) == num)
                {
                    flag = 1;
                }
                else
                {
                    apilar(&auxDada, desapilar(&dada));
                }
            }

            while(!pilavacia(&auxDada))
            {
                apilar(&dada, desapilar(&auxDada));
            }

            if(flag == 1)
            {
                printf("\nEl numero que ingreso se encuentra en la pila DADA\n");
            }
            else
            {
                printf("\nEl numero que ingreso NO se encuentra en la pila DADA\n");
            }

            opcion = getch();

            break;
        case 56:

            for(int i = 0; i<10; i++)
            {
                apilar(&dada, rand()%11);
            }


            printf("PILA DADA CARGADA RANDOM:");
            mostrar(&dada);

            printf("Ingrese el numero que quiere eliminar en la pila dada: ");
            scanf("%d", &num);

            while(!pilavacia(&dada) && flag == 0)
            {
                if(tope(&dada) == num)
                {
                    flag = 1;
                    apilar(&basura, desapilar(&dada));
                }
                else
                {
                    apilar(&auxDada, desapilar(&dada));
                }
            }

            while(!pilavacia(&auxDada))
            {
                apilar(&dada, desapilar(&auxDada));
            }

            if(flag == 1)
            {
                printf("\nPILA DADA SIN EL ELEMENTO SELECCIONADO:");
                mostrar(&dada);

            }
            else
            {
                printf("\nEl elemento seleccionado no se encuentra en la pila DADA");
            }
            opcion = getch();
            inicpila(&dada);

            break;
        case 57:

            do
            {
                printf("Ingrese numero a cargar en la pila DADA: ");
                scanf("%d", &num);
                apilar(&dada, num);
                printf("ESC para salir.\n");
                opcion=getch();

            }while(opcion != ESC);
            system("cls");

            printf("PILA DADA:");
            mostrar(&dada);

            while(!pilavacia(&dada))
            {
                apilar(&copiaDada, tope(&dada));
                apilar(&auxDada, desapilar(&dada));
            }

            while(!pilavacia(&auxDada))
            {
                apilar(&dada, desapilar(&auxDada));
            }

            while(!pilavacia(&dada) && flag == 0)
            {
                if(tope(&dada) == tope(&copiaDada))
                {
                    apilar(&auxDada, desapilar(&dada));
                    apilar(&basura, desapilar(&copiaDada));
                }
                else
                {
                    flag = 1;
                }
            }
            while(!pilavacia(&auxDada))
            {
                apilar(&dada, desapilar(&auxDada));
            }

            if(flag == 0)
            {
                printf("\nLA PILA DADA ES CAPICUA.\n");
            }
            else
            {
                printf("\nLA PILA DADA NO ES CAPICUA.\n");
            }
            inicpila(&dada);

            opcion = getch();


            break;
        case 97:

            break;
        case 98:

            ///cargo la pila ordenada manuealnebte
            apilar(&ordenada, 1);
            apilar(&ordenada, 3);
            apilar(&ordenada, 5);
            apilar(&ordenada, 7);
            apilar(&ordenada, 9);

            ///cargo la pila ordenada2 manualmente
            apilar(&ordenada2, 2);
            apilar(&ordenada2, 4);
            apilar(&ordenada2, 6);
            apilar(&ordenada2, 8);
            apilar(&ordenada2, 10);

            printf("PILA ORDENADA 1:");
            mostrar(&ordenada);
            printf("PILA ORDENADA 2:");
            mostrar(&ordenada2);

            while(!pilavacia(&ordenada))
            {
                apilar(&dada, desapilar(&ordenada));
            }
            while(!pilavacia(&ordenada2))
            {
                apilar(&auxDada, desapilar(&ordenada2));
            }

            while(!pilavacia(&dada) && !pilavacia(&auxDada))
            {
                apilar(&ordenadaFinal, desapilar(&dada));
                apilar(&ordenadaFinal, desapilar(&auxDada));
            }

            mostrar(&ordenadaFinal);
            opcion = getch();

            break;
        case 99:

            break;
        case 100:

            break;
        }

    }
    while(opcion != ESC);

    return 0;
}


/** \brief Esta funcion contiene el menu con los ejercicios del TP
 *
 * \param
 * \param
 * \return
 *
 */

void muestraMenu()
{
    printf("\t\t\t\t\tELIGA QUE EJERCICIO QUIERE REALIZAR\n");
    printf("\n1. Sumar los elementos de una pila (usar variables enteras)");
    printf("\n2. Contar los elementos de una pila (usar variables enteras)");
    printf("\n3. Calcular el promedio de los valores de una pila (usar variables)");
    printf("\n4. Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables enteras, solo pilas)");
    printf("\n5. Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal que se conserve el orden. (sin variables enteras, solo pilas)");
    printf("\n6. Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal quela segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de ordenacion por seleccion.");
    printf("\n7. Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la búsqueda.");
    printf("\n8. Eliminar un elemento de una pila. El eliminarlo, finalizar el recorrido y dejar el resto en elmismo orden.");
    printf("\n9. Verificar si una pila DADA es capicua.");
    printf("\n\nPRESIONE LA LETRA CORRESPONDIENTE AL AJERCICIO");
    printf("\nA- ");
    printf("\nB- 11. Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando el resultado en una pila también ordenada en forma creciente (ORDENADAFINAL).");
    printf("\nC- 12. Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el resultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5.");
    printf("\nD- 13. Suponer un juego de cartas en el que en cada mano se reparten dos cartas por jugador. Unjugador gana la mano cuando la suma de sus cartas es mayor que las del contrario y alhacerlo coloca todas las cartas (las de él y las de su rival) en su pila de puntos. En caso  deempate (y para simplificar) siempre gana el jugador1. Simular la ejecución del juego de talmanera que dada una pila MAZO (con un número de elementos múltiplo de cuatro)distribuya las cartas en las pilas PUNTOSJUG1 y PUNTOSJUG2 como si estos hubieran jugado. Utilizar las pilas auxiliares que crea conveniente");
    printf("\n\n");
    printf("Ingrese ESC para salir.");

}
































































































