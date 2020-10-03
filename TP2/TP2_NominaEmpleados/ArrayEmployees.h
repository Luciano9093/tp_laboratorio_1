#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#endif // ARRAYEMPLOYEES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define NAME_LASTNAME 51



/**
 * \Brief ESTRUCTURA DE EMPLEADOS;
 */
typedef struct
   {
       int id;
       char lastName[NAME_LASTNAME];
       char name[NAME_LASTNAME];
       float salary;
       int sector;
       int isEmpty;
   }sEmployee;


/**
 * \Brief PROTOTIPOS DE FUNCIONES;
 */
int initEmployees(sEmployee* aEmployees, int length);
int addEmployee(sEmployee* aEmployees, int length);
int findEmployeeById(sEmployee*aEmployees,int length);
int removeEmployee(sEmployee* aEmployees, int length);
int printEmployees(sEmployee* aEmployees, int length);

