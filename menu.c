#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "mascota.h"
#define TAM 30
#define LENMASCOTA 10
#define LENRAZA 10
#define VACIO 0
#define OCUPADO 1

int IngresarDatoEntero()
{
    int opcion;
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

char IngresarDatoChar()
{
    char salida;

    fflush(stdin);
    scanf("%c",&salida);
    salida=tolower(salida);

    return salida;
}

int Menu()
{
    int opcion;

    printf("\n--------- MASCOTAS ---------\n");
    printf("1- Mostrar lista \n");
    printf("2- Borrar Mascota \n");
    printf("3- Ordenar mascota por pais de origen  \n");
    printf("4- Alta de Raza  \n");
    printf("5- Modificacion de mascota  \n");
    printf("6- Pais de origen con mayor mascotas \n");
    printf("7- Salir \n");

    opcion=IngresarDatoEntero();

    return opcion;
}

void MostrarMenu()
{
    eRaza listaRaza[LENRAZA];
    eMascotas listaMascota[LENMASCOTA];
    char salida;

    VerificacionInicioMascota(listaMascota,LENMASCOTA);
    VerificacionInicioRaza(listaRaza,LENRAZA);
    HarcodearMascotas(listaMascota);
    HardcodearRaza(listaRaza);


    do
    {
        switch(Menu())
        {
            case 1:
                system("cls");
                printf("\n---------  1- Mostrar lista  ---------\n");
                MostrarListado(listaMascota,listaRaza,LENMASCOTA,LENRAZA);
            break;

            case 2:
                system("cls");
                printf("\n---------  2- Borrar Mascota  ---------\n");
                VerificarFuncionBorrar(listaMascota,listaRaza,LENMASCOTA,LENRAZA);

            break;

            case 3:
                system("cls");
                printf("\n---------  3- Ordenar mascota por pais de origen  ---------\n");
                VerificarFuncionOrdenar(listaMascota,listaRaza,LENMASCOTA,LENRAZA);
            break;

            case 4:
                system("cls");
                printf("\n---------  4- Alta de Raza  ---------\n");
                CargarMascotayRaza(listaMascota,listaRaza,LENMASCOTA,LENRAZA);
            break;

            case 5:
                system("cls");
                printf("\n---------  5- Modificacion de mascota  ---------\n");
            break;

            case 6:
                system("cls");
                printf("\n---------  6- Pais de origen con mayor mascotas  ---------\n");

            break;

            case 7:
                system("cls");
                printf("\n---------  7- Salir  ---------\n");
                salida=ValidarRepuesta("Seguro que desea salir?S-N ","ERROR Ingrese S para salir o N para volver al menu ", 's','n');
                system("cls");
            break;


            default:
                system("cls");
                printf("ERROR, ingrese una opcion \n");

            break;
        }
     }while(salida!='s');
}

char ValidarRepuesta(char msg[],char errorMsg[],char s, char n)
{
    char salida;

    printf("%s",msg);
    salida=IngresarDatoChar();

    while(salida!=n &&salida!=s)
    {
        printf("%s",errorMsg);
        salida=IngresarDatoChar();
    }
    return salida;
}


int ValidarRepuestaInt(char msg[],char errorMsg[],int numUno, int numDos)
{
    int salida;

    printf("%s",msg);
    salida=IngresarDatoEntero();
    while(salida<=numUno||salida>=numDos)
    {
        printf("%s",errorMsg);
        salida=IngresarDatoEntero();
    }
    return salida;
}

int GetInt(char msg[],char msgError[])
{
   int dato;
    printf("%s",msg);
    dato=IngresarDatoEntero();

   while(dato<0)//
   {
       printf("%s",msgError);
       dato=IngresarDatoEntero();
   }

   return dato;
}

void GetString(char dato[], char msg[],char msgError[], int len)
{
    char buffer[len];
    int i;

    printf("%s",msg);
    fflush(stdin);
    scanf("%[^\n]",buffer);
    strlwr(buffer);


    buffer[0]=toupper(buffer[0]);

    for(i=0;i<len;i++)
    {
        if(isspace(buffer[i]))
        {
            buffer[i+1]=toupper(buffer[i+1]);
        }
    }

   while(strlen(buffer)>len-1)//mide el largo de la cadena
   {
        printf("%s",msgError);
        fflush(stdin);
        scanf("%[^\n]",buffer);
        strlwr(buffer);


        buffer[0]=toupper(buffer[0]);

        for(i=0;i<len;i++)
        {
            if(isspace(buffer[i]))
            {
                buffer[i+1]=toupper(buffer[i+1]);
            }
        }
   }
   strcpy (dato, buffer);
}


