#pragma once
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
		FromString(s);
	}
	char* ToString()
	{
		stringstream ss;
		ss << Nombre << Valor;
		//convert ss to char*
		char* output = new char[ss.str().length() + 1];
		strcpy(output, ss.str().c_str());
		return output;
	}
private:
	void FromString(string s)
	{
		//Valores divididos por comas, en orden: Nombre, Valor
		vector<string>tokens;
		stringstream ss;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ',')
			{
				tokens.push_back(ss.str());
				ss.str("");
			}
			else
			{
				ss << s[i];
			}
		}
		tokens.push_back(ss.str());
		this->Nombre = tokens[0];
		this->Valor = stof(tokens[1]);
	}
public:
	void Imprimir(ostream out)
	{
		out << "- " << Nombre << "\t\t\t S/." << Valor << endl;
	}
	char* ToText()
	{
		stringstream ss;
		ss << "- " << Nombre << "\t\t\t S/." << Valor << endl;
		char* output = new char[ss.str().length() + 1];
		strcpy(output, ss.str().c_str());
		return output;
	}
	void setID(int id)
	{
		this->ID = id;
	}
};