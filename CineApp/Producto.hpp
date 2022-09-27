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
	char* ToString()
	{
		//Formato:
		//#Nombre#: S/ #Valor#
		return nullptr;
	}
private:
	void FromString()
	{
		vector<string> tokens;
		//Valores divididos por comas, orden: Nombre, Valor
		/*
		TO-DO
		*/
		this->Nombre = tokens[0];
		this->Valor = stof(tokens[1]);
		
	}
public:
	void Imprimir(ostream out)
	{
		out << Nombre << ": " << Valor << endl;
	}
	void ImprimirFactura(ostream out)
	{
		out << "- " << Nombre << "\t\t\t S/." << Valor << endl;
	}
	void setID(int id)
	{
		this->ID = id;
	}
};