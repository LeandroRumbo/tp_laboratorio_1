#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {
    char nombre[50];
    int edad;
    int estado;
    int cont;
    long int dni;
}EPersona;

int buscarEstado(EPersona lista[]);
long int Documento(long int dni);
int vejez(int edad);
char validar_S_N(char respuesta);
void Eliminar(EPersona lista[]);
void Ordenamiento(EPersona lista[]);
void GrafEdad(EPersona lista[]);
void Altas(EPersona lista[]);

#endif // FUNCIONES_H_INCLUDED
