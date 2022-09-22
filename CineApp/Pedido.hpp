#include "Producto.hpp"
#include "Lista.hpp"
#include "SBaseDatos.hpp"

class Pedido : public Entidad
{
private:
	Lista<Producto*>* Productos;
	int IDCliente;
public:
	Pedido() : Entidad()
	{
		Productos = new Lista<Producto*>();
		IDCliente = -1;
	}
	~Pedido() {}
	string ToString()
	{
		return "Pedido Nro.: " + IDCliente+"\n";
	}
	void Imprimir(ostream out)
	{
		for (int i = 0; i < Productos.cantidad; i++;)
		{
			Productos->AccedeElemento(i)->ImprimirFactura(ostream out);
		}
	}
};