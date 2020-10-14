#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED
#define TAM 30
#define LEN 5
#define VACIO 0
#define OCUPADO 1

typedef struct
{
    int idTipo;
    int idMascota;
    char paisOrigen[TAM];
    char tamanio[TAM];
    char raza[TAM];
    int isEmpty;
}eRaza;

typedef struct
{
    int idMascota;
    char nombreMascota[15];
    char sexo;
    int edad;
    int isEmpty;
}eMascotas;

int IniciarMascota(eMascotas list[], int len);
void VerificacionInicioMascota(eMascotas list[],int len);
int IniciarRaza(eRaza list[], int len);
void VerificacionInicioRaza(eRaza list[],int len);

void HarcodearMascotas(eMascotas lista[]);

void HardcodearRaza(eRaza lista[]);

eRaza DevuelveUnaRaza(eRaza lista[], int len, int id);

eMascotas DevuelveUnaMascota(eMascotas lista[], int len,int id);

void MostrarUnaRazaYMascota(eMascotas unaMascota, eRaza unaRaza);

void JuntarMascotayRaza(eMascotas listaMascotas[],eRaza listaRaza[], int lenMascota, int lenRaza,int id);

int BuscarMascotaPorId(eMascotas lista[], int len,int id);

void MostrarListado(eMascotas listaMascotas[],eRaza listaRaza[], int lenMascota, int lenRaza);

void VerificarFuncionBorrar(eMascotas listaMascota[],eRaza listaRaza[], int lenMascota,int lenRaza);

int BorrarMascotaPorId(eMascotas listaMascota[],eRaza listaRaza[], int lenMascota,int lenRaza);

int OrdenarMascotasPorPais(eMascotas listaMascota[], eRaza listaRaza[], int lenMascota,int lenRaza);

void VerificarFuncionOrdenar(eMascotas listaMascota[], eRaza listaRazas[], int lenMascota,int lenRaza);

int BuscarLibre(eMascotas lista[], int len,int estado);

void CargarMascotayRaza(eMascotas listaMascota[],eRaza listaRaza[],int lenMascota,int lenRaza);

eMascotas CargarUnaMascota(eMascotas listaMascota[],int len,int id);

eRaza CargarUnaRaza(eRaza listaRaza[], int len,int id);

void ValidarIngresoRaza(eRaza lista[],int lenRaza,char raza[], int tam);
void BuscarLibreRaza(eRaza lista[],int len);


#endif // MASCOTA_H_INCLUDED
