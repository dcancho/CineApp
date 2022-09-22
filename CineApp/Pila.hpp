#include "Nodo.hpp"
#include <functional>
#define uint unsigned int
template<class T>
class Pila
{
private:
	Nodo<T>* Tope;
	uint Tamaño;
public:
	Pila()
	{
		Tope = nullptr;
		Tamaño = 0;
	}
	~Pila()
	{
		Nodo<T>* aux = Tope;
		while (aux != nullptr)
		{
			aux = Tope;
			Tope = Tope->Siguiente;
			delete aux;
		}
	}
	void Push(T elem)
	{
		Nodo<T>* nuevo = new Nodo<T>(elem);
		if (Tamaño == 0)
		{
			Tope = nuevo;
		}
		else
		{
			nuevo->Siguiente = Tope;
			Tope = nuevo;
		}
		Tamaño++;
	}
	T Pop()
	{
		if (Tamaño == 0)
		{
			throw "Pila vacia";
		}
		else
		{
			Nodo<T>* aux = Tope;
			T elem = aux->Dato;
			Tope = Tope->Siguiente;
			delete aux;
			Tamaño--;
			return elem;
		}
	}
	T Peek()
	{
		if (Tamaño == 0)
		{
			throw "Pila vacia";
		}
		else
		{
			return Tope->Dato;
		}
	}
	bool Vacia()
	{
		return Tamaño == 0;
	}
	void Flush()
	{
		Nodo<T>* aux = Tope;
		while (aux != nullptr)
		{
			aux = Tope;
			Tope = Tope->Siguiente;
			delete aux;
		}
		Tamaño = 0;
	}
	uint Cantidad()
	{
		return Tamaño;
	}
};