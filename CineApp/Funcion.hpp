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
		//Valores divididos por comas, orden: Nombre, Capacidad máxima, Capacidad actual, Hora inicio, Hora fin, Costo asiento, ID
		/*
		TO-DO
		*/
		this->nombrePelicula = tokens[0];
		this->capacidadMaxima = stoi(tokens[1]);
		this->capacidadActual = stoi(tokens[2]);
		this->horaInicio = tokens[3];
		this->horaFin = tokens[4];
		this->costoAsiento = stof(tokens[5]);
		this->ID = stoi(tokens[6]);
		
	}
};