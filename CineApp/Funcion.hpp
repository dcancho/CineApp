#pragma once
#include "Entidad.hpp"


namespace CineApp {
	//Entidad 3
	class Funcion : public Entidad
	{
	private:
		string nombrePelicula;
		string horaInicio;
		int duracion;
		float costoAsiento;
		
	public:
		Funcion() : Entidad()
		{
			nombrePelicula = "";
			horaInicio = "";
			duracion = 0;
			costoAsiento = 0;
		}
		Funcion(string s) : Entidad()
		{
			FromString(s);
		}
		~Funcion()
		{
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
			this->ID = stoi(tokens[0]);
			this->nombrePelicula = tokens[1];
			this->horaInicio = tokens[2];
			this->duracion = stoi(tokens[3]);
			this->costoAsiento = stof(tokens[4]);
		}
		char* ToString()
		{
			stringstream ss;
			ss << this->ID << "," << this->nombrePelicula << "," << this->horaInicio << "," << this->duracion << "," << this->costoAsiento;
			char* output = new char[ss.str().length() + 1];
			strcpy(output, ss.str().c_str());
			return output;
		}
		void Imprimir(ostream& out)
		{
			out << "Funcion Nro: " << this->ID << endl;
			out << "Nombre de la pelicula: " << this->nombrePelicula << endl;
			out << "Hora de inicio: " << this->horaInicio << endl;
			out << "Duracion: " << this->duracion << endl;
		}
	};
}
