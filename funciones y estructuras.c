#include <stdio.h>
#include <string.h>

#define MAX_HERRAMIENTAS 50
#define MAX_USUARIO 20

struct herramientas
{
    char Nombre_de_la_herramienta[MAX_HERRAMIENTAS];
    char Tipo_de_herramienta[50];
};

struct Usuario
{
    char Nombre_del_usuario[20];
    char Apellido[20];
    char Area_de_trabajo[20];
    char Numero_de_telefono[40];
};

void mostrarHerramientas(struct herramientas herramientas[], int num_herramientas)
{
    if (num_herramientas > 0)
    {
        printf("Lista de las herramientas:\n");
        for (int i = 0; i < num_herramientas; i++)
        {
            printf("- %s %s (%s)\n", herramientas[i].Nombre_de_la_herramienta, herramientas[i].Tipo_de_herramienta);
        }
    }
    else
    {
        printf("No hay herramienstas para mostrar.\n");
    }
}

void buscar_herramientas(struct herramientas herramientas[], int num_herramientas)
{
    if (num_herramientas > 0)
    {
        char nombre_buscar[50];
        printf("Ingrese el nombre de la herramienta que desea buscar: ");
        scanf("%s", nombre_buscar);

        int encontrado = 0;
        for (int i = 0; i < num_herramientas; i++)
        {
            if (strcmp(herramientas[i].Nombre_de_la_herramienta, nombre_buscar) == 0)
            {
                encontrado = 1;
                printf("Detalles de la herramienta:\n");
                printf("Herramienta: %s %s (%s)\n", herramientas[i].Nombre_de_la_herramienta, herramientas[i].Tipo_de_herramienta);
                break;
            }
        }

        if (!encontrado)
        {
            printf("Herramienta no encontrada.\n");
        }
    }
    else
    {
        printf("No hay herramientas para buscar.\n");
    }
}

void registro(struct Usuario usuario[], int num_usuarios[])
{
    if (*num_usuarios < MAX_USUARIO)
    {
        printf("Ingrese los detalles del Usuario:\n");
        struct Usuario nuevo_usuario;

        printf("Nombre del Usuario: ");
        scanf("%s", nuevo_usuario.Nombre_del_usuario);
        printf("Apellido del usuario: ");
        scanf("%s", nuevo_usuario.Apellido);
        printf("Area de trabajo del usuario: ");
        scanf("%s", nuevo_usuario.Area_de_trabajo);

        // Se solicita y guarda la contraseña del usuario
        char contrasena[50];
        printf("Ingrese una contraseña para el usuario: ");
        scanf("%s", contrasena);

        // Almacena la contraseña en un archivo
        FILE *archivo;
        archivo = fopen("C:/Users/angel/OneDrive/Escritorio/PROGRAMACION/Proyecto final.1/contrasenas.txt", "a"); // Abre el archivo en modo 'append'
        if (archivo != NULL)
        {
            fprintf(archivo, "%s %s\n", nuevo_usuario.Nombre_del_usuario, contrasena);
            fclose(archivo);
        }
        else
        {
            printf("Error al abrir el archivo.\n");
            return;
        }

        usuario[(*num_usuarios)++] = nuevo_usuario;
        printf("Bienvenido %s\n", nuevo_usuario.Nombre_del_usuario);
        // Continuar con las operaciones que desees realizar después del registro
    }
    else
    {
        printf("La lista de usuarios está completa.\n");
    }
}

void agregar_Herramientas(struct herramientas herramienta[], int *num_herramienta)
{
    if (*num_herramienta < MAX_HERRAMIENTAS)
    {
        printf("Ingrese los detalles de la heramienta CD:\n");
        struct herramientas nueva_herramienta;
        printf("Nombre de la herramienta: ");
        scanf("%s", nueva_herramienta.Nombre_de_la_herramienta);
        printf("Tipo de herramienta: ");
        scanf("%s", nueva_herramienta.Tipo_de_herramienta);

        herramienta[(*num_herramienta)++] = nueva_herramienta;
        printf("Herramienta agregada correctamente.\n");
    }
    else
    {
        printf("El inventario esta lleno\n");
    }
}

void retirar(struct herramientas herramientas[], int *num_herramienta)
{
    if (*num_herramienta > 0)
    {
        char nombre_buscar[50];
        printf("Ingrese el nombre de la herramienta que desea retirar: ");
        scanf("%s", nombre_buscar);

        int encontrado = 0;
        for (int i = 0; i < *num_herramienta; i++)
        {
            if (strcmp(herramientas[i].Nombre_de_la_herramienta, nombre_buscar) == 0)
            {
                encontrado = 1;
                for (int j = i; j < *num_herramienta - 1; j++)
                {
                    herramientas[j] = herramientas[j + 1];
                }
                (*num_herramienta)--;
                printf("%s retirada, favor de devolver a tiempo.\n", nombre_buscar);
                break;
            }
        }

        if (!encontrado)
        {
            printf("Herramienta no disponible.\n");
        }
    }
    else
    {
        printf("No hay herramientas disponibles.\n");
    }
}