#pragma once
#include <fstream>
#include <iostream>
#include <string>



using namespace std;

namespace CineApp {
	template<class T>
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
	class TxtLector : public Archivo<string>
	{
	private:
		ifstream file;
	public:
		TxtLector(string filename) : Archivo(filename)
		{
			file.open(filename, ios::in);
		}
		~TxtLector()
		{
			file.close();
		}
		char* LeerLinea()
		{
			if (!file.eof())
			{
				string output = "";
				getline(file, output);
				//convert string to char*
				char* cstr = new char[output.length() + 1];
				strcpy(cstr, output.c_str());
				return cstr;
			}
			return nullptr;
		}
	};

	//Escritor .txt
	class TxtEscritor : public Archivo<string>
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
		void EscribirLinea(char* line)
		{
			file << line << endl;
		}
		void Escribir(char* text)
		{
			file << text;
		}
	};

	//Lector .csv
	class CsvLector : public Archivo<string>
	{
	private:
		ifstream file;
	public:
		CsvLector(string filename) : Archivo(filename)
		{
			file.open(filename, ios::in);
		}
		~CsvLector()
		{
			file.close();
		}
		char* LeerLinea()
		{
			if (!file.eof())
			{
				string output = "";
				getline(file, output);
				//convert string to char*
				char* cstr = new char[output.length() + 1];
				strcpy(cstr, output.c_str());
				return cstr;
			}
			return nullptr;
		}
	};

	//Escritor .csv
	class CsvEscritor : public Archivo<string>
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
		void EscribirLinea(char* line)
		{
			file << line << endl;
		}
		void Escribir(char* text)
		{
			file << text;
		}
	};


}
