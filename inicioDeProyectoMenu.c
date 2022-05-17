# TP-labo-1-2022
trabajos practicos de laboratorio 1 de oyente en 2022

  #include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>

///CONSTANTES

const int ESC = 27;
const int DIM = 15;

///PROTOTIPADOS

void mustraMenu();


int main()
{
    char opcion;

    do{
      system("cls");
      mustra_menu ();
      opcion=getch();
      system("cls");

    switch (opcion) {

        case 49:
            printf("\nhola master\n");
            opcion = getch();
            break;
        case 50:
            printf("\nhola perro\n");
            opcion = getch();
            break;
        case 51:
            printf("\nhola animal \n");
            opcion = getch();
            break;

      }



    } while (opcion1!=ESC);

    return 0;
}

///muestra el menu

void mustraMenu()
{
    printf("\t\t\t\t\n QUE FUNCION DESEA RELIZAR?");
    printf("\n");
    printf("\n");
    printf("\n ");
    printf("\n");
    printf("\n");
    printf("ingrese numero de funcion o ESC para salir: ");

}
