#pragma once
#include <iostream>
#include <Windows.h>
#include "SBaseDatos.hpp"
#include "SSesion.hpp"
#include "Archivo.hpp"
#include "Funcion.hpp"
#include "Pedido.hpp"

using namespace System;
using namespace std;

namespace CineApp
{
	static SSesion* Sesion = SSesion::getInstance();
	static SBaseDatos* BaseDatos = SBaseDatos::getInstance();
	
	void MostrarCartelera()
	{
		//Mostrar cartelera, recorre lista Cartelera e imprime los titulos
		int i = 0;
		while (i!=BaseDatos->Cartelera->longitud())
		{
			cout<<BaseDatos->Cartelera->obtenerPos(i)<<endl;
			i++;
		}
		printf("Presione cualquier tecla para volver al menu...\n");
	}

	void RegistrarPedido()
	{
		//Crear pedido
		Pedido* nuevoPedido = new Pedido();

		//Asignar ID de cliente al pedido


		//Imprimir funciones y escoger una, asignar a Pedido
		
		//Seleccionar cantidad de entradas(Asientos)
		
		//Seleccionar productos de la dulcería


		//Agregar pedido a la lista de pedidos
		Sesion->Pedidos->agregaFinal(nuevoPedido);

	}

	void BuscarPedido()
	{
		//Imprimir cada elemento de Sesion->Pedidos
	}
	void Cuenta()
	{
		if (Sesion->isLogged)
		{
			printf("Cerrando sesion...\n");
			Sesion->CerrarSesion();
			Sleep(1000);
			printf("Sesion cerrada!\n");
		}
		else
		{
			printf("Iniciando sesion...\n");
			//Pedir usuario y contrasena, comparar con lista de clientes en BaseDatos
			Sleep(1000);
			printf("Sesion iniciada!\n");
		}
		return;
	}

	void menu()
	{
		printf("Bienvenido, %s\n", Sesion->NombreUsuario);
		printf("1) Mostrar cartelera\n");
		printf("2) Registrar pedido\n");
		printf("3) Buscar pedido\n");
		printf("4) Cuenta\n");
		printf("5) Salir\n");
		printf("Escriba una opcion: ");
	}

	int main()
	{
		
		int opcion = 0;
		do
		{
			menu();
			cin >> opcion;
			switch (opcion)
			{
			case 1:
				MostrarCartelera();
				break;
			case 2:
				Sesion->isLogged ? RegistrarPedido() : printf("Por favor, inicie sesion para registrar un pedido...");
				break;
			case 3:
				Sesion->isLogged ? BuscarPedido() : printf("Por favor, inicie sesion para buscar un pedido...");
				break;
			case 4:
				Cuenta();
				break;
			case 5:
				printf("Saliendo...\n");
				Sleep(1000);
				break;
			default:
				printf("\nEscoja otra opción...");
				break;
			}
		} while (opcion != 5);
		printf("Gracias por tu visita, %s, vuelve pronto!", Sesion->NombreUsuario);
		system("pause");
		return 0;
	}
}