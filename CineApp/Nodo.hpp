//Nodo con puntero a Nodo siguiente
template<class T>
class Nodo 
{
public:
	T Dato;
	Nodo<T>* Siguiente;
	Nodo(T elem, Nodo<T>* sig = nullptr)
	{
		Dato = elem;
		Siguiente = sig;
	}
};

//Nodo con punteros a Nodo anterior y siguiente
template<class T>
class NodoD : public Nodo<T>
{
public:
	NodoD<T>* Anterior;
	NodoS(T elem, Nodo<T>* sig = nullptr, Nodo<T>* ant = nullptr) : Nodo<T>(elem, sig)
	{
		Anterior = ant;
	}
};