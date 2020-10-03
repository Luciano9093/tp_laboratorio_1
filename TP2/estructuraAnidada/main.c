#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


int main()
{
    ePersona p1;
    eFecha f1 = {12,4,2000};

    p1.legajo = 1234;
    strcpy(p1.nonmbre,"Juan");
    p1.sexo = 'm';
    p1.altura = 1.72;
    p1.isEmpty = 0;
    p1.fNac= f1;
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(p1.nonmbre);
    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c",&p1.sexo);
    printf("Ingrese altura: ");
    scanf("%f", &p1.altura);
    printf("Ingrese fecha de nacimiento dd/mm/aaaa: ");
    scanf("%d/%d/%d", &p1.fNac.dia, &p1.fNac.mes, &p1.fNac.anio);



    printf("%d %s %c %.2f %d/%d/%d\n", p1.legajo, p1.nonmbre, p1.sexo, p1.altura, p1.fNac.dia, p1.fNac.anio, p1.fNac.mes);
}
