#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int A=0, B=0, sumar, resta, multiplicaciones, flag=1;
    double factorial, divisiones;
    char continua;
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%d)\n",A);
        printf("2- Ingresar 2do operando (B=%d)\n",B);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);


switch(opcion)
        {
            case 1:
                printf("Ingrese el primer operando: \n");
                scanf("%d",&A);
                break;

            case 2:
                printf("Ingrese el segundo operando: \n");
                scanf("%d",&B);
                break;
            case 3:
                sumar=Sumar(A,B);
                printf("La suma de los dos operandos (%d + %d) es: %d \n",A,B,sumar);
                break;
            case 4:
                resta=Restar(A,B);
                printf("La resta de los dos operandos (%d - %d)es: %d \n",A,B,resta);
                break;
            case 5:
                if(A==0 || B==0)
                {
                  printf("ERROR.La division por cero no es posible. Modifique el operando A y/o B que sea mayor a cero: \n");
                  flag=0;
                }
                else
                {
                divisiones=Division(A,B);
                printf("La division de los dos operandos (%d / %d) es: %.2lf \n",A,B,divisiones);
                }
                break;
            case 6:
                multiplicaciones=Multiplicacion(A,B);
                printf("La multiplicacion de los dos operandos (%d * %d) es: %d \n",A,B,multiplicaciones);
                break;
            case 7:
                factorial=Factorial(A);
                printf("El factorial del primer operando (%d!) es: %.0lf \n",A,factorial);
                break;
            case 8:
                if(A==0 || B==0)
                {
                  printf("ERROR.La division por cero no es posible. Modifique el operando A para que sea mayor a cero:  \n");
                  flag=0;
                }
                else
                {
                sumar=Sumar(A,B);
                resta=Restar(A,B);
                divisiones=Division(A,B);
                multiplicaciones=Multiplicacion(A,B);
                factorial=Factorial(A);
                printf("La suma de los dos operandos (%d + %d) es: %d \n",A,B,sumar);
                printf("La resta de los dos operandos (%d - %d) es: %d \n",A,B,resta);
                printf("La division de los dos operandos (%d / %d) es: %.2lf \n",A,B,divisiones);
                printf("La multiplicacion de los dos operandos (%d * %d) es: %d \n",A,B,multiplicaciones);
                printf("El factorial del primer operando (%d!) es: %.0lf \n",A,factorial);
                }
                break;
            case 9:
                seguir = 'n';
                break;

        }
     continua=validaS_N();

    }
return 0;

}
