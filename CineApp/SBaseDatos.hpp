#include "Archivo.hpp"
#include "Lista.hpp"
#include "Entidad.hpp"


class SBaseDatos {
public:
	static SBaseDatos* GetInstance() {
		if (NULL == BaseDatos)
		{
			BaseDatos = new SBaseDatos();
		}
		return BaseDatos;
	}
	~SBaseDatos() {}
	Lista<Entidad*>* Clientes;
	Lista<Entidad*>* Pedidos;
	Lista<Entidad*>* Funciones;
private:
	SBaseDatos()
	{
		Clientes = new Lista<Entidad*>();
		Pedidos = new Lista<Entidad*>();
		Funciones = new Lista<Entidad*>();
	}
	SBaseDatos(const SBaseDatos& obj) {}
	static SBaseDatos* BaseDatos;

};

SBaseDatos* SBaseDatos::BaseDatos = 0;