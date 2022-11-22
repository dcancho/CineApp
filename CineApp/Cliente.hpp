#pragma once
#include "Entidad.hpp"


namespace CineApp {
	//Entidad 1
	class Cliente : public Entidad
	{
	public:
		string nombre;
		string DNI;
		string nombreUsuario;
		string contraseña;
		

		Cliente() : Entidad()
		{
			nombre = "";
			DNI = "";
			nombreUsuario = "";
			contraseña = "";		
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
		char* ToString()
		{
			stringstream ss;
			ss << nombre << "," << DNI << "," << nombreUsuario << "," << contraseña << ",";
			char* output = new char[ss.str().length() + 1];
			strcpy(output, ss.str().c_str());
			return output;
		}
	private:
		void FromString(string s)
		{
			//Values divided by commas, in order: nombre, DNI, nombreUsuario, contraseña
			vector<string> tokens;
			stringstream ss;
			for (int i = 0; i < s.length(); i++)
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
			this->nombre = tokens[0];
			this->DNI = tokens[1];
			this->nombreUsuario = tokens[2];
			this->contraseña = tokens[3];
			//this->ID = stoi(tokens[4]);
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
}
