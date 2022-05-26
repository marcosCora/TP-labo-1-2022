#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>

///ESTRUCTURA

typedef struct
{
    int matricula;
    char nombre[30];
    char genero; ///m o f
} stAlumno;

///CONSTANTES

const int ESC = 27;
const int DIM = 50;

///PROTOTIPADOS

void mustraMenu();
stAlumno cargaUnAlumno();
int cargaArrayAlumnos(stAlumno a[], int dim);
void muestraUnAlumno(stAlumno a);
void muestraArrayAlumnos(stAlumno a[], int v);
stAlumno buscaAlumnoMatricula(stAlumno a[], int v, int matricula);
void ejercicio3(stAlumno a[], int v);
int buscaPosMatriculaAlumno(stAlumno a[], int v, int i);
int ordenamientoXSeleccionAlumno(stAlumno a[], int v);
void muestraRegistroPorGenero(stAlumno a[], int v, char genero);
int insertaElementoArrayOrdenadoMatricula(stAlumno a[], int v, stAlumno insert);
void insertaElementoArrayOrdenadoNombre(stAlumno a[], int v, stAlumno insert);
void ordenamientoXInsercionnAlumno(stAlumno a[], int v);
int cuentaRegistroPorGenero(stAlumno a[], int v, char genero);

int main()
{
    char opcion;
    int cantAlumnosGenero = 0;

    ///estructuras
    stAlumno alumnos[DIM];
    int vAlumnos;

    char generoAMostrar;
    stAlumno aInsertar;
    char m[30] = {'m','a','s','c','u','l','i','n','o'};
    char f[30] = {'f','e','m','e','n','i','n','o'};


    do
    {
        system("cls");
        mustraMenu();
        opcion=getch();
        system("cls");

        switch (opcion)
        {

        case 49:

            printf("CARGANDO ARRAY DE ALUMNOS\n\n");
            vAlumnos = cargaArrayAlumnos(alumnos, DIM);

            ///opcion = getch();
            break;
        case 50:

            printf("ARREGLO DE ALUMNOS:\n\n");
            muestraArrayAlumnos(alumnos, vAlumnos);
            opcion = getch();
            break;
        case 51:

            ejercicio3(alumnos, vAlumnos);
            opcion = getch();
            break;
        case 52:

            vAlumnos = ordenamientoXSeleccionAlumno(alumnos, vAlumnos);
            printf("El arreglo de alumnos ya fue ordenado por matricula\n\n");
            opcion = getch();
            break;

        case 53:

            printf("Ingrese que genero desea mostrar F/M: ");
            fflush(stdin);
            scanf("%c", &generoAMostrar);

            muestraRegistroPorGenero(alumnos, vAlumnos, generoAMostrar);

            opcion = getch();
            break;

        case 54:
            printf("Ingrese el nuevo alumno:\n\n");
            aInsertar = cargaUnAlumno();

            vAlumnos = insertaElementoArrayOrdenadoMatricula(alumnos, vAlumnos, aInsertar);
            printf("\nEl alumno ya fue agregado a el arreglo.\n\n");
            opcion = getch();
            break;

        case 55:

            ordenamientoXInsercionnAlumno(alumnos, vAlumnos);
            printf("El arreglo de alumnos ya fue ordenado por nombre\n\n");
            muestraArrayAlumnos(alumnos, vAlumnos);


            opcion = getch();
            break;

        case 56:

            printf("Ingrese que genero desea contar F/M: ");
            fflush(stdin);
            scanf("%c", &generoAMostrar);

            cantAlumnosGenero = cuentaRegistroPorGenero(alumnos, vAlumnos, generoAMostrar);

            if(generoAMostrar == 'm')
            {
                printf("\n\nEn el registro se encunetran %d personas del genero %s\n\n", cantAlumnosGenero,  m);
            }
            else
            {
                printf("\n\nEn el registro se encunetran %d personas del genero %s\n\n", cantAlumnosGenero,  f);
            }



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
    printf("\t\t\t\t %cQUE FUNCION DESEA RELIZAR?\n\n", 168);
    printf("1. Carga arreglo de alumnos (1).\n");
    printf("2. Muestra arreglo de alumnos (2).\n");
    printf("3. Busca un alumno por maticula (3)\n");
    printf("4. Ordenamiento por seleccion por matricula (4)\n");
    printf("5. Muestra el genero que eliga el usuario(5)\n");
    printf("6. Inserta alumno en un arreglo ordenado por matricula(6)\n");
    printf("7. Ordenamiento por insercion por nombre(7)\n");
    printf("8. cuenta la cantidad de personas de un genero en especifico que hay en el registro\n");
    printf("\n");
    printf("\n");
    printf("ESC para salir: ");

}



///EJERCICIO 1

///funcion que carga un solo alumno

stAlumno cargaUnAlumno()
{
    stAlumno alumno;

    printf("Ingrese su matricula.......: ");
    scanf("%d", &alumno.matricula);
    printf("Ingrese su nombre..........: ");
    fflush(stdin);
    gets(alumno.nombre);
    printf("Ingrese su genero F/M......: ");
    fflush(stdin);
    scanf("%c", &alumno.genero);

    while(alumno.genero != 'f' && alumno.genero != 'm')
    {
        printf("Genero incorrecto, ingrese F o M: ");
        fflush(stdin);
        scanf("%c", &alumno.genero);
    }

    return alumno;
}


///funcion que carga un arreglo de tipo alumnos
///invoca a la funcion de carga un alumno
///retorna los validos

int cargaArrayAlumnos(stAlumno a[], int dim)
{
    int v = 0;
    char opcion = 'NULL';

    while(v < dim && opcion != ESC)
    {
        a[v] = cargaUnAlumno();
        printf("\nESC para salir OTRO para continuar.\n\n");
        opcion = getch();
        v++;
    }

    return v;
}

///EJERCICIO 2

///funcion que muestra un solo alumno

void muestraUnAlumno(stAlumno a)
{
    char m[30] = {'M','a','s','c','u','l','i','n','o'};
    char f[30] = {'F','e','m','e','n','i','n','o'};
    printf("---------------------------------------------------------\n");
    printf("MATRICULA.........: %d\n", a.matricula);
    printf("NOMBRE............: %s\n", a.nombre);

    if(a.genero == 'm')
    {
        printf("GENERO............: %s\n", m);
    }
    else
    {
        printf("GENERO............: %s\n", f);
    }
    printf("---------------------------------------------------------\n");
}

///funcion que muestra un arreglo de alumnos
///invoca a la funcion de mostrar un alumno

void muestraArrayAlumnos(stAlumno a[], int v)
{
    int i;

    for(i = 0; i<v; i++)
    {
        muestraUnAlumno(a[i]);
    }
}


///EJERCICIO 3

///funcion que busca un alumno por matricula y lo retorna

stAlumno buscaAlumnoMatricula(stAlumno a[], int v, int matricula)
{
    stAlumno encontrado;
    int i = 0;
    int flag = 0;

    while(i<v && flag == 0)
    {
        if(matricula == a[i].matricula)
        {
            encontrado = a[i];
            flag = 1;
        }
        else
        {
            encontrado.matricula = -1;
        }
        i++;
    }

    return encontrado;
}

///funcion que pide matricula de usuario para buscar el alumno

void ejercicio3(stAlumno a[], int v)
{
    int matricula = 0;
    stAlumno encontrado;
    printf("\nIngrese la matricula: ");
    scanf("%d", &matricula);
    system("cls");
    encontrado = buscaAlumnoMatricula(a, v, matricula);

    if(encontrado.matricula != -1)
    {
        printf("Este es el alumno que usted busca:\n");
        muestraUnAlumno(encontrado);
    }
    else
    {
        printf("El alumno que busca no se encunetra.\n");
    }
}


///EJERCICIO 4

///funcion que busca la posicion donde esta la menor matricula

int buscaPosMatriculaAlumno(stAlumno a[], int v, int i)
{
    int posMenor = i;
    int matriculaMenor = a[posMenor].matricula;

    for(i = i+1; i<v; i++)
    {
        if(matriculaMenor > a[i].matricula)
        {
            posMenor = i;
            matriculaMenor = a[i].matricula;
        }
    }
    return posMenor;
}


///funcion que ordena el arrglo
///por matricula

int ordenamientoXSeleccionAlumno(stAlumno a[], int v)
{
    int i = 0;
    stAlumno aux;
    int posMenor = 0;

    for(i = 0; i<v; i++)
    {
        posMenor = buscaPosMatriculaAlumno(a, v, i);
        aux = a[i];
        a[i] = a[posMenor];
        a[posMenor] = aux;
    }
    return i;
}


///EJERCICIO 5

///muestra estudiantes de un determinado genero enviado por parametro

void muestraRegistroPorGenero(stAlumno a[], int v, char genero)
{
    int i;

    for(i = 0; i<v; i++)
    {
        if(genero == a[i].genero)
        {
            muestraUnAlumno(a[i]);
        }
    }
}

///EJERCICIO 6
///inserta en un arreglo ordenado por matricula un nuevo elemento en orden

int insertaElementoArrayOrdenadoMatricula(stAlumno a[], int v, stAlumno insert)
{
    int f = v-1;

    while(f >= 0 && a[f].matricula > insert.matricula)
    {
        a[f+1] = a[f];
        f--;
    }

    a[f+1] = insert;

    return v+1;
}

///EJERCICIO 7

///funcion que inserta un alumno a un arreglo ordenado por nombre

void insertaElementoArrayOrdenadoNombre(stAlumno a[], int v, stAlumno insert)
{
    int i = v;

    while(i >= 0 && strcmpi(a[i].nombre, insert.nombre) > 0)
    {
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = insert;
}


void ordenamientoXInsercionnAlumno(stAlumno a[], int v)
{
    int i = 0;

    for(i = 0; i<v; i++)
    {
        insertaElementoArrayOrdenadoNombre(a, i, a[i+1]);
    }
}

///EJERCICIO 8
///cuenta la cantidad de alumnos de un genero en especifico hay

int cuentaRegistroPorGenero(stAlumno a[], int v, char genero)
{
    int i;
    int cont = 0;

    for(i = 0; i<v; i++)
    {
        if(genero == a[i].genero)
        {
            cont++;
        }
    }
    return cont;
}












