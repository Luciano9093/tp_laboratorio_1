#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define LENGHT 1000
#define TRUE 1
#define FALSE 0
int main()
{
   setbuf(stdout,NULL);
   int opcion;
   int inicio;
   int alta;
   int modificar;
   int baja;
   int altaFlag = -1;
   char salir='n';
   sEmployee aEmployee[LENGHT];

   inicio=initEmployees(aEmployee,LENGHT);
   if(inicio==-1)
   {
       printf("NO SE HA PODIDO INICIALIZAR EL PROGRAMA. PONGASE EN CONTACTO CON SU PROVEDOR.");
   }
   else
   {
       do
       {
           system("cls");
           printf("..................NOMINA DEL PERSONAL.........................\n\n");
           printf("MENU DE OPCIONES.\n\n");
           printf("1. ALTAS.\n");
           printf("2. MODIFICAR.\n");
           printf("3. BAJA.\n");
           printf("4. INFORMAR.\n");
           printf("5. SALIR.\n\n");
           printf("ELIGA UNA OPCION: ");
           fflush(stdin);
           scanf("%d", &opcion);

           switch(opcion)
           {
                case 1:
                    alta=addEmployee(aEmployee, LENGHT);
                    if(alta==-1)
                    {
                       printf("NO SE HA PODIDO DAR DE ALTA AL EMPLEADO, VERIFIQUE QUE HAYA ESPACIO EN EL PROGRAMA E INTENTE NUEVAMENTE\n\n");
                    }
                    else
                    {
                        printf("EL EMPLEADO A SIDO DADO DE ALTA EXITOSAMENTE\n\n");
                        altaFlag=0;
                    }
                    break;
                 case 2:
                    if(altaFlag==0)
                    {
                        modificar=findEmployeeById(aEmployee, LENGHT);
                    }
                    else
                    {
                        printf("NO EXISTEN EMPLEADOS DADOS DE ALTA EN ESTE PROGRAMA. PARA HACERLO SELECCIONE LA OPCION Nro 01\n\n");
                    }
                    if(modificar==-1)
                    {
                        printf("NO SE HA PODIDO HALLAR AL EMPLEADO. POR FAVOR VERIFIQUE QUE EL ID INGRESADO FUE CORRECTO\n\n.");
                    }
                    break;

                 case 3:
                    if(altaFlag==0)
                    {
                        baja=removeEmployee(aEmployee,LENGHT);
                        if(baja==-1)
                        {
                            printf("NO SE HA PODIDO DAR DE BAJA AL EMPLEADO, VERIFIQUE QUE HAYA AGREGADO EL ID CORRECTO.\n\n");
                        }
                        break;
                    }
                case 4:
                    if(altaFlag==0)
                    {
                       printEmployees(aEmployee,LENGHT);
                    }
                    else
                    {
                        printf("*.............AUN NO HA DADO DE ALTA EMPLEADO ALGUNO, SELECCIONE LA OPCION Nro.1............*\n\n");
                    }
                    break;
           }
           system("pause");
        }
        while(salir=='n');
    }
}





