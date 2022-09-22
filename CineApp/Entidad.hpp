#pragma once
#include <iostream>
#include <string>

using namespace std;

class Entidad
{
protected:
	int ID = 0;
public:
	//Formato lineal para guardar en archivo de texto
	virtual string ToString() {}
	//Recuperar valores a partir de un string de archivo
	virtual void FromString(std::string s) {}
	//Impresión en comprobante de pago
	virtual void Imprimir(ostream out) {}
};