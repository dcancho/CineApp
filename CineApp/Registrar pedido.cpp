#include "Pedido.hpp"
#include "SSesion.hpp"
#include "SBaseDatos.hpp"

using namespace System;
using namespace std;

void RegistrarPedido()
{
	Funcion* funcion = nullptr;
	//Iniciar singleton de base de datos
	SBaseDatos* BaseDatos;
	BaseDatos = BaseDatos->getInstance();

	//Iniciar singleton de sesion
	SSesion* Sesion;
	Sesion = Sesion->getInstance();

	//Crear pedido
	Pedido* nuevoPedido = new Pedido();

	//Asignar ID de cliente
	nuevoPedido->IDCliente = Sesion->IDUsuario;

	//Seleccionar sede
	//Seleccionar película
	//Seleccionar función (Horario)
	//Seleccionar cantidad de entradas(Asientos)
	//Seleccionar productos de la dulcería
	

	//Agregar pedido a la lista de pedidos
	//Sesion->Pedidos->Agregar(nuevoPedido);
}