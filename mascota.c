#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "mascota.h"
#define TAM 30
#define VACIO 0
#define OCUPADO 1

int IniciarMascota(eMascotas list[], int len)
{
    int error;
    int i;
    error=1;

    if(list!=NULL&&len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=VACIO;
        }
       error=0;
    }

    return error;
}

int IniciarRaza(eRaza list[], int len)
{
    int error;
    int i;
    error=1;

    if(list!=NULL&&len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=VACIO;
        }
       error=0;
    }

    return error;
}

void VerificacionInicioMascota(eMascotas list[],int len)
{
    if(IniciarMascota(list,len)==0)
    {
        printf("Inicialicion exitosa Mascota -");
    }
    else
    {
        printf("Fallo inicialicion Mascota -");
    }
}

void VerificacionInicioRaza(eRaza list[],int len)
{
    if(IniciarRaza(list,len)==0)
    {
        printf(" Inicialicion exitosa Raza \n");
    }
    else
    {
        printf("Fallo inicialicion Raza \n");
    }
}

void MostrarUnaRazaYMascota(eMascotas unaMascota, eRaza unaRaza)
{
    if(unaMascota.isEmpty==OCUPADO)
    {
        printf("%4d %4d %15s %15s %10s %6d %15s   %c\n",unaRaza.idMascota,unaRaza.idTipo,unaRaza.paisOrigen,unaRaza.raza,unaRaza.tamanio,unaMascota.edad,unaMascota.nombreMascota,unaMascota.sexo);
    }
}

void HarcodearMascotas(eMascotas lista[])
{
    int i;

    int arrayIdMascotas[5]={100,101,102,103,104};
    char arrayNombreMascota[5][TAM]={"Fido","Pancho","Lolo","Clara","Cholo"};
    char arraySexo[5]={'m','f','m','f','m'};
    int arrayedad[5]={5,2,3,1,4};

    for(i=0;i<5;i++)
    {
        lista[i].idMascota=arrayIdMascotas[i];
        strcpy(lista[i].nombreMascota,arrayNombreMascota[i]);
        lista[i].sexo=arraySexo[i];
        lista[i].edad=arrayedad[i];
        lista[i].isEmpty=OCUPADO;
    }
}

void HardcodearRaza(eRaza lista[])
{
    int i;
    int arrayIdMascotas[5]={100,101,102,103,104};
    int arrayidTipo[5]={1,2,1,2,2};
    char arrayPaisOrigen[5][TAM]={"Tailandia","Alemania","Persia","Belgica","Argentina"};
    char arrayTamanio[5][TAM]={"chico","grande","mediano","grande","chico"};
    char arrayRaza[5][TAM]={"Siames","Doberman","Persa","Pastor Belga","Pekines"};

    for(i=0;i<5;i++)
    {
        lista[i].idTipo=arrayidTipo[i];
        lista[i].idMascota=arrayIdMascotas[i];
        strcpy(lista[i].paisOrigen,arrayPaisOrigen[i]);
        strcpy(lista[i].tamanio,arrayTamanio[i]);
        strcpy(lista[i].raza,arrayRaza[i]);
        lista[i].isEmpty=OCUPADO;
    }
}

eRaza DevuelveUnaRaza(eRaza lista[], int len, int id)
{
    eRaza unaRaza;

    for(int i=0; i<len;i++)
    {
        if(lista[i].idMascota==id)
        {
            unaRaza=lista[i];
        }
    }
    return unaRaza;
}

eMascotas DevuelveUnaMascota(eMascotas lista[], int len,int id)
{
    eMascotas unaMascota;

    for(int i=0; i<len;i++)
    {
        if(lista[i].idMascota==id)
        {
            unaMascota=lista[i];
        }
    }
    return unaMascota;
}

