#ifndef ABMCLIENTE_H_INCLUDED
#define ABMCLIENTE_H_INCLUDED

typedef struct{

int idCliente;
char nombre[50];
char apellido[50];
int cuil;
int isEmpty;

}Cliente;

int abmCliente_init(Cliente *array, int size);
int abmCliente_alta(Cliente *array,int size);
int abmCliente_buscarPorId(Cliente *array,int size, int id);
int abmCliente_baja(Cliente *array,int size, int id);
int abmCliente_modificacion(Cliente* array, int size, int id);

#endif // ABMCLIENTE_H_INCLUDED
