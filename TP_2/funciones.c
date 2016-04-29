#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "funciones.h"
#define c 4

    EPersona lista[c];
    int me18=0, E18Y35=0, ma35=0;

int buscarEstado(EPersona lista[])
{
    int i, pos=-1;
    for(i=0; i<c; i++)
    {
        if(lista[i].estado==0)
        {
            pos=i;
            break;
        }

    }
    return pos;
}
long int Documento(long int dni)
{
        printf("Ingrese el DNI: ");
        scanf("%ld",& dni);
        while(dni<1000000 || dni > 99999999)
        {
            system("cls");

            printf("\nERROR: Ingrese un DNI valido: ");
            scanf("%ld",&dni);
        }
        return dni;
}
int vejez(int edad)
{
        printf("Ingrese la edad: ");
        scanf("%d",&edad);

        while(edad<1 || edad > 120)
        {
            system("cls");
            printf("\nERROR: Ingrese una edad entre 1 y 120: ");
            scanf("%d",&edad);
        }
        return edad;
}
void Altas(EPersona lista[])
{
    system("cls");
    int i, pos, doble=0, auxEd=0;
    long int auxdni=0;

    pos=buscarEstado(lista);
    if(pos!=-1)
    {
       auxdni=Documento(auxdni);

        for(i=0; i<c; i++)
        {
            if(auxdni==lista[i].dni)
            {
                doble=1;

            }
            break;
        }
        if(doble==0)
        {
            printf("Ingrese el nombre: ");
            fflush(stdin);
            gets(lista[pos].nombre);
            strlwr(lista[pos].nombre);
            auxEd=vejez(auxEd);
            if(auxEd >= 18)
            {
                if(auxEd >35)
                {
                    ma35++;
                }
                else
                {
                    E18Y35++;
                }
            }
            else
            {
                me18++;
            }

            lista[pos].edad=auxEd;
            lista[pos].dni=auxdni;
            lista[pos].estado=1;
            lista[0].cont++;
        }
        else
        {
            printf("ERROR: El DNI ya ha sido ingresado");

        }
    }

    else
	{
		printf("No hay lugar para guardar el dato, borre uno e intente nuevamente");
	}
    system("pause");

}
void Eliminar(EPersona lista[])
{
    long int auxdni;
    int i, bandera=0;
    char rta;

    system("cls");
    printf("Ingrese DNI de la persona a eliminar: ");
    scanf("%ld",&auxdni);
    for(i=0; i<c; i++)
    {
        if(auxdni==lista[i].dni)
        {
            printf("*DNI: %ld\n*Nombre: %s\n*Edad: %d\n",lista[i].dni, lista[i].nombre, lista[i].edad);
            printf("Desea elminar esta persona? (S o N)");
            rta=tolower(getch());
            validar_S_N(rta);
            if(lista[i].edad >=18)
            {
                if(lista[i].edad > 35)
                {
                    ma35--;
                }
                else
                {
                    E18Y35--;
                }
            }
            else
            {
                me18--;
            }

            if(rta=='s')
            {
                system("cls");
                lista[i].estado=0;
                printf("\nSe han eliminado los datos\n");
                lista[0].cont--;
                system("pause");
            }
            else
            {
                system("cls");
                printf("\nLos datos no han sido eliminados");
                system("pause");
            }
            bandera=1;
            break;
        }
    }
    if(bandera==0)
    {
        printf("El DNI ingresado no existe");
        system("pause");
    }

}
void Ordenamiento(EPersona lista[])
{
    int i,j;
    EPersona auxNom;

    for(i=0; i<c-1; i++)
    {
            for(j=i+1; j<c; j++)
            {
                if(strcmp(lista[i].nombre, lista[j].nombre)>0)
                {
                            auxNom=lista[i];
                            lista[i]=lista[j];
                            lista[j]=auxNom;
                }
            }
    }
            system("cls");
            printf("Lista ordenada alfabeticamente\n");

            for(i=0; i<c; i++)
            {
                if(lista[i].estado==1)
                {
                    strupr(lista[i].nombre);
                    printf("\n*Nombre: %s\n*DNI: %ld\n*Edad: %d\n\n",lista[i].nombre, lista[i].dni, lista[i].edad);
                }
            }
              system("pause");
}
void GrafEdad(EPersona lista[])
{
    int i, band=0, mayor;

        system("cls");
        if(me18>E18Y35 && me18> ma35)
        {
            mayor=me18;
        }
        else
        {
            if(E18Y35>me18 && E18Y35> ma35)
                mayor=E18Y35;
            else
            {
                mayor=ma35;
            }
        }
        for(i=mayor; i>0; i--)
        {
            if(me18>= i)
            {
                printf(" * ");
            }
            if(E18Y35>= i)
            {
                    printf("\t  *  ");
                    band=1;
            }
            if(ma35>=i)
            {
                if(band==0)
                    printf("\t\t * ");
             else
            {
                printf("\t * ");
            }
        }
               printf("\n");
        }
        printf("<18\t18-35\t>35\n");
        system("pause");
}
char validar_S_N(char respuesta)
{
          while(respuesta != 's' && respuesta != 'n' )
          {
              printf("\nERROR: Ingrese una respuesta valida. s/n");
              respuesta=tolower(getch());
          }
          return respuesta;
}
