#pragma once
#include<iostream>
#include"Lista.hpp"
using namespace std;

//Estructura 2
template<typename T >
class Pila {
	typedef long long ll;
private:
	struct Nodo {
		T valor;
		Nodo* siguiente;
		Nodo* anterior;
		Nodo() = delete;
		Nodo(T valor) :valor(valor), siguiente(nullptr), anterior(nullptr) {}
	};
	Nodo* cabeza;
	Nodo* top;
	size_t tamano;
public:
	Pila() {
		this->cabeza = this->top = nullptr;
		this->tamano = 0ll;
	}
	~Pila() { while (tamano)pop(); }
	size_t size() { return tamano; }
	T getTop() {
		if (this->top == nullptr)cout << "No se puede retornar un valor de puntero nulo";
		return this->top->valor;
	}
	void pop() {
		if (tamano == 0)cout << "Pila vacia";
		if (tamano == 1) {
			delete this->cabeza;
			this->cabeza = this->top = nullptr;
			tamano = 0;
			return;
		}
		this->top = this->top->anterior;
		this->top->siguiente->anterior = nullptr;
		this->top->siguiente->siguiente = nullptr;
		delete this->top->siguiente;
		--tamano;
		this->top->siguiente = nullptr;
	}
	void push(T valor) {
		Nodo* newNodo = new Nodo(valor);
		if (!tamano) {
			this->cabeza = this->top = newNodo;
			tamano = 1ll;
			return;
		}
			newNodo->anterior = this->top;
			this->top = newNodo;
			++tamano;
		
	}
	void Imprime(T imprime) {
		Nodo* aux = cabeza;
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
	void Revertir() {
		Nodo* newNodo = new Nodo();
		if (tamano > 0) {
			pop();
			Revertir();
			push(valor);
		}
	}
};
