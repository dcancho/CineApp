#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

	class Archivo
	{
	private:
		string filename;
	public:
		Archivo()
		{
			filename = "";
		}
		Archivo(string filename)
		{
			this->filename = filename;
		}
	};

	//Lector .txt
	class TxtLector : public Archivo
	{
	private:
		ifstream file;
		vector<string> archivo;

	public:
		TxtLector(string filename) : Archivo(filename)
		{
			file.open(filename, ios::in);
		}
		~TxtLector()
		{
			try
			{
				file.close();
			}
			catch (const std::exception&)
			{
				throw "Error al cerrar el archivo";
			}
		}
		//Lee todo el archivo y lo almacena en un vector de string
		void Leer()
		{
			string linea;
			if (file.is_open())
			{
				while (getline(file, linea))
				{
					archivo.push_back(linea);
				}
			}
		}
		string Linea(int i)
		{
			return archivo[i];
		}
		vector<string> returnArchivo()
		{
			return archivo;
		}
	};

	//Escritor .txt
	class TxtEscritor : public Archivo
	{
	private:
		ofstream file;
	public:
		TxtEscritor(string filename) : Archivo(filename)
		{
			file.open(filename, ios::out);
		}
		~TxtEscritor()
		{
			file.close();
		}
		void EscribirLinea(string line)
		{
			file << line << endl;
		}
		void Escribir(string text)
		{
			file << text;
		}
	};

	//Lector .csv
	class CsvLector : public Archivo
	{
	private:
		ifstream file;
		vector<vector<string>> archivo;
	public:
		CsvLector(string filename) : Archivo(filename)
		{
			file.open(filename, ios::in);
		}
		~CsvLector()
		{
			file.close();
		}
		void Leer()
		{
			string linea;
			if (file.is_open())
			{
				while (getline(file, linea))
				{
					vector<string> tokens;
					stringstream ss;
					for (int i = 0; i < linea.size(); i++)
					{
						if (linea[i] == ',')
						{
							tokens.push_back(ss.str());
							ss.str("");
						}
						else
						{
							ss << linea[i];
						}
					}
					tokens.push_back(ss.str());
					archivo.push_back(tokens);
				}
			}
		}
		int Filas()
		{
			return archivo.size();
		}
		vector<string> Linea(int i)
		{
			return archivo[i];
		}
		vector<vector<string>> returnArchivo()
		{
			return archivo;
		}
	};

	//Escritor .csv
	class CsvEscritor : public Archivo
	{
	private:
		ofstream file;
	public:
		CsvEscritor(string filename) : Archivo(filename)
		{
			file.open(filename, ios::out);
		}
		~CsvEscritor()
		{
			file.close();
		}
		void Escribir(vector<string> linea)
		{
			for (int i = 0; i < linea.size(); i++)
			{
				file << linea[i];
				if (i != linea.size() - 1)
				{
					file << ",";
				}
			}
			file << endl;
		}
	};
