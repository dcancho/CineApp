#pragma once

#include <functional>

using namespace std;

typedef unsigned int uint;

template <typename T>
class Lista {
    struct Nodo;
    typedef function<int(T, T)> Comp;

    Nodo* ini;
    Nodo* ant;
    uint    lon; // número de elementos en la lista

    Comp    comparar; // lambda de criterio de comparación

public:
    Lista()
    {
        ini = nullptr;
        ant = nullptr;
        lon = 0;
        comparar = [](T a, T b) { return a < b; };
    }
    Lista(Comp comparar) : ini(nullptr), ant(nullptr), lon(0), comparar(comparar) {}
    ~Lista();

    uint    longitud();

    bool    esVacia();

    void    agregaInicial(T elem);
    void    agregaPos(T elem, uint pos);
    void    agregaFinal(T elem);

    void    modificarInicial(T elem);
    void    modificarPos(T elem, uint pos);
    void    modificarFinal(T elem);

    void    eliminaInicial();
    void    eliminaPos(uint pos);
    void    eliminaFinal();
    void    insertAt(T value, int pos);//lista doble enlazada 

    T       obtenerInicial();
    T       obtenerPos(uint pos);
    T       obtenerFinal();

    T       buscar(T elem);
    T       getByCriteria(function<bool(T)>criteria);
};

template <typename T>
struct Lista<T>::Nodo {
    T       elem;
    Nodo* sig; // puntero apunta al siguiente nodo
    Nodo* ant;//puntero apunta al anterior nodo

    Nodo(T elem = NADA, Nodo* sig = nullptr, Nodo* ant = nullptr) : elem(elem), sig(sig), ant(ant) {}
};

template <typename T>
Lista<T>::~Lista() {
    Nodo* aux = ini;
    while (aux != nullptr) {
        aux = ini;
        ini = ini->sig;
        delete aux;
    }
}

template <typename T>
uint Lista<T>::longitud() {
    return lon;
}

template <typename T>
bool Lista<T>::esVacia() {
    return lon == 0;
}

template <typename T>
void Lista<T>::agregaInicial(T elem) {
    Nodo* nuevo = new Nodo(elem, ini);
    if (nuevo != nullptr) {
        ini = nuevo;
        lon++;
    }
}

template <typename T>
void Lista<T>::agregaPos(T elem, uint pos) {
    if (pos > lon) return;
    if (pos == 0) {
        agregaInicial(elem);
    }
    else {
        Nodo* aux = ini;
        for (int i = 1; i < pos; i++) {
            aux = aux->sig;
        }
        Nodo* nuevo = new Nodo(elem, aux->sig);
        if (nuevo != nullptr) {
            aux->sig = nuevo;
            lon++;
        }
    }
}
template <typename T>
void Lista<T>::agregaFinal(T elem) {
    agregaPos(elem, lon);
}

template <typename T>
void Lista<T>::modificarInicial(T elem) {
    if (lon > 0) {
        ini->elem = elem;
    }
}
template <typename T>
void Lista<T>::modificarPos(T elem, uint pos) {
    if (pos >= 0 && pos < lon) {
        Nodo* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->sig;
        }
        aux->elem = elem;
    }
}
template <typename T>
void Lista<T>::modificarFinal(T elem) {
    modificar(elem, lon - 1);
}

template <typename T>
void Lista<T>::eliminaInicial() {
    if (lon > 0) {
        Nodo* aux = ini;
        ini = ini->sig;
        delete aux;
        lon--;
    }
}
template <typename T>
void Lista<T>::eliminaPos(uint pos) {
    if (pos >= 0 && pos < lon) {
        if (pos == 0) {
            eliminaInicial();
        }
        else {
            Nodo* aux = ini;
            for (int i = 1; i < pos; i++) {
                aux = aux->sig;
            }
            Nodo* aux2 = aux->sig;
            aux->sig = aux2->sig;
            delete aux2;
            lon--;
        }
    }

}
template <typename T>
void Lista<T>::eliminaFinal() {
    eliminaPos(lon - 1);

}

template <typename T>
T Lista<T>::obtenerInicial() {
    return obtenerPos(0);
}
template <typename T>
T Lista<T>::obtenerPos(uint pos) {
    if (pos >= 0 && pos < lon) {
        Nodo* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->sig;
        }
        return aux->elem;
    }
    else {
        return nullptr;
    }
}
template <typename T>
T Lista<T>::obtenerFinal() {
    return obtenerPos(lon - 1);
}

template <typename T>
T Lista<T>::buscar(T elem) {
    Nodo* aux = ini;
    while (aux != nullptr) {
        if (comparar(aux->elem, elem) == 0) {
            return aux->elem;
        }
        aux = aux->sig;
    }
    return nullptr;
}

template <typename T>
void Lista<T>::insertAt(T value, int pos) {
    if (pos<0 || pos>lon)return;
    if (pos == 0) { agregaInicial(value); return; }
    if (pos == lon) { agregaFinal(value); return; }
    Nodo* aux = this->ini;
    Nodo* newNode = new Nodo(value);
    for (int i = 0; i < pos - 1; ++i)aux = aux->sig;
    //enlazar el nodo a isnertar con el nodo en la posición pos (aux->next)
    newNode->sig = aux->sig;
    aux->sig->ant = newNode;
    //enlaza el nodo a insertar con el nodo anterior al de la posición pos(aux)
    aux->sig = newNode;
    newNode->ant = aux;

    ++this->lon;
}
template<typename T>
T Lista<T>::getByCriteria(function<bool(T)>criteria) {
    Nodo* aux = this->ini;
    while (aux) {
        if (criteria(aux->value))return aux->value;
        aux = aux->next;
    }
    return T();
}
