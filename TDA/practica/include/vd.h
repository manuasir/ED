#ifndef _VD_H_
#define _VD_H_
#include <iostream>
using namespace std; 
template <class T>
class VD{
	private:
		T * datos;
		int reservados;
		int maximo;
		void copiar(const VD<T> & v);
		void liberar();
		int n;

	public:
		void resize(int n);

		VD<T>(int tam=5);
		VD<T>(const VD<T>& original);
		~VD<T>();
		const int size() const { return n; }
		VD<T> & operator=(const VD<T> & original);
		const T & operator[](int i) const { return datos[i]; }
		T & operator[](int i){ return datos[i]; }
		void set(T element);
		void set(int i,T element);
};
#include "../src/vd.cpp"
#endif