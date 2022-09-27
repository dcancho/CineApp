#pragma once
#include <iostream>
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

		//Asignar ID de cliente


		//Seleccionar sede
		//Seleccionar película
		//Seleccionar función (Horario)
		//Seleccionar cantidad de entradas(Asientos)
		//Seleccionar productos de la dulcería


		//Agregar pedido a la lista de pedidos
		//Sesion->Pedidos->Agregar(nuevoPedido);

	}

	void menu()
	{
		printf("Bienvenido, %s\n", Sesion->NombreUsuario);
		printf("1) Mostrar cartelera\n");
		printf("2) Registrar pedido\n");
		printf("3) Cuenta\n");
		printf("4) Salir\n");
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
		system("pause");
		return 0;
	}
}