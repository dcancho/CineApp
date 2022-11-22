#pragma once
#include "Producto.hpp"
#include "Lista.hpp"
#include <ostream>

namespace CineApp {
	//Entidad 4
	class Pedido : public Entidad
	{
	public:
		Lista<Producto*>* Productos;
		string DNICliente;
		int IDFuncion;
		Pedido() : Entidad()
		{
			Productos = new Lista<Producto*>();
			DNICliente = -1;
		}
		Pedido(string s) : Entidad()
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
			this->ID = stoi(tokens[0]);
			this->DNICliente = tokens[1];
			this->IDFuncion = stoi(tokens[2]);
		}
		~Pedido() {}
		char* ToString()
		{
			//Salida:
			//Pedido NroÅã: #ID#

			return nullptr;
		}
		void Imprimir(ostream out)
		{
			out << "Pedido Nro: " << this->ID;
			for (int i = 0; i < Productos->longitud(); i++)
			{
				out << Productos->obtenerPos(i)->ToText();
			}
		}

		void ImprimirComprobante()
		{
			ofstream out("Comprobante.txt");
			out << "Pedido Nro: " << this->ID << endl;
			for (int i = 0; i < Productos->longitud(); i++)
			{
				out << Productos->obtenerPos(i)->ToText();
			}
			out.close();
		}
	};
}
