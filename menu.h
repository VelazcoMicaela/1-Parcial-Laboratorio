#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

int IngresarDatoEntero();

char IngresarDatoChar();

int Menu();

void MostrarMenu();

char ValidarRepuesta(char msg[],char errorMsg[],char s, char n);
int GetInt(char msg[],char msgError[]);
void GetString(char dato[], char msg[],char msgError[], int len);
int ValidarRepuestaInt(char msg[],char errorMsg[],int numUno, int numDos);


#endif // MENU_H_INCLUDED
