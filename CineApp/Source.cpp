#pragma once
#include <iostream>
#include "SBaseDatos.hpp"
#include "SSesion.hpp"
#include "Archivo.hpp"

using namespace System;
using namespace std;

void MostrarCartelera()
{
	/*
	Mostrar Cartelera en una lista
	- [Nombre pelicula] - [Duracion] - [Clasificacion]
	...
	- [Nombre pelicula] - [Duracion] - [Clasificacion]
	Presione X para salir...
	*/
}

void menu(char* nombreUsuario)
{
	printf("Bienvenido, %s", nombreUsuario);
	printf("1) Mostrar cartelera\n");
	printf("2) Registrar pedido\n");
	printf("3) Cuenta\n");
	printf("4) Salir\n");
	printf("Escriba una opcion: ");
}

int main()
{
	//Iniciar singleton de base de datos
	SBaseDatos* BaseDatos;
	BaseDatos = BaseDatos->getInstance();
	SSesion* Sesion;
	Sesion = Sesion->getInstance();
	int opcion = 0;
	do
	{
		menu(Sesion->NombreUsuario);
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			MostrarCartelera();
			break;
		case 2:
			//RegistrarPedido();
			break;
		case 3:
			//ControlCuenta();
			break;
		case 4:
			//Salir
			break;
		default:
			printf("\nEscoja otra opción...");
			break;
		}
	} while (opcion != 4);
	printf("Gracias por tu visita, %s, vuelve pronto!", Sesion->NombreUsuario);

}