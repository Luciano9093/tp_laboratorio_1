#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"

// DESARROLLO DE FUNCION SUMA.
float sumaOperandos(float a, float b)
{
    float resultado;
    resultado=a+b;

    return resultado;
}
//DESARROLLO DE FUNCION RESTA.
float restaOperandos(float x, float y)
{
    float resultado;
    resultado=x-y;

    return resultado;
}
//DESARROLLO DE FUNCION MULTIPLICACION.
float multiplicacionOperandos(float x, float y)
{
    float resultado;
    resultado=x*y;

    return resultado;
}
//DESARROLLO DE LA FUNCION DIVISION
float divisionOperandos(float x, float y, float*resultado)
{
    float cociente;                                         //UTILICE UN PUNTERO PARA GUARDAR EL RESULTADO DE LA DIVISION.
    int error;                                              //LO QUE RETORNA ESTA FUNCION ES SI HUBO O NO HUBO ERROR. DICHA
    if(y!=0)                                                //CONDICION ESTA DETERMINADA POR EL VALOR INGRESADADO AL 2DO
    {                                                       //OPERANDO (DENOMINADOR EN ESTE CASO).-
        cociente=x/y;
        (*resultado)=cociente;
        error=0;
    }
    else
    {
        error=1;
    }

    return error;
}
//DESARROLLO DE LA FUNCION FACTORIAL.
long long int factorialOperandos(int x)                //UTILICE LONG LONG INT PARA EVITAR DEBORDAMIENTO. SIN EMBARGO EL MAXIMO
{                                                      //NUMERO QUE LE PUEDO DAR A LOS OPERANDOS PARA EVITAR QUE EL RESULTADO
    long long int fact=1;                              //ME DESBORDE INCLUSO ESTE TIPO DE VARIABLES ES "20".

    for(int i=1;i<=x;i++)
    {
        fact*=i;
    }
    return fact;
}

