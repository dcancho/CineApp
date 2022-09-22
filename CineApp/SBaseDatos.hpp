#include "Archivo.hpp"
#include "Cliente.hpp"
#include "Lista.hpp"
#include "Pedido.hpp"

class SBaseDatos
{
private:
	SBaseDatos* BaseDatos;
	Lista<Cliente*>* Clientes;
	Lista<Pedido*>* Pedidos;
	SBaseDatos()
	{

	}
public:
	SBaseDatos* getInstance()
	{
		if (BaseDatos == nullptr)
		{
			BaseDatos = new SBaseDatos();
		}
		return BaseDatos;
	}
};