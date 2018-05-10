#ifndef ABMPUBLICACIONES_H_INCLUDED
#define ABMPUBLICACIONES_H_INCLUDED
#include "abmCliente.h"
typedef struct{

int idCliente;
int rubro;
char texto[64];
int idAviso;
int estado;
int isEmpty;

}Publicacion;

int abmPublicacion_init(Publicacion *array, int size);
int abmPublicacion_alta(Publicacion *array,int size);
int abmPublicacion_Pausar(Publicacion *array, int size, int id);
int abmPublicacion_Reanudar(Publicacion *array, int size, int id);
int abmPublicacion_mostrarClientes(Cliente *arrayCliente, Publicacion *arrayPublicacion, int sizeCliente, int sizePublicacion);
int abmPublicacion_mostrarPublicacion(Cliente *arrayCliente, Publicacion *arrayPublicacion, int size);

#endif // ABMPUBLICACIONES_H_INCLUDED