void MostrarListado(eMascotas listaMascotas[],eRaza listaRaza[], int lenMascota, int lenRaza)
{
    int id;
    int i;
    int flag=0;
    int error;

    printf(" ID   TIPO           PAIS            RAZA    TAMANIO    EDAD NOMBRE MASCOTA SEXO \n\n");

    for(i=0;i<lenMascota;i++)
    {
        id=listaMascotas[i].idMascota;

        error=BuscarLibre(listaMascotas,lenMascota,OCUPADO);

       if(error>=0)
        {

            JuntarMascotayRaza(listaMascotas,listaRaza,lenMascota,lenRaza,id);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("No hay mascota para mostrar\n");
    }
}

void JuntarMascotayRaza(eMascotas listaMascotas[],eRaza listaRaza[], int lenMascota, int lenRaza,int id)
{
    eMascotas unaMascota;
    eRaza unaRaza;

    unaMascota=DevuelveUnaMascota(listaMascotas,lenMascota,id);
    unaRaza=DevuelveUnaRaza(listaRaza,lenRaza,id);

    MostrarUnaRazaYMascota(unaMascota,unaRaza);
}

int BuscarMascotaPorId(eMascotas lista[], int len,int id)
{
    int indice=-1;

    for(int i=0;i<len;i++)
    {
       if(lista[i].idMascota==id&&lista[i].isEmpty==OCUPADO)
        {
           indice=i;
            break;
        }
    }

    return indice;
}

int BuscarLibre(eMascotas lista[], int len,int estado)
{
    int indice=-1;

    for(int i=0; i<len;i++)
    {
        if(lista[i].isEmpty==estado)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void BuscarLibreRaza(eRaza lista[],int len)
{
    int i;

    for(int i=0;i<len;i++)
    {
       if(lista[i].isEmpty==OCUPADO)
       {
           printf("  %s -",lista[i].raza);
       }
    }
}

int BorrarMascotaPorId(eMascotas listaMascota[],eRaza listaRaza[], int lenMascota, int lenRaza)
{
    int error=-1;
    int indice;
    char confirmar;
    int id;

    if(listaMascota!=NULL&&lenMascota>0&&listaRaza!=NULL&&lenRaza>0)
    {
        MostrarListado(listaMascota,listaRaza,lenMascota,lenRaza);

        id=GetInt("\n Ingrese Id a borrar: ","ERROR Id no puede ser un numero negativo ");

        indice=BuscarMascotaPorId(listaMascota,lenMascota,id);

        if(indice==-1)
        {
            system("cls");
            printf("No hay ningun id con ese numero \n");

        }
        else
        {
            JuntarMascotayRaza(listaMascota,listaRaza, lenMascota,lenRaza,id);
            confirmar=ValidarRepuesta("\n Desea eliminar esta mascota?S-N ","ERROR Ingrese S para eliminar o N para volver \n",'s','n');
            system("cls");

            if(confirmar=='s')
            {
                listaMascota[indice].isEmpty=VACIO;

                error=0;
            }
            else
            {
                error=2;
            }
        }
    }

    return error;
}

void VerificarFuncionBorrar(eMascotas listaMascota[],eRaza listaRaza[],int lenMascota, int lenRaza)
{
    int error;

    error=BorrarMascotaPorId(listaMascota,listaRaza,lenMascota,lenRaza);

    switch(error)
    {
        case 0:
            printf("----- Se realizo la modificacion con exito----- \n");
        break;

        case -1:
            printf("----- Problemas con la modificacion ----- \n");
        break;

        default:
            printf("----- Modificacion cancelada por el usuario----- \n");
    }

    MostrarListado(listaMascota,listaRaza,lenMascota,lenRaza);
}

int OrdenarMascotasPorPais(eMascotas listaMascota[], eRaza listaRaza[], int lenMascota,int lenRaza)
{
    eMascotas auxMascota;
    eRaza auxRazaI;
    eRaza auxRazaJ;
    int error=-1;

    for(int i=0;i<lenRaza-1;i++)
    {
        for(int j=i+1; j<lenRaza;j++)
        {
            auxRazaI=DevuelveUnaRaza(listaRaza, lenMascota, listaMascota[i].idMascota);
            auxRazaJ= DevuelveUnaRaza(listaRaza, lenRaza, listaMascota[j].idMascota);

            if(strcmp(auxRazaI.paisOrigen, auxRazaJ.paisOrigen)>0)
            {
                auxMascota = listaMascota[i];
                listaMascota[i] = listaMascota[j];
                listaMascota[j] = auxMascota;
            }
        }
    }
    error=0;

    return error;
}

void VerificarFuncionOrdenar(eMascotas listaMascota[], eRaza listaRaza[], int lenMascota,int lenRaza)
{
    if(OrdenarMascotasPorPais(listaMascota,listaRaza,lenMascota,lenRaza)==0)
    {
        printf("Ordenamiento Realizado \n");
    }
    else
    {
        printf("Fallo en el ordenamiento \n");
    }
    MostrarListado(listaMascota,listaRaza,lenMascota,lenRaza);
}

void CargarMascotayRaza(eMascotas listaMascota[],eRaza listaRaza[],int lenMascota,int lenRaza)
{
    int i;
    int indice;
    eMascotas unaMascota;
    eRaza unaRaza;
    int idNext=105;
    char respuesta;

    do
    {
        if(listaMascota!=NULL&&listaRaza!=NULL&&lenMascota>0&&lenRaza>0)
        {

            indice=BuscarLibre(listaMascota,lenMascota,VACIO);

            if(indice==-1)
            {
                printf("\n No hay lugar\n");
            }
            else
            {
                BuscarLibreRaza(listaRaza,lenRaza);

                unaMascota=CargarUnaMascota(listaMascota,lenMascota,idNext++);
                unaRaza=CargarUnaRaza(listaRaza,lenRaza,unaMascota.idMascota);

                MostrarUnaRazaYMascota(unaMascota,unaRaza);
                system("cls");

                for(i=0;i<lenMascota;i++)
                {
                    listaMascota[indice]=unaMascota;
                    listaRaza[indice]=unaRaza;
                }
            }
            MostrarListado(listaMascota,listaRaza,lenMascota,lenRaza);

            respuesta=ValidarRepuesta("Desea ingresar mas Mascotas?S-N ","ERROR Ingrese S para seguir cargando o N para volver al menu\n ",'s','n');
            system("cls");
        }

    }while(respuesta!='n');
}

void ValidarIngresoRaza(eRaza lista[],int lenRaza,char raza[], int tam)
{
    int i;
    char dato[tam];

    GetString(dato,"Ingrese la raza: ","ERROR raza muy largo: ",tam);
    for(i=0;i<lenRaza;i++)
    {
        if(strcmp(lista[i].raza,dato)==0)
        {
            strcpy(raza,dato);
            break;
        }
    }

    while(strcmp(lista[i].raza,dato)!=0)
    {
        GetString(dato,"ERROR ReIngrese la raza: ","ERROR raza muy largo: ",tam);
        strcpy(raza,dato);

        for(i=0;i<lenRaza;i++)
        {
            if(strcmp(lista[i].raza,dato)==0)
            {
                strcpy(raza,dato);
                break;
            }
        }
    }
}

eMascotas CargarUnaMascota(eMascotas listaMascota[],int len,int id)
{
    eMascotas unaMascota;
    char nombreMascota[TAM];

    unaMascota.idMascota=id;
    unaMascota.isEmpty=OCUPADO;

    GetString(nombreMascota,"\n Ingrese el nombre: ","ERROR nombre muy largo: ",TAM);
    strcpy(unaMascota.nombreMascota,nombreMascota);

    unaMascota.sexo=ValidarRepuesta("Ingrese el sexo de la mascota F/M: ","ERROR reingrese F o M: \n ",'f','m');

    unaMascota.edad=GetInt("Ingrese la edad de su mascota: ","ERROR la edad no puede ser un numero negativo: ");

    return unaMascota;
}

eRaza CargarUnaRaza(eRaza listaRaza[], int len,int id)
{
    eRaza unaRaza;
    char paisOrigen[TAM];
    char tamanio[TAM];
    char raza[TAM];

    unaRaza.idMascota=id;

    GetString(paisOrigen,"Ingrese el pais: ","ERROR pais muy largo: ",TAM);
    strcpy(unaRaza.paisOrigen,paisOrigen);

    ValidarIngresoRaza(listaRaza,len,raza, TAM);
    strcpy(unaRaza.raza,raza);
    printf("%s",unaRaza.raza);

    GetString(tamanio,"Ingrese el tamanio: ","ERROR tamanio muy largo: ",TAM);
    strcpy(unaRaza.tamanio,tamanio);

    unaRaza.idTipo=ValidarRepuestaInt("Ingrese el tipo de su mascota 1-Gato 2-Perro 3-Otro: ","ERROR Reingrese el tipo de su mascota 1-Gato 2-Perro 3-Otro: ",1,3);

    return unaRaza;
}
