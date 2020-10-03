#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define TRUE 1
#define FALSE 0
#define LENGHT 1000
#define NAME_LASTNAME 51


int initEmployees(sEmployee* aEmployees, int length)
{
    int retorno=-1;
    int i;
    if(aEmployees!=NULL && length>0)
    {
        retorno=0;
        for (i=0; i<length; i++)
        {
            aEmployees[i].isEmpty=TRUE;
        }
    }

    return retorno;
}
int addEmployee(sEmployee* aEmployees, int length)
{
    int retorno=-1;
    if(aEmployees!=NULL && length>0)
    {
        for(int i=0; i<length; i++)
        {
            if(aEmployees[i].isEmpty==TRUE)
            {
                aEmployees[i].id=i+1;
                aEmployees[i].isEmpty=FALSE;
                printf("Ingrese Apellido: ");
                fflush(stdin);
                gets(aEmployees[i].lastName);
                while(strlen(aEmployees[i].lastName)>NAME_LASTNAME)
                {
                    printf("Ingreso invalido. Intente agregar el apellido nuevamente: ");
                    fflush(stdin);
                    gets(aEmployees[i].lastName);
                }
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(aEmployees[i].name);
                while(strlen(aEmployees[i].name)>NAME_LASTNAME)
                {
                    printf("Ingreso invalido. Intente agregar el nombre nuevamente: ");
                    fflush(stdin);
                    gets(aEmployees[i].name);
                }
                printf("Ingrese el salario: ");
                scanf("%f",&aEmployees[i].salary);
                while(aEmployees[i].salary==0 || aEmployees[i].salary<0)
                {
                        fflush(stdin);
                        printf("Ingreso invalido. Ingrese el salario nuevamente: ");
                        scanf("%f",&aEmployees[i].salary);
                }
                printf("Ingrese sector de trabajo: ");
                scanf("%d",&aEmployees[i].sector);
                while(aEmployees[i].sector==0 || aEmployees[i].sector<0)
                {
                        fflush(stdin);
                        printf("Ingreso invalido. Ingrese el sector nuevamente: ");
                        scanf("%d",&aEmployees[i].sector);
                }
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int findEmployeeById(sEmployee*aEmployees,int length)
{
    int retorno=-1;
    int idEmpleado;
    int opcion;
    char confirmacion;
    char salir='n';

    if(aEmployees!=NULL && length>0)
    {
        printf("Ingrese ID del empleado: ");
        scanf("%d",&idEmpleado);
        printf("\n............INFORME DE EMPLEADOS...................\n\n");
        for(int i=0; i<length; i++)
        {
            if(aEmployees[i].id==idEmpleado && aEmployees[i].isEmpty==FALSE)
            {
                retorno=0;
                printf("ID = %d\nAPELLIDO = %s\nNOMBRE = %s\nSALARIO = %.2f\nSECTOR = %d\n\n",aEmployees[i].id, aEmployees[i].lastName, aEmployees[i].name, aEmployees[i].salary, aEmployees[i].sector);
                printf("\nDesea realizar alguna modificacion?. Ingrese 'S' para confirmar 'N' para salir: ");
                fflush(stdin);
                scanf("%c",&confirmacion);
                confirmacion=tolower(confirmacion);
                while(confirmacion!='s' && confirmacion!='n')
                {
                    printf("Respuesta no valida. Ingrese [S] para confirmar o [N] para salir.\n");
                    fflush(stdin);
                    scanf("%c",&confirmacion);
                    confirmacion=tolower(confirmacion);
                }
                if(confirmacion=='s')
                {
                   do
                   {
                        system("cls");
                        printf("\n......SELECCIONE QUE PARAMETRO DESEA MODIFICAR.....\n\n");
                        printf("1. APELLIDO.\n");
                        printf("2. NOMBRE.\n");
                        printf("3. SALARIO.\n");
                        printf("4. SECTOR.\n");
                        printf("5. SALIR.\n\n");
                        printf("ELIGA UNA OPCION (para finalizar eliga la Opcion Nro. 05): ");
                        fflush(stdin);
                        scanf("%d", &opcion);
                        switch(opcion)
                        {
                            case 1:
                                printf("Ingrese Apellido: ");
                                fflush(stdin);
                                gets(aEmployees[i].lastName);
                                while(strlen(aEmployees[i].lastName)>NAME_LASTNAME)
                                {
                                    printf("Ingreso invalido. Intente agregar el apellido nuevamente: ");
                                    fflush(stdin);
                                    gets(aEmployees[i].lastName);
                                }
                                break;
                            case 2:
                                 printf("Ingrese nombre: ");
                                 fflush(stdin);
                                 gets(aEmployees[i].name);
                                 while(strlen(aEmployees[i].name)>NAME_LASTNAME)
                                 {
                                     printf("Ingreso invalido. Intente agregar el nombre nuevamente: ");
                                     fflush(stdin);
                                     gets(aEmployees[i].name);
                                 }
                                 break;
                            case 3:
                                 printf("Ingrese el salario: ");
                                 scanf("%f",&aEmployees[i].salary);
                                 while(aEmployees[i].salary==0 || aEmployees[i].salary<0)
                                 {
                                     fflush(stdin);
                                     printf("Ingreso invalido. Ingrese el salario nuevamente: ");
                                     scanf("%f",&aEmployees[i].salary);
                                 }
                                 break;
                            case 4:
                                 printf("Ingrese sector de trabajo: ");
                                 scanf("%d",&aEmployees[i].sector);
                                 while(aEmployees[i].sector==0 || aEmployees[i].sector<0)
                                 {
                                    fflush(stdin);
                                    printf("Ingreso invalido. Ingrese el sector nuevamente: ");
                                    scanf("%d",&aEmployees[i].sector);
                                 }
                                 break;
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
                                if(salir=='s')
                                {
                                    printf("LAS MODIFICACIONES HAN SIDO GUARDADAS...\n\n");
                                }
                                break;
                            default:
                                printf("Seleccion invalida, eliga opcion nuevamente\n\n");
                                break;
                        }
                   }
                   while(salir=='n');
            }
            else
            {
                printf("MODIFICACIONES CANCELADAS...\n\n");
            }
        }

      }
    }
    return retorno;
}

int removeEmployee(sEmployee*aEmployees,int length)
{
    int retorno=-1;
    int idBaja;
    char confirmacion;
    if(aEmployees!=NULL && length>0)
    {
        printf("Ingrese el ID del empleado a dar de baja: \n");
        scanf("%d", &idBaja);
        for(int i=0; i<length; i++)
        {
            if(aEmployees[i].id==idBaja)
            {
                printf("\nCONFIRMA LA BAJA DEL EMPLEADO QUE A CONTINUACION SE DETALLA?\n\n");
                printf("ID = %d\nAPELLIDO = %s\nNOMBRE = %s\nSALARIO = %.2f\nSECTOR = %d\n\n",aEmployees[i].id, aEmployees[i].lastName, aEmployees[i].name, aEmployees[i].salary, aEmployees[i].sector);
                printf("Ingrese 'S' para confirmar, 'N' para cancelar. ");
                fflush(stdin);
                scanf("%c",&confirmacion);
                confirmacion=tolower(confirmacion);
                while(confirmacion!='s' && confirmacion!='n')
                {
                    printf("Respuesta no valida. Ingrese [S] para confirmar o [N] para cancelar.\n");
                    fflush(stdin);
                    scanf("%c",&confirmacion);
                    confirmacion=tolower(confirmacion);
                }
                if(confirmacion=='s')
                {
                    aEmployees[i].isEmpty=TRUE;
                    printf("EL EMPLEADO A SIDO DADO DE BAJA.\n\n");
                    retorno=0;
                    break;
                }
                else
                {
                    printf("BAJA CANCELADA.\n\n");
                    break;
                }
            }
        }
    }
    return retorno;
}

int printEmployees(sEmployee*aEmployees,int length)
{
    int retorno=-1;
    int contadorSalario=0;
    int sueldoMayor=0;
    float sumaSalario=0;
    float promedioSalario;

    if (aEmployees!=NULL && length>0)
    {
        printf("............INFORME DE EMPLEADOS...................\n\n");
        for(int i=0; i<length; i++)
        {
            if(aEmployees[i].isEmpty==FALSE)
            {
                sumaSalario+=aEmployees[i].salary;
                contadorSalario++;

                printf("APELLIDO = %s\nNOMBRE = %s\nSECTOR = %d\n\n",aEmployees[i].lastName, aEmployees[i].name, aEmployees[i].sector);

                retorno=0;
            }

        }
        promedioSalario=sumaSalario/contadorSalario;
        printf("Total salarios = %.2f\n",sumaSalario);
        printf("Salario promedio = %.2f\n",promedioSalario);
        for(int i=0; i<length; i++)
        {
            if(aEmployees[i].isEmpty==FALSE && aEmployees[i].salary>promedioSalario)
            {
                sueldoMayor++;
            }
        }
        printf("Cantidad de empleados que superan el sueldo promedio: %d\n\n",sueldoMayor);
    }
    return retorno;
}

