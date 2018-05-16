#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abmCliente.h"
#include "getsValids.h"


static int proximoId(void);
static int buscarLugarLibre(Cliente* array,int size);

int abmCliente_init(Cliente *array, int size)
{
    int i;
    int retorno=-1;
    if(size>0&& array !=NULL)
    {
        for(i=0; i<size; i++)
        {
            array[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

int abmCliente_alta(Cliente *array,int size)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    int cuil;


    if(size > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,size);
        if(i >= 0)
        {
            if(!get_validLetras("\nIngrese su nombre? ","\nEso no es un nombre","El maximo es 50",nombre,50,3))
            {
                if(!get_validLetras("\nIngrese su apellido? ","\nEso no es un apellido","El maximo es 50",apellido,50,3))
                {
                    if(!get_validInt("\nIngrese su Cuil?(sin usar guiones) ","\nEso no es un Cuil",&cuil,0,99999999,2))
                    {
                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        strcpy(array[i].apellido,apellido);
                        array[i].cuil = cuil;
                        array[i].idCliente = proximoId();
                        array[i].isEmpty = 0;
                        printf("El ID del cliente es: %d\n", array[i].idCliente);
                    }
                }

            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int abmCliente_buscarPorId(Cliente *array,int size, int id)
{
    int retorno = -1;
    int i;
    if(size > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<size;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int abmCliente_baja(Cliente *array,int size, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = abmCliente_buscarPorId(array,size,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}


int abmCliente_mostrar(Cliente *array, int id)
{

    int retorno = -1;
    int i;
    i=id;
    if(array != NULL)
    {
        retorno = 0;

            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %s - %d - %d\n",array[i].idCliente, array[i].nombre,array[i].apellido,array[i].cuil, array[i].isEmpty);
    }
    return retorno;
}

int abmCliente_modificacion(Cliente* array, int size, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char apellido[50];
    int cuil;

    indiceAModificar = abmCliente_buscarPorId(array, size, id);

   if(size > 0 && array != NULL)
    {
        if(indiceAModificar >= 0)
        {
            if(!get_validLetras("\nIngrese su nombre? ","\nEso no es un nombre","El maximo es 50",nombre,50,3))
            {
                if(!get_validLetras("\nIngrese su apellido? ","\nEso no es un apellido","El maximo es 50",apellido,50,3))
                {
                    if(!get_validInt("\nIngrese su Cuil?(sin usar guiones) ","\nEso no es un Cuil",&cuil,0,100,2))
                    {
                        retorno = 0;
                        strcpy(array[indiceAModificar].nombre,nombre);
                        strcpy(array[indiceAModificar].apellido,apellido);
                        array[indiceAModificar].cuil = cuil;
                        array[indiceAModificar].idCliente = proximoId();
                        array[indiceAModificar].isEmpty = 0;
                    }
                }

            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


static int buscarLugarLibre(Cliente *array,int size)
{
    int retorno = -1;
    int i;
    if(size > 0 && array != NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}



