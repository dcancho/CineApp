#include<functional>
//Renzo
using namespace std;

template<class T>
class Lista {
    typedef function<int(T)>Comp;
    Nodo<T>* inicio;
    Nodo<T>* final;
    unsigned int cantidad;//elementos de la lista 
    Comp comparar;//lambda
public:
    Lista() :inicio(nullptr), final(nullptr), cantidad(0), comparar([](T a, T b) {return a - b; }) {}
    ~Lista() {
        Nodo* aux = ini;
        while (aux != nullptr) {
            aux = ini;
            ini = ini->sig;
            delete aux;
        }
    }
    size_t Cantidad() { return cantidad; }
    unsigned int Vacia() { return cantidad = 0; }
    void Agregar(T elem) {
        Nodo<T>* nuevo = new Nodo<T>(elem);
        if (cantidad == 0) {
            inicio = nuevo;
            final = nuevo;
        }
        else {
            inicio->sig = nuevo;
            inicio = nuevo;
        }cantidad++;
    }
    void Print(function<void(T)>imprime) {
        Nodo<T>* aux = inicio;
        while (aux->sig != nullptr) {
            imprime(aux->elemento);
            aux = aux->sig;
        }
        imprime(aux->sig);
        cout << endl;
    }
    T AccedeElemento(int n) {}
    void Borrar(int n) {
        Nodo<T>* lista = inicio;
        if (lista != nullptr) {
            Nodo<T>* aux;
            Nodo<T>* ant = nullptr;//anterior=nullptr
            aux = lista;
            //Recorrer
            for (int i = 0; i < n; ++i) {
                ant = aux;
                aux = aux->sig;
            }
            //condicion primer elem
            if (ant == nullptr) {
                lista = lista->sig;
                delete aux;
            }
            else {
                ant->sig = aux->sig;
                delete aux;
            }

        }
        inicio = lista;
    }
    // por mejorar 
    T Buscar(T elem) {
        Nodo<T>* aux = inicio;
        while (aux != nullptr) {
            if (comparar(aux->elem) == 0)
                return aux->elem;
            aux = aux->sig;
        }
        return 0;
    }
    //alternativa con lambda
    T CondicionBuscar(function<bool(T)>condicion) {
        Nodo<T>* aux = inicio;
        while (aux->sig != nullptr && !condicion(aux->elemento)) {
            aux = aux->sig;
        }if (condicion(aux->elemento)) { return aux->elemento; cout << "correcto"; }

    }
};