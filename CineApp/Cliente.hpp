#pragma once
#include "Entidad.hpp"

class Cliente : public Entidad
{
private:
	string nombre;
	string DNI;
	string nombreUsuario;
	string contraseña;
public:
	Cliente() : Entidad()
	{
		nombre = "";
		DNI = "";
		nombreUsuario = "";
		contraseña = "";		//Hashed
	}
	Cliente(string nombre, string DNI, string nombreUsuario, string contraseña) : Entidad()
	{
		this->nombre = nombre;
		this->DNI = DNI;
		this->nombreUsuario = nombreUsuario;
		this->contraseña = contraseña;
	}
	//Constructor a partir de un string de archivo
	Cliente(string s)
	{
		FromString(s);
	}
	~Cliente() {}
	string ToString()
	{
		return "@" +nombreUsuario + " (" + nombre + ": " + DNI + ") ";
	}
private:
	void FromString(string s)
	{
		//Values divided by commas, in order: nombre, DNI, nombreUsuario, contraseña
		int pos = 0;
		string token;
	}
public:
	void Imprimir(ostream out)
	{
		out << "Cliente: " + nombre + "\t\tDNI: " + DNI << endl;
	}
	void setID(int id)
	{
		this->ID = id;
	}
};