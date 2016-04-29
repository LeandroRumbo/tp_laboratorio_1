#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "funciones.h"
#define c 20

int main()
{
    EPersona per[c];
    char seguir='s';
    int opcion=0, i;

    for(i=0; i<c; i++)
    {
        per[i].estado=0;
    }
    per[0].cont=0;

    for(i=0;i<c;i++)
    {
        if(per[i].estado==1)
        {
            per[0].cont++;
        }
    }

    while(seguir=='s')
    {
        system("cls");
        printf("Bienvenido al menu de opciones.\n");
        printf("En este momento hay %d/20 personas agregadas\n",per[0].cont);
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                Altas(per);
                break;
            case 2:
                Eliminar(per);
                break;
            case 3:
                Ordenamiento(per);
                break;
            case 4:
                GrafEdad(per);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("ERROR: Por favor Ingrese una opcion entre 1 y 5");
                system("pause");
        }
    }
    return 0;
}
