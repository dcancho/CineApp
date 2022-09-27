﻿#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Entidad
{
protected:
	int ID = 0;
public:
	Entidad()
	{
		ID = 0;
	}
	//Formato lineal para guardar en archivo de texto
	virtual char* ToString() { return ""; }
	//Recuperar valores a partir de un string de archivo
	virtual void FromString(std::string s) {}
	//Impresión en comprobante de pago
	virtual void Imprimir(ostream out) {}
};