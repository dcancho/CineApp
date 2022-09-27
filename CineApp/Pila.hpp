#pragma once
#include<iostream>
#include"Lista.hpp"
using namespace std;

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
	size_t tamaño;
public:
	Pila() {
		this->cabeza = this->top = nullptr;
		this->tamaño = 0ll;
	}
	~Pila() { while (tamaño)pop(); }
	size_t size() { return tamaño; }
	T top() {
		if (this->top == nullptr)cout << "No se puede retornar un valor de puntero nulo";
		return this->top->value;
	}
	void pop() {
		if (tamaño == 0)cout << "Pila vacía";
		if (tamaño == 1) {
			delete this->cabeza;
			this->cabeza = this->top = nullptr;
			tamaño = 0;
			return;
		}
		this->top = this->top->anterior;
		this->top->siguiente->anterior = nullptr;
		this->top->siguiente->siguiente = nullptr;
		delete this->top->siguiente;
		--tamaño;
		this->top->siguiente = nullptr;
	}
	void push(T valor) {
		Nodo* newNodo = new Nodo(valor);
		if (!tamaño) {
			this->cabeza = this->top = newNodo;
			tamaño = 1ll;
			return;
		}
			newNodo->anterior = this->top;
			this->top = newNodo;
			++tamaño;
		
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
		if (tamaño > 0) {
			pop();
			Revertir();
			push(valor);
		}
	}
};
