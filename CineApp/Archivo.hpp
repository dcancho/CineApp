#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
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

template <class T>
//Lector binario
class BinLector : public Archivo<T>
{
private:
	ifstream file;
public:
	BinLector(string filename) : Archivo(filename)
	{
		file.open(filename,ios::in, ios::binary);
	}
	~BinLector()
	{
		file.close();
	}
	T LeerValor()
	{
		T elem = new T();
		file >> elem;
		return elem;
	}
};

template<class T>
//Escritor binario
class BinEscritor : public Archivo<T>
{
private:
	ofstream file;
public:
	BinEscritor(string filename) : Archivo(filename)
	{
		file.open(filename, ios::out, ios::binary);
	}
	~BinEscritor()
	{
		file.close();
	}
	void EscribirValor(T elem)
	{
		file << elem;
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