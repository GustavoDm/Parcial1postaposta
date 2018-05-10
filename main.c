#include <stdio.h>
#include <stdlib.h>
#include "abmCliente.h"
#include "abmPublicaciones.h"
#include "getsValids.h"
#define CANTIDADCLIENTES 9
#define CANTIDADAVISOS 4

int main()
{
    int menu,idCliente, idPublicacion;
    Cliente clientes[CANTIDADCLIENTES];
    Publicacion publicaciones[CANTIDADAVISOS];
    abmCliente_init(clientes, CANTIDADCLIENTES);
    abmPublicacion_init(publicaciones, CANTIDADAVISOS);

   do
    {
       get_validInt("MENU\n\n1:Alta Cliente\n2:Modificar Cliente\n3:Baja cliente\n4:Publicar aviso\n5:Pausear Aviso\n6:Reanudar aviso\n","Ingrese una opcion correcta",&menu,0,9,2);
       fflush(stdin);
       printf("%d",menu);

        switch(menu)
        {

        case 1:
            abmCliente_alta(clientes, CANTIDADCLIENTES);
            break;
        case 2:
            printf("Ingrese un ID: ");
            scanf("%d", &idCliente);
            abmCliente_modificacion(clientes, CANTIDADCLIENTES, idCliente);
            break;
        case 3:
            printf("Ingrese un ID: ");
            scanf("%d", &idCliente);
            abmCliente_baja(clientes, CANTIDADCLIENTES, idCliente);
            break;
        case 4:
            abmPublicacion_alta(publicaciones, CANTIDADAVISOS);
            break;
        case 5:
            printf("Ingrese un ID: ");
            scanf("%d", &idPublicacion);
            abmPublicacion_Pausar(publicaciones, CANTIDADAVISOS, idPublicacion);
            break;
        case 6:
            printf("Ingrese un ID: ");
            scanf("%d", &idPublicacion);
            abmPublicacion_Reanudar(publicaciones, CANTIDADAVISOS,idPublicacion);
            break;
        case 7:
            abmPublicacion_mostrarClientes(clientes,publicaciones,CANTIDADCLIENTES,CANTIDADAVISOS);
        case 8:
            abmPublicacion_mostrarPublicacion(clientes, publicaciones, CANTIDADAVISOS);

            }
    }while(menu !=9);

        return 0;
    }
