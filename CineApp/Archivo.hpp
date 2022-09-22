#pragma once
#include <fstream>
#include <iostream>

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
		T elem;
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
	string LeerLinea()
	{
		
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
	void EscribirLinea(string line)
	{
		file << line << endl;
	}
	void Escribir(string text)
	{
		file << text;
	}
};