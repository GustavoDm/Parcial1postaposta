#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "abmCliente.h"
#include "abmPublicaciones.h"



int informes_mostrarClientes(Cliente *arrayCliente, Publicacion *arrayPublicacion, int sizeCliente, int sizePublicacion);
int informes_mostrarPublicacion(Cliente *arrayCliente, Publicacion *arrayPublicacion, int sizePublicacion, int sizeCliente);
int informes_PublicacionesTotales(Publicacion* arrayPublicacion,int sizePublicacion,int idCliente);
int informes_PublicacionesActivas(Publicacion* arrayPublicacion,int sizePublicacion,int idCliente);
int informes_PublicacionesPausadas(Publicacion* arrayPublicacion,int sizePublicacion,int idCliente);
int informes_ClienteMaxPub(Publicacion *arrayPublicacion, Cliente *arrayCliente, int sizePublicacion, int sizeCliente);
int informes_publicacionesPorRubro(Publicacion* arrayPublicacion,int sizePublicacion);
#endif // INFORMES_H_INCLUDED
