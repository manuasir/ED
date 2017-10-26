#ifndef _VD_H_
#define _VD_H_
using namespace std;
template <class T>

class VD{

	private:
		T * datos;
		int n;
		int reservados;
		void resize(int nuevo_tam);
		void copiar(int nuevo_tam);
		void copiar(const VD<T> & v);
		void liberar();


	public:
		VD<T>(int tam);
		VD<T>(const VD<T>& original);
		~VD<T>();
		const int size() const { return reservados; }
		VD<T> & operator=(const VD<T> & original);
		const T & operator[](int i) const { return datos[i]; }
		T & operator[](int i){ return datos[i]; }


};
#include "../src/vd.cpp"

#endif