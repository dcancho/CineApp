#pragma once
#include "Entidad.hpp"

class Funcion : public Entidad
{
private:
	string nombrePelicula;
	int capacidadMaxima;
	int capacidadActual;
	string horaInicio;
	string horaFin;
	float costoAsiento;
public:
	Funcion() :Entidad()
	{
		nombrePelicula = "";
		capacidadMaxima = 0;
		capacidadActual = 0;
		horaInicio = "";
		horaFin = "";
		costoAsiento = 0.0f;
	}
	Funcion(string nombre, int max, int actual, string inicio, string fin, float precio) : Entidad()
	{
		this->capacidadActual = actual;
		this->capacidadMaxima = max;
		this->costoAsiento = precio;
		this->horaFin = fin;
		this->horaInicio = inicio;
		this->nombrePelicula = nombre;
	}
	~Funcion()
	{
	}
	Funcion(string s)
	{
		FromString(s);
	}
	void FromString(string s)
	{
		vector<string> tokens;
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
		this->nombrePelicula = tokens[0];
		this->capacidadMaxima = stoi(tokens[1]);
		this->capacidadActual = stoi(tokens[2]);
		this->horaInicio = tokens[3];
		this->horaFin = tokens[4];
		this->costoAsiento = stof(tokens[5]);
		this->ID = stoi(tokens[6]);
	}
	char* ToString()
	{
		stringstream ss;
		ss << nombrePelicula << "," << capacidadMaxima << "," << capacidadActual << "," << horaInicio << "," << horaFin << "," << costoAsiento << "," << ID;
		char* output = new char[ss.str().length() + 1];
		strcpy(output, ss.str().c_str());
		return output;
	}
	void Imprimir(ostream& out)
	{
		out << "- " << nombrePelicula << "\t\t\t" << horaInicio << "\t\t\t" << horaFin << "\t\t\t" << capacidadActual << "/" << capacidadMaxima << "\t\t\tS/." << costoAsiento << endl;
	}
};