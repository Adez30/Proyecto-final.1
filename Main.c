#include <stdio.h>
#include "declaraciones.h"

int main()
{
    int opcion;
    struct herramientas herramientas[MAX_HERRAMIENTAS];
    struct Usuario usuario[MAX_USUARIO];
    int num_herramientas = 0;
    int num_usuarios = 0;

    registro(usuario, &num_usuarios);

    while (1)
    {

        printf("Menu:\n");
        printf("1. Ver herramientas.\n");
        printf("2. Retirar herramienta.\n");
        printf("3. Buscar herramienta.\n");
        printf("4. Agregar herramienta. \n");
        printf("4. Ver info de la herramienta.\n");
        printf("6. SALIR.\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Ha seleccionado la Opcion 1.\n");
            mostrarHerramientas(herramientas, num_herramientas);
            break;
        case 2:
            printf("Ha seleccionado la Opcion 2.\n");
            retirar(herramientas, &num_herramientas);
            break;
        case 3:
            printf("Ha seleccionado la Opcion 3.\n");
            buscar_herramientas(herramientas, num_herramientas);
            break;
        case 4:
            printf("Ha seleccionado la Opcion 4.\n");
            agregar_Herramientas(herramientas, &num_herramientas);
            break;
        case 5:
            printf("Saliendo del programa. Adiós.\n");
            return 0;
        default:
            printf("Opción no válida. Por favor, seleccione una opción válida.\n");
        }
    }

    return 0;
}
