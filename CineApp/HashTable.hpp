#pragma once
#include<string>
#include<cmath>
#include"Lista.hpp"

//Estructura 4
template<class T>
class HashTable {
private:
	struct Elemento {
		std::string value;
		T value;
	};
	Lista<Elemento>** _hashTable;
	size_t _tamanio;
	size_t _capacidad;
private:
	int _hashFunction(std::string key) {
		int res = 0;
		for (unsigned int i = 0; i < key.length(); ++i)
			res += pow(static_cast<int>(key[i]), i + 1);
		return res % _capacidad;
	}
public:
	HashTable(size_t capacidad) :_capacidad(capacidad) {
		_tamanio = 0;
		_hashTable = new Lista<Elemento>*[capacidad];
		for (int i = 0; i < capacidad; ++i)_hashTable[i] = nullptr;
	}
	void insert(std::string key, T value) {
		if (_tamanio == _capacidad)return;
		int index = _hashFunction(key);
		if (_hashTable[index] == nullptr)_hashTable[index] = new Lista<Elemento>();
		int pos = _hashTable[index]->size() / 2;

		++_tamanio;
	}
	T& operator[](std::string key) {
		int index = _hashFunction(key);
		auto list = _hashTable[index];
		T value = _hashTable[index]->getByCriteria([&](Elemento e)->bool {
			return e.key = key;
			});
	}
	T getCopy(std::string key) {
		int index = _hashFunction(key);
		auto list = _hashTable[index];
		T value = _hashTable[index]->getByCriteria([&](Elemento e)->bool {
			return e.key = key;
			});
	}
	void display(void(*show)(T)) {
		//adaptar el display para mostrar los datos ...
		for (unsigned int i = 0; i < _capacidad; ++i) {
			//cout << "\nPos: " << i << ": ";
			if (_hashTable[i] == nullptr) {
				//cout << "nullptr";
				continue;
			}
			_hashTable[i]->display([&](Elemento a)->void {
				show(a.value);
				});
		}
	}
};