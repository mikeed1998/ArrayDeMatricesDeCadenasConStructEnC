////////////////////////////////////////
/*
	FileName: main.c
	FileType: C source file
	Author: Sandoval Pérez, Michael Eduardo
	Created on: 01/06/2021
	Description: Creación de un arreglo que almacena matrices de cadenas de caracteres
*/
////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MatrizCadena
{
	int x;
	int y;
	char ***matriz;
};

typedef struct
{
	struct MatrizCadena matrizCadena;
}ListaMatrices;

typedef struct
{
	ListaMatrices *listaMatrices;
}ArrayMatricesCadenas;

ListaMatrices *insertarDatos(int, int);
void mostrarDatos(ListaMatrices*);

int main(int argc, char *argv[])
{
	int posX, posY, tam, i = 0;

	ListaMatrices *(*ptrInsertarDatos)(int, int) = &insertarDatos;

	printf("Tamano del array: ");
	scanf("%d", &tam);

	ArrayMatricesCadenas array[tam];

	while(i < tam)
	{
		printf("Ingresa la cantidad de filas: ");
		scanf("%d", &posX);
		printf("Ingresa la cantidad de columnas: ");
		scanf("%d", &posY);
		
		array[i].listaMatrices = ptrInsertarDatos(posX, posY);

		i++;
	}
	
	i = 0;
	while(i < tam)
	{
		mostrarDatos(array[i].listaMatrices);
		i++;
	}

	return 0;
}

ListaMatrices *insertarDatos(int _x, int _y)
{
	ListaMatrices *lista = (ListaMatrices*)malloc(sizeof(ListaMatrices));
	
	lista->matrizCadena.x = _x;
	lista->matrizCadena.y = _y;
	
	lista->matrizCadena.matriz = calloc(lista->matrizCadena.x, sizeof(char**));
	for(int i = 0; i < lista->matrizCadena.x; i++)
	{
		*(lista->matrizCadena.matriz + i) = calloc(lista->matrizCadena.y, sizeof(char*));
		for(int j = 0; j < lista->matrizCadena.y; j++)
		{
			*(*(lista->matrizCadena.matriz + i) + j) = malloc(sizeof(char) * (lista->matrizCadena.x * lista->matrizCadena.y) );
			printf("Dato [%d][%d]: ", i, j);
			getchar();
			scanf("%10[0-9a-zA-Z ]", *(*(lista->matrizCadena.matriz + i) + j));
		}
	}

	return lista;
}

void mostrarDatos(ListaMatrices* lista)
{
	for(int i = 0; i < lista->matrizCadena.x; i++)
	{
		printf("|");
		for(int j = 0; j < lista->matrizCadena.y; j++)
		{
			printf(" %s |", *(*(lista->matrizCadena.matriz + i) + j));
		}	
		printf("\n");
		free(*(lista->matrizCadena.matriz + i));
	}
	printf("\n\n");
	
	free(lista->matrizCadena.matriz);
	free(lista);
}
