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
		system("pause");
		system("cls");
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
	
	int BuscarCuenta(string usuario, string contrasena)
	{
		//Recorrer lista de clientes y buscar coincidencia
		int i = 0;
		while (i != BaseDatos->Clientes->longitud())
		{
			if (BaseDatos->Clientes->obtenerPos(i)->nombreUsuario == usuario && BaseDatos->Clientes->obtenerPos(i)->contraseña == contrasena)
			{
				return i;
			}
			i++;
		}
		return -1;
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
			string usuario, contrasena;
			do
			{
				cout << "\nEscriba su usuario: ";
				cin >> usuario;
				cout << "\nEscriba su contrasena: ";
				cin >> contrasena;
				if (-1!=BuscarCuenta(usuario, contrasena))
				{
					char* nombre = new char[usuario.length()];
					strcpy(nombre, usuario.c_str());
					Sesion->IniciarSesion(nombre);
					break;
				}
				else
				{
					printf("Usuario o contrasena incorrectos, intente de nuevo.\n");
					printf("Presione X para salir del inicio de sesion. Cualquier otra para seguir intentando\n");
					char salir;
					cin >> salir;
					if (salir == 'X' || salir == 'x')
					{
						return;
					}
				}
			} while (true);
			printf("Iniciando sesion...\n");
			Sleep(1000);
			printf("Sesion iniciada!\n");
		}
		return;
	}

	void menuAdministrador()
	{
		cout << "1) Imprimir datos clientes\n";
		cout << "2) Imprimir datos pedidos\n";
		cout << "3) Imprimir datos funciones\n";
		cout << "4) Imprimir datos productos\n";
		cout << "0) Salir\n";
		char opcion;
		cin >> opcion;
		switch (opcion)
		{
		case '1':
			for (int i = 0; i < BaseDatos->Clientes->longitud(); i++)
			{
				cout << BaseDatos->Clientes->obtenerPos(i)->ToString() << endl;
			}
			break;
		case '2':
			//Imprimir datos pedidos
			break;
		case '3':
			for (int i = 0; i < BaseDatos->Funciones->longitud(); i++)
			{
				cout << BaseDatos->Funciones->obtenerPos(i)->ToString() << endl;
			}
			break;
		case '4':
			//Imprimir datos productos
			break;
		case '0':
			return;
		default:
			break;
		}
	}

	void menu()
	{
		printf("Bienvenido, %s\n", Sesion->NombreUsuario);
		printf("1) Mostrar cartelera\n");
		printf("2) Registrar pedido\n");
		printf("3) Buscar pedido\n");
		printf("4) Cuenta\n");
		printf("5) Salir\n");
		printf("6) Administrador\n");
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
			case 6:
				menuAdministrador();
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