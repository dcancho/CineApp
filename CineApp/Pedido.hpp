#include "Producto.hpp"
#include "Lista.hpp"
#include "Funcion.hpp"

class Pedido : public Entidad
{
public:
	Lista<Producto*>* Productos;
	int IDCliente;
	Funcion* funcion;
	Pedido() : Entidad()
	{
		Productos = new Lista<Producto*>();
		IDCliente = -1;
	}
	~Pedido() {}
	char* ToString()
	{
		//Salida:
		//Pedido NroÅã: #ID#

		return nullptr;
	}
	void Imprimir(ostream out)
	{
		// Imprimir() por cada Producto en Productos
	}
};