#pragma once
#include "Archivo.hpp"
#include "Cliente.hpp"
#include "Pedido.hpp"
#include "SBaseDatos.hpp"
#include "Funcion.hpp"

namespace CineApp
{
	class DataGen
	{
	/*public:
		static vector<Funcion*> GenerarFunciones(int cantidad)
		{
			vector<Funcion*> funciones;
			CsvLector* archivo = new CsvLector("moviename.csv");
			vector<string> nombres = archivo->returnArchivo()[0];
			for (int i = 0; i < cantidad; i++)
			{
				string init;
				init.append(to_string(i));
				init.append(",");
				init.append(nombres[rand() % nombres.size()]);
				init.append(",");
				init.append(GenerarHoraInicio());
				init.append(",");
				init.append(GenerarDuracion());
				init.append(",");
				init.append(to_string(rand() % 30));
				Funcion* funcion = new Funcion(init);
				funciones.push_back(funcion);
			}
			return funciones;
		}
	*/
	public:
		static void GenerarCartelera(int cantidad)
		{
			CsvLector* archivo = new CsvLector("moviename.csv");
			vector<string> nombres = archivo->returnArchivo()[0];
			Lista<string>* cartelera = new Lista<string>();
			for (int i = 0; i < cantidad; i++)
			{
				cartelera->agregaFinal(nombres[rand() % nombres.size()]);
			}
			//write cartelera to a txt file
			TxtEscritor* carteleraFile = new TxtEscritor("cartelera.txt");
			for (int i = 0; i < cartelera->longitud(); i++)
			{
				carteleraFile->EscribirLinea(cartelera->obtenerPos(i));
			}
		}
	private:

		static string GenerarHoraInicio()
		{
			string fecha;
			fecha.append(to_string(rand() % 24));
			fecha.append(":");
			fecha.append(to_string(rand() % 60));
			return fecha;
		}
		static string GenerarDuracion()
		{
			string tiempoDuracion;
			tiempoDuracion.append(to_string(rand() % 3 + 1));
			tiempoDuracion.append(":");
			tiempoDuracion.append(to_string(rand() % 60));
			return tiempoDuracion;
		}
	public:
		static vector<Cliente*> GenerarClientes(int cantidad)
		{
			CsvLector* archivo = new CsvLector("namedata.csv");
			vector<string> nombres = archivo->returnArchivo()[0];
			vector<string> apellidos = archivo->returnArchivo()[1];
			vector<Cliente*> clientes;
			for (int i = 0; i < cantidad; i++)
			{
				string init;
				string nombre = nombres[rand() % nombres.size()];
				string apellido = apellidos[rand() % apellidos.size()];
				init.append(nombre + " " + apellido);
				init.append(",");
				init.append(to_string(rand() % 100000000));
				init.append(",");
				init.append(to_string(nombre[0] + apellido[0]));
				init.append(",");
				init.append(to_string(12345678));
				Cliente* cliente = new Cliente(init);
				clientes.push_back(cliente);
			}
			return clientes;
		}
		static vector<Pedido*> GenerarPedidos(int cantidad)
		{
			vector<Pedido*> pedidos;
			for (int i = 0; i < cantidad; i++)
			{
				Pedido* pedido = new Pedido();
				int numClientes = SBaseDatos::getInstance()->Clientes->longitud();
				pedido->DNICliente = SBaseDatos::getInstance()->Clientes->obtenerPos(rand() % numClientes)->DNI;

			}
		}
	private:
		static vector<Cliente*> GroomID(vector<Cliente*> revisar)
		{
			//Eliminar clientes con id repetidos
			vector<Cliente*> clientes;
			for (int i = 0; i < revisar.size(); i++)
			{
				bool repetido = false;
				for (int j = 0; j < clientes.size(); j++)
				{
					if (revisar[i]->DNI == clientes[j]->DNI)
					{
						repetido = true;
						break;
					}
				}
				if (!repetido)
				{
					clientes.push_back(revisar[i]);
				}
			}
		}
	};
}

