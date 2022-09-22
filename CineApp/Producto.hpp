#include "Entidad.hpp"

class Producto : public Entidad
{
private:
	string Nombre;
	float Valor;
public:
	Producto()
	{
		Nombre="";
		Valor=0.0f;
	}
	Producto(string nombre, float precio)
	{
		Nombre = nombre;
		Valor = precio;
	}
	Producto(string s)
	{
		
	}
	string ToString()
	{
		return Nombre + ": " + std::to_string(Valor);
	}
private:
	void FromString()
	{
		//Values divided by commas, in order : Nombre, Valor
		
	}
public:
	void Imprimir(ostream out)
	{
		out << Nombre << ": " << Valor << endl;
	}
	void setID(int id)
	{
		this->ID = id;
	}
};