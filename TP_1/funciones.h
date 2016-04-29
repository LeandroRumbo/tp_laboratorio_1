#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int Sumar(int x, int y)
{
  int suma;
  suma=x+y;
  return suma;
}

int Restar(int x, int y)
{
   int resta;
   resta=x-y;
   return resta;
}

int Multiplicacion(int x,int y)
{
   int multiplica;
   multiplica=x*y;
   return multiplica;
}

double Division(int x, int y)
{
   double divi;
   divi=1.0*x/y;
   return divi;
}

double Factorial(int x)
{
   double res;
   if(x==1)
     return 1;
   res=x*Factorial(x-1);
   return res;
}

int validaS_N()
{
    char respuesta;

    printf("Desea continuar s/n?");
    fflush(stdin);
    scanf("%c", &respuesta);
    respuesta = toupper(respuesta);


    while(respuesta != 'S' && respuesta != 'N'){
        printf("ERROR REINGRESE, Desea continuar S/N?");
        fflush(stdin);
        scanf("%c", &respuesta);
        respuesta = toupper(respuesta);
        system("cls");
    }

    if(respuesta == 'S'){
        return 1;
    }
    else{

        return 0;
    }
}
#endif
