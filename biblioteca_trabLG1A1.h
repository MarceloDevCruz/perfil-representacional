/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

//Defini��o de estruturas
//Struct para fazer login no programa
typedef struct
	{
		char nome[140];        //ser� completado com o nome do usu�rio
		char prontuario[30];   //ser� completado com o prontu�rio do usu�rio
	} log;

//Struct para guardar a frase perguntas e valores dos resultados do teste	
typedef struct
	{
		int NroFrase;
		char frase[99+1];
		int C;
		char item_1[99+1];
		int A;
		char item_2[99+1];
		int V;
		char item_3[99+1];
		int D;
		char item_4[99+1];
	} cadastro;

