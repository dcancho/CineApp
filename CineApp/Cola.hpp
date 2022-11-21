#pragma once
#include<iostream>

template<class T >
class Nodo {
public:
	T elem; Nodo<T>* siguiente;
	Nodo(T e, Nodo<T>* s = NULL) {
		elem = e; siguiente = s;
	}
};

//Estructura 1
template<class T >
class Cola {
private:
	Nodo<T>* inicio; Nodo<T>* fin; size_t cantidad;
public:
	Cola() { inicio = nullptr; fin = nullptr; cantidad = 0; }	
	size_t getCantidad() { return cantidad; }
	void insertar(T e) {
		Nodo<T>* nuevoNodo = new Nodo<T>(e);
		if (cantidad == 0) {
			inicio = nuevoNodo;
			fin = inicio;
		}
		else {
			fin->siguiente = nuevoNodo;
			fin = nuevoNodo;
		}
		nuevoNodo = nullptr;
		cantidad++;
	}
	void Imprimir(T imprime) {
		Nodo<T>* aux = inicio;
		int i = 0;
		while (aux->siguiente != nullptr) {
			cout << "( " << i << ")";
			imprime(aux->elem);
			aux = aux->siguiente;
			i++;
		}
		cout << "( " << i << ")";
		imprime(aux->elem); cout << endl;
	}
	void Eliminar() {
		if (inicio == fin) {
			inicio = NULL; fin = NULL; cantidad = 0;
		}
		else {
			inicio = inicio->siguiente;
			cantidad--;
		}
	}
	T SacarCola() {
		T aux = inicio->elem;
		Eliminar();
		return aux;
	}
};