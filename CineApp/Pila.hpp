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
	size_t tama�o;
public:
	Pila() {
		this->cabeza = this->top = nullptr;
		this->tama�o = 0ll;
	}
	~Pila() { while (tama�o)pop(); }
	size_t size() { return tama�o; }
	T top() {
		if (this->top == nullptr)cout << "No se puede retornar un valor de puntero nulo";
		return this->top->value;
	}
	void pop() {
		if (tama�o == 0)cout << "Pila vac�a";
		if (tama�o == 1) {
			delete this->cabeza;
			this->cabeza = this->top = nullptr;
			tama�o = 0;
			return;
		}
		this->top = this->top->anterior;
		this->top->siguiente->anterior = nullptr;
		this->top->siguiente->siguiente = nullptr;
		delete this->top->siguiente;
		--tama�o;
		this->top->siguiente = nullptr;
	}
	void push(T valor) {
		Nodo* newNodo = new Nodo(valor);
		if (!tama�o) {
			this->cabeza = this->top = newNodo;
			tama�o = 1ll;
			return;
		}
			newNodo->anterior = this->top;
			this->top = newNodo;
			++tama�o;
		
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
		if (tama�o > 0) {
			pop();
			Revertir();
			push(valor);
		}
	}
};
