#pragma once
#include "Archivo.hpp"
#include "Lista.hpp"
#include "Cliente.hpp"
#include "Pedido.hpp"
#include "Funcion.hpp"
#include "Producto.hpp"
#include "Pila.hpp"


namespace CineApp {
	//Entidad 6
	class SBaseDatos {

		
	public:
		static SBaseDatos* getInstance()
		{
			if (nullptr == BaseDatos)
			{
				BaseDatos = new SBaseDatos();
			}
			return BaseDatos;
		}
		~SBaseDatos() {}
		Lista<Cliente*>* Clientes;
		Lista<Pedido*>* Pedidos;
		//Lista<Funcion*>* Funciones;
		Lista<string>* Cartelera;
		Lista<Producto*>* Productos;
	private:
		static SBaseDatos* BaseDatos;
		SBaseDatos()
		{
			Clientes = new Lista<Cliente*>();
			Pedidos = new Lista<Pedido*>();
			Productos = new Lista<Producto*>();
			//Funciones = new Lista<Funcion*>();
			Cartelera = new Lista<string>();
			LeerCartelera();
			LeerClientes();
			//LeerFunciones();
			LeerProductos();
		}
		SBaseDatos(const SBaseDatos& obj) {}
		void LeerClientes()
		{
			ifstream* archivo = new ifstream("clientes.txt");
			string linea;
			while (getline(*archivo, linea))
			{
				Clientes->agregaFinal(new Cliente(linea));
			}
		}
		void LeerPedidos()
		{
			ifstream* archivo = new ifstream("pedidos.txt");
			string linea;
			while (getline(*archivo, linea))
			{
				Pedidos->agregaFinal(new Pedido(linea));
			}
		}
		/*void LeerFunciones()
		{
			ifstream* archivo = new ifstream("funciones.txt");
			string linea;
			while (getline(*archivo, linea))
			{
				Funciones->agregaFinal(new Funcion(linea));
			}
		}*/
		void LeerCartelera()
		{
			ifstream* archivo = new ifstream("cartelera.txt");
			string linea;
			while (getline(*archivo, linea))
			{
				Cartelera->agregaFinal(linea);
			}
		}
		void LeerProductos()
		{
			ifstream* archivo = new ifstream("productos.txt");
			string linea;
			while (getline(*archivo, linea))
			{
				Productos->agregaFinal(new Producto(linea));
			}
		}
	};

	SBaseDatos* SBaseDatos::BaseDatos = 0;
	
}
