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
		int IDCliente;
		int IDFuncion;
		Pedido() : Entidad()
		{
			Productos = new Lista<Producto*>();
			IDCliente = -1;
		}
		Pedido(string s) : Entidad()
		{
			Productos = new Lista<Producto*>();
			FromString(s);
		}
		~Pedido() {}
		char* ToString()
		{
			//Salida:
			//Pedido Nro??: #ID#

			return nullptr;
		}
		/*void FromString(string s)
		{
			//Formato:
			//IDCliente, IDFuncion, IDProducto1, IDProducto2, ...
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
			this->IDCliente = stoi(tokens[0]);
			this->IDFuncion = stoi(tokens[1]);
			for (int i = 2; i < tokens.size(); i++)
			{
				Productos->agregaFinal(new Producto(stoi(tokens[i])));
			}
		}
*/		void Imprimir(ostream out)
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
