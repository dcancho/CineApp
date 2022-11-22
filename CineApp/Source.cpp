#include <iostream>
#include <Windows.h>
#include "SBaseDatos.hpp"
#include "SSesion.hpp"
#include "Archivo.hpp"
#include "Funcion.hpp"
#include "Pedido.hpp"
#include "ArbolAVL.hpp"
#include "Ordenamientos.hpp"

using namespace System;
using namespace std;

namespace CineApp
{
	static SSesion* Sesion = SSesion::getInstance();
	static SBaseDatos* BaseDatos = SBaseDatos::getInstance();
	
	//Mostrar cartelera, recorre lista Cartelera e imprime los titulos
	void MostrarCartelera()
	{
		int i = 0;
		while (i != BaseDatos->Cartelera->longitud())
		{
			cout << BaseDatos->Cartelera->obtenerPos(i) << endl;
			i++;
		}
		printf("Presione cualquier tecla para volver al menu...\n");
		system("pause");
		system("cls");
	}
	//Registrar un nuevo pedido y se envia a la sesion
	void RegistrarPedido()
	{
		//Crear pedido
		Pedido* nuevoPedido = new Pedido();

		//Asignar ID de cliente al pedido
		nuevoPedido->IDCliente = Sesion->IDUsuario;

		//Imprimir funciones y escoger una, asignar a Pedido
		for (int i = 0; i < BaseDatos->Funciones->longitud(); i++)
		{
			BaseDatos->Funciones->obtenerPos(i)->Imprimir(cout);
		}
		int IDFuncion;
		cout << "Ingrese el ID de la funcion que desea comprar: ";
		cin >> IDFuncion;
		nuevoPedido->IDFuncion = IDFuncion;
		//Seleccionar cantidad de entradas(Asientos)
		printf("Cuantas entradas desea comprar? ");
		int cantidad;
		cin >> cantidad;
		do
		{
			nuevoPedido->Productos->agregaFinal(new Producto("Asiento x1", 25.0f));
			cantidad--;
		} while (cantidad);
		//Seleccionar productos de la dulcería
		for (int i = 0; i < BaseDatos->Productos->longitud(); i++)
		{
			cout << i + 1 << ") ";
			BaseDatos->Productos->obtenerPos(i)->Imprimir();
		}
		printf("Que productos desea comprar? ");
		printf("Presione 0 para terminar de comprar productos\n");
		int opcion;
		do
		{
			cin >> opcion;
			if (opcion > 0 && opcion < BaseDatos->Productos->longitud())
			{
				nuevoPedido->Productos->agregaFinal(BaseDatos->Productos->obtenerPos(opcion - 1));
			}

		} while (opcion != 0);
		//Agregar pedido a la lista de pedidos
		printf("Compra terminada. Presione cualquier tecla para volver al menu...\n");
		Sesion->Pedidos->insertar(nuevoPedido);
		nuevoPedido->ImprimirComprobante();
		system("pause");
		system("cls");

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
				if (-1 != BuscarCuenta(usuario, contrasena))
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
		system("cls");
		return;
	}

	void CrearArbolAVLFuncion()
	{
		auto mostrarFuncion = [](Funcion* funcion) {cout << funcion->nombrePelicula << endl; };
		auto compararFuncion = [](Funcion* funcion1, Funcion* funcion2) {return funcion1->costoAsiento < funcion2->costoAsiento; };
		auto igualFuncion = [](Funcion* funcion1, Funcion* funcion2) {return funcion1->costoAsiento == funcion2->costoAsiento; };
		ArbolAVL<Funcion*>* arbol = new ArbolAVL<Funcion*>(mostrarFuncion, compararFuncion, igualFuncion);
		for (int i = 0; i < BaseDatos->Funciones->longitud(); i++)
		{
			arbol->insertar(BaseDatos->Funciones->obtenerPos(i));
		}
		arbol->IterarPreOrden();
		
	}

	void menuAdministrador()
	{
		cout << "1) Imprimir datos clientes\n";
		cout << "3) Imprimir datos funciones\n";
		cout << "4) Imprimir datos productos\n";
		cout << "5) Crear arbol AVL de funciones por precio\n";
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
		case '3':
			for (int i = 0; i < BaseDatos->Funciones->longitud(); i++)
			{
				cout << BaseDatos->Funciones->obtenerPos(i)->ToString() << endl;
			}
			break;
		case '4':
			for (int i = 0; i < BaseDatos->Productos->longitud(); i++)
			{
				cout << BaseDatos->Productos->obtenerPos(i)->ToString() << endl;
			}
			break;
		case '5':
			CrearArbolAVLFuncion();
			break;
		case '0':
			
			return;
		default:
			break;
		}
		system("pause");
		system("cls");
	}

	void menu()
	{
		printf("****************************************************************************************\n");
		printf("..######..####.##....##.########.########..##..........###....##....##.########.########\n");
		printf(".##....##..##..###...##.##.......##.....##.##.........##.##...###...##.##..........##...\n");
		printf(".##........##..####..##.##.......##.....##.##........##...##..####..##.##..........##...\n");
		printf(".##........##..##.##.##.######...########..##.......##.....##.##.##.##.######......##...\n");
		printf(".##........##..##..####.##.......##........##.......#########.##..####.##..........##...\n");
		printf(".##....##..##..##...###.##.......##........##.......##.....##.##...###.##..........##...\n");
		printf("..######..####.##....##.########.##........########.##.....##.##....##.########....##...\n");
		printf("****************************************************************************************\n");
		printf("Bienvenid@, %s\n", Sesion->NombreUsuario);
		printf("1) Mostrar cartelera\n");
		printf("2) Registrar pedido\n");
		printf("3) Cuenta\n");
		printf("4) Salir\n");
//		printf("5) Administrador\n");
		printf("****************************************************************************************\n");
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
				Sesion->isLogged ? RegistrarPedido() : printf("Por favor, inicie sesion para registrar un pedido...\n");
				break;
			case 3:
				Cuenta();
				break;
			case 5:
				menuAdministrador();
				break;
			case 4:
				printf("Saliendo...\n");
				Sleep(1000);
				break;
			default:
				printf("\nEscoja otra opción...\n");
				break;
			}
		} while (opcion != 4);
		printf("Gracias por tu visita, %s, vuelve pronto!", Sesion->NombreUsuario);
		system("pause");
		return 0;
	}
}
