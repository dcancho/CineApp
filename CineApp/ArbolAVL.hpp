#pragma once
#pragma once
#include<functional>
#include<stack>
#include<vector>
using namespace std;


template <class T>
class ArbolAVL {
private:
	struct Nodo {
		T value;
		Nodo* izq;
		Nodo* der;
		int altura;
	};
	Nodo* _raiz;
	size_t _tamanio;
	function<void(T)>_mostrar;
	function<bool(T, T)>_comparar;
	function<bool(T, T)>_igual;
public:
	ArbolAVL(function<void(T)>mostrar, function<bool(T, T)>Compara, function<bool(T, T)>igual) :_mostrar(mostrar), _comparar(Compara), _igual(igual) {
		_raiz = nullptr;
		_tamanio = 011;
	}
	void insertar(T value) { _insertar(_raiz, value); }
	void preOrden() { _preOrden(_raiz); }
	T maximo() {
		Nodo* aux = _raiz;
		while (aux->der != nullptr)aux = aux->der;
		return aux->value;
	}
	void IterarPreOrden() {
		std::stack<Nodo*>s;
		s.push(this->_raiz);
		while (s.empty() == false) {
			//saca un nodo de la pila
			Nodo* n = s.top();
			s.pop();
			//muestra en consola
			_mostrar(n->value);
			//Inserto en la pila a sus hijos derecho e ezquiedo,
			// en ese orden, en la pila (si es que no son nulos)
			if (n->der)
				s.push(n->der);
			if (n->izq)
				s.push(n->izq);
		}
	}
	void remover(T value) {
		vector<Nodo*>path;
		Nodo* parent = nullptr;//padre de n
		Nodo* n = _Remover(parent, value, path);//actual nodo
		if (n == nullptr) {
			cout << ":c";
			return;
		}
		while (n != nullptr) {
			if (n->izq == nullptr && n->der == nullptr) {
				if (n == _raiz) {
					delete n;
					n = nullptr;
					_raiz = nullptr;
					--_tamanio;
					break;
				}
				else if (parent->izq == n)parent->izq = nullptr;
				else parent->der = nullptr;
				delete n;
				n = nullptr;
				--_tamanio;
				continue;
			}
			if (n->izq != nullptr && n->der != nullptr) {
				path.push_back(n);
				Nodo* menorParent = nullptr;
				Nodo* menorNodo = _getMenorElemento(n->der, menorParent, path);
				this->_swap(n->value, menorNodo->value);
				if (menorNodo == menorParent)parent = n;
				else parent = menorParent;
				n = menorNodo;
				continue;
			}
			if (n->izq != nullptr) {
				if (n == _raiz)_raiz = n->izq;
				else if (parent->der == n)parent->der = n->izq;
				else parent->izq = n->izq;
				delete n;
				--_tamanio;
				n = nullptr;
				continue;
			}
			if (n->der != nullptr) {
				if (n == _raiz)_raiz = n->der;
				else if (parent->izq == n)parent->izq = n->der;
				else parent->der = n->der;
				delete n;
				--_size;
				n = nullptr;
			}
		}
		_equilibrioEnEliminacion(path);
		path.clear();
	}
private:
	void _insertar(Nodo*& n, T value) {
		if (n == nullptr) {
			n = new Nodo{ value,nullptr,nullptr,0 };
			++_tamanio;
			return;
		}
		if (_comparar(n->value, value))_insertar(n->izq, value);
		else _insertar(n->der, value);
		_setAltura(n);
		_balanceSubArbol(n);
	}
	void _preOrden(Nodo* n) {
		if (!n)return;
		_mostrar(n->value);
		_preOrden(n->izq);
		_preOrden(n->der);
	}
	void _rotacionIzq(Nodo*& n) {
		Nodo* right = n->der;
		n->der = right->izq;
		right->izq = n;
		_setAltura(n);
		_setAltura(right);
		n = right;
	}
	void _rotacionDer(Nodo*& n) {
		Nodo* left = n->izq;
		n->izq = left->der;
		left->der = n;
		_setAltura(n);
		_setAltura(left);
		n = left;
	}
	void _balanceSubArbol(Nodo*& n) {
		int diferenciaAltura = _getAltura(n->izq) - _getAltura(n->der);
		if (diferenciaAltura <= -2) {//desbalanceado por la derecha
			if (n->der->der) {
				_rotacionIzq(n);
			}
			else {
				_rotacionDer(n->der);
				_rotacionIzq(n);
			}
		}
		else if (diferenciaAltura >= 2) 
		{//desbalanceado por la izquierda
			if (n->izq->izq) {
				_rotacionDer(n);
			}
			else {
				_rotacionIzq(n->izq);
				_rotacionDer(n);
			}
		}
	}
	void _setAltura(Nodo* n) {
		n->altura = max(_getAltura(n->izq), _getAltura(n->der)) + 1;
	}
	int _getAltura(Nodo* n) {
		return (n) ? n->altura : -1;
	}
	/*Nodo* _Remover(Nodo*& parent, T value, std::vector<Nodo*>& path) {
		Nodo* aux = _raiz;
		while (aux) {
			if (_igual(aux->value, value))
				break;
			path.push_back(aux);
			parent = aux;
			if (_comparar(aux->value, value))
				aux = aux->izq;
			else
				aux = aux->der;
		}
		return aux;
	}*/
	//Nodo* _getMenorElemento(Nodo* inicio, Nodo*& parent, vector<Nodo*>& path) {
	//	Nodo* aux = inicio;
	//	parent = inicio;
	//	while (aux->izq != nullptr) {
	//		parent = aux;
	//		path.push_back(aux);
	//		aux = aux->izq;
	//	}
	//	return aux;
	//}
	void _swap(T& a, T& b) {
		T c = a;
		a = b;
		b = c;
	}
	/*void _equilibrioEnEliminacion(vector<Nodo*>& path) {
		if (path.size() == 1) {
			Nodo* c = path[path.size() - 1];
			_setAltura(c);
			_balanceSubArbol(c);
			c = nullptr;
			return;
		}
		int index = path.size() - 1;
		Nodo* hijo = nullptr;
		Nodo* parent = path[index];
		while (true) {
			--index;
			if (index < 0)
				breack;
			hijo = parent;
			parent = path[index];
			_setAltura(hijo);
			if (parent->izq == hijo) {
				_balanceSubArbol(hijo);
				parent->izq = hijo,
			}
			else {
				_balanceSubArbol(hijo);
				parent->der = hijo;
			}
		}
		hijo = nullptr;
		parent = nullptr;
	}*/

};