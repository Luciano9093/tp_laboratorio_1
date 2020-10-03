#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char menu();


int main()
{
    char seguir = 's';
    char confirma;

    do
    {
        switch(menu())
        {

        case 'a':


            break;
        case 'b':


            break;
        case 'c':

            break;
        case 'd':


            break;
        case 'e':


            break;
        case 'f':

            break;


        case 'g':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");

    }
    while( seguir == 's');


    return 0;
}
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nonmbre[20];
    char sexo;
    float altura;
    eFecha fNac;
    int isEmpty;
}ePersona;

char menu()
{
    char opcion;
    system("cls");

    printf("*** ABM Personas ***\n\n");
    printf("a Alta\n");
    printf("b Baja\n");
    printf("c Modificacion\n");
    printf("d Listar\n");
    printf("e Ordenar\n");
    printf("f Informes\n");
    printf("g Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}

