#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"

/* --------------------------------TRABAJO PRACTICO N° 01 - CALCULADORA -----------------------------------
APELLIDO Y NOMBRE : STANCANELLO, LUCIANO DARÍO DANIEL.
CURSO :1°A.
-----------------------------------------------------------------------------------------------------------

CONSIGNA:

Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
*/

int main()
{
   //DECLARACION DE VARIABLES.-
   int opcion;
   float x;
   float y;
   int flagX=0;
   int flagY=0;
   int flagInforme=0;
   float suma;
   float resta;
   float multiplicacion;
   long long int factorialA;
   long long int factorialB;
   float division;
   float resultado;
   char salir='n';
   do
   {
       //...........................CREACIÓN DEL MENU DE OPCIONES.-
       system("cls");
       printf("***MENU DE OPCIONES***\n\n");
       if(flagX==0)
       {
            printf("1. Ingresar 1er operando.(A=X)\n");             // USE BANDERA PARA SABER CUANDO SE INGRESA EL PRIMER
       }                                                            // VALOR DE LA VARIABLE X O Y.-
       else
       {
           printf("1. Ingresar 1er operando.(A=%.2f)\n", x);          // CUANDO EL VALOR DE LA VARIABLE BANDERA flagX CAMBIE AL VALOR 1 (UNO)
       }                                                            // MOSTRARA EL PARAMETRO ACTUAL DE "X". LO MISMO SUCEDARA CON
       if(flagY==0)                                                 // "Y" CUANDO LA VARIABLLE BANDERA flagY CAMBIE AL VALOR 1 (UNO).-
       {
           printf("2. Ingresar 2do operando.(B=Y)\n");
       }
       else
       {

           printf("2. Ingresar 2do operando.(B=%.2f)\n", y);
       }
       printf("3. Calcular todas las operaciones.\n\n");
       printf("   A. Calcular la suma.\n");
       printf("   B. Calcular la resta.\n");
       printf("   C. Calcular la division.\n");
       printf("   D. Calcular la multiplicacion.\n");
       printf("   E. calcular el factorial.\n\n");
       printf("4. Informar resultado.\n");
       printf("5. Salir.\n\n");
       printf("Selecciones una opcion: ");
       fflush(stdin);
       scanf("%d", &opcion);

       //.........................................DESARROLLO DE LAS OPCIONES ELEGIDAS POR EL USUARIO,-
       switch(opcion)
       {
            //case 1: INGRESO DEL 1ER OPERANDO.-
            case 1:
                flagX=1;        //<============================FlagX=1 SIGNIFICA QUE YA INGRESE EL PRIMER VALOR DE X.
                printf("Ingrese el 1er operando: ");        // SE ACTUALIZARÁ EL VALOR DEL OPERANDO "A" EN EL MENU DE OPCIONES.-
                fflush(stdin);
                if(scanf("%f",&x)==0) //<======================PARA EVITAR QUE EL USUARIO NO INGRESE UN VALOR "X" QUE NO SEA UN NUMERO.
                {
                    printf("El valor ingresado no es un numero, elija la opcion [1] nuevamente y vuelva a intentar.\n");
                    flagX=0;
                }
                break;
            //case 2: INGRESO DEL 2DO OPERANDO.-
            case 2:
                flagY=1;        //<============================FlagY=1 SIGNIFICA QUE YA INGRESE EL PRIMER VALOR DE Y.
                printf("Ingrese el 2do operando: ");        // SE ACTUALIZARÁ EL VALOR DEL OPERANDO "B" EN EL MENU DE OPCIONES.-
                if(scanf("%f",&y)==0) //<======================PARA EVITAR QUE EL USUARIO NO INGRESE UN VALOR "Y" QUE NO SEA UN NUMERO.
                {
                    printf("El valor ingresado no es un numero, elija la opcion [2] nuevamente y vuelva a intentar.\n");
                    flagY=0;
                }
                break;
            //case 3: PROCESAMIENTO DE LOS OPERANDOS PARA CALCULAR OPERACIONES.-
            case 3:
                if(flagX!=1 || flagY!=1)        //<=======================SI NO SE INGRESARON LOS DOS OPERANDOS NECESARIOS NO SE PODRA REALIZAR LOS CALCULOS.-
                {
                    printf("verifique que haya ingresado los valores de los dos operandos necesarios para realizar las operaciones.\n");
                }
                else
                {
                    suma=sumaOperandos(x,y);                            // INVOCACION(LLAMADA)DE LAS FUNCIONES QUE REALIZARAN LA OPERACIONES.-
                    resta=restaOperandos(x,y);
                    multiplicacion=multiplicacionOperandos(x,y);
                    division=divisionOperandos(x,y,&resultado);  //<===========&resultado= "UTILICE PUNTERO EN LA FUNCION divisionOperandos,DONDE SE GUARDARA EL RESULTADO DE LA DIVISIÓN.
                    factorialA=factorialOperandos(x);                         //EN EL PUNTO 4 EXPLICO EL PORQUE USE PUNTERO EN LA DIVISIÓN.-
                    factorialB=factorialOperandos(y);
                    printf("Calculos procesados con exito.\n");
                    flagInforme=1;      //<===============================flagInforme= SI SE CUMPLE QUE EL USUARIO HAYA INGRESADO DOS OPERANDOS Y SE HAYAN REALIZADO LAS OPERACIONES,
                }                                                       //ENTONCES SE PODRAN MOSTRAR LOS RESULTADOS AL SELECCIONAR LA OPCION 4.-
                break;
            //case 4: MUESTRA LAS OPERACIONES CALCULADAS
            case 4:
                if(flagInforme==0)
                {
                    printf("No hay resultados que mostrar, verifique que haya ingresado los operandos necesarios.\n");// <===== ESTE PRINTF SE MOSTRARA SI SOLO SE INGRESO UNO O NINGUN VALOR DE LOS OPERANDOS.-
                }
                else
                {
                    printf("El resultado de %.2f + %.2f es: %.2f\n", x,y,suma);
                    printf("El resultado de %.2f - %.2f es: %.2f\n", x,y,resta);
                    printf("El resultado de %.2f * %.2f es: %.2f\n", x,y,multiplicacion);
                    if(division==0)     //<===============================================================LA VARIABLE division , SOLO PUEDE RECIBIR POR PARTE DE LA FUNCION divisionOperandos() VALORES IGUALES A
                    {                                                                                   //"1" O "0". SI ES IGUAL A CERO SIGNIFICA QUE NO HUBO ERROR EN LA DIVISION (DENOMINADOR DISTINTO DE CERO), HABILITANDO
                        printf("El resultado de %.2f / %.2f es: %.2f\n", x,y,resultado);                    //EL RESULTADO DE ESA DIVISION CUYO VALOR SE ENCUENTRA EN LA DIRECCION DE MEMORIA DE LA VARIABLE RESULTADO.-
                    }
                    else
                    {
                        printf("Error...la division tiene resultado indefinido (denominador = 0)...\n");
                    }

                    //VALIDACION DEL RESULTADO DEL FACTORIAL.
                    if((x<=0 || x>=21) && (y<=0 || y>=21))
                    {
                        printf("El factorial de A y el factorial de B no se pueden verificar\n");                           //EL NUMERO INGRESADO, PARA EL FACTORIAL DEBE SER UN ENTERO POSITIVO SINO NO EXISTE,
                    }                                                                                                       //SIN EMBARGO NO SUPE COMO VALIDAR LA FUNCION FACTORIAL SOLO PARA LOS NUMEROS ENTEROS QUE EL USUARIO INGRESE (NO LOS DECIMALES)
                    else                                                                                                    //A SU VEZ SE PUDO COMPROBAR QUE EL NUMERO MAXIMO QUE LE PUEDO DAR A UNO O AMBOS OPERANDOS ES 20
                    {                                                                                                       //CUALQUIER NUMERO MAYOR A 20, ME RETORNA UN RESULTADO CUYO VALOR ME DESBORDA INCLUSO, UNA VARIABLE
                        if(x>0 && x<21 && y>0 && y<21)                                                                      //DEL TIPO LONG LONG INT. POR TAL MOTIVO SE INTENTO VALIDAR EN BASE A LO MENCIONADO.-
                        {
                            printf("El factorial de A es %.0lld y el factorial de B es %.0lld\n",factorialA,factorialB);
                        }
                        else
                        {
                            if(x>0 && x<21 && (y<=0 || y>=21))
                            {
                                printf("El factorial de A es %.0lld y el factorial de B no se puede verificar\n",factorialA);
                            }
                            else
                            {
                                printf("El factorial de A no se puede verificar. El factorial de B es el numero %.0lld\n",factorialB);
                            }
                        }
                    }
                }
                 break;
            //case 5: VALIDACIÓN Y CONFIRMACIÓN DE SALIDA DEL PROGRAMA
            case 5:
                printf("Esta seguro que desea salir?. Ingrese [S] para salir o [N] para continuar.\n");
                fflush(stdin);
                scanf("%c",&salir);
                salir=tolower(salir);
                while(salir!='s' && salir!='n')
                {
                    printf("Respuesta no valida. Ingrese [S] para salir o [N] para continuar.\n");
                    fflush(stdin);
                    scanf("%c",&salir);
                    salir=tolower(salir);
                }
                break;
            //default: VALIDACION DE LA OPCION ELEGIDA POR EL USUARIO.-
            default:
                printf("La opcion seleccionada es invalida. Intente nuevamente.\n\n");
                break;
       }
       system("pause");
    }
    while(salir=='n');
    return 0; //<=================================================FIN DEL PROGRAMA.-
}
//ACLARACIÓN: PIDO DISCULPAS POR TANTOS COMENTARIOS, LO HICE A LOS FINES DE QUE PUEDAN ENTENDER LA LOGICA QUE INTENTE USAR
