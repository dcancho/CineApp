#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;


void GenerarCartelera(int cantidad)
{
	//Leer moviename.txt y guardar strings en un vector
	ifstream file("moviename.txt");
	vector<string> nombres;
	string s;
	while (getline(file, s))
	{
		nombres.push_back(s);
	}
	file.close();
}
//
//static void GenerarClientes(int cantidad)
//{
//	CsvLector* archivo = new CsvLector("namedata.csv");
//	
//	vector<string> nombres = archivo->returnArchivo()[0];
//	vector<string> apellidos = archivo->returnArchivo()[1];
//	vector<string> clientes;
//	for (int i = 0; i < cantidad; i++)
//	{
//		string init;
//		string nombre = nombres[rand() % nombres.size()];
//		string apellido = apellidos[rand() % apellidos.size()];
//		init.append(nombre + " " + apellido);
//		init.append(",");
//		init.append(to_string(rand() % 100000000));
//		init.append(",");
//		init.append(to_string(nombre[0] + apellido[0]));
//		init.append(",");
//		init.append(to_string(12345678));
//		clientes.push_back(init);
//	}
//	//write clientes to a txt file
//	TxtEscritor* clientesFile = new TxtEscritor("clientes.txt");
//	for (int i = 0; i < clientes.size(); i++)
//	{
//		clientesFile->EscribirLinea(clientes[i]);
//	}
//}


int main()
{
	GenerarCartelera(100);
	//GenerarClientes(100);
	return 0;
}

