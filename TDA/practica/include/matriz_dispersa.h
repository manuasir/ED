#ifndef _MATRIZ_DISPERSA_H
#define _MATRIZ_DISPERSA_H
#include "./vd.h"

template <class T>

class Matriz_Dispersa{
	private:
		struct tripleta{
			int fila,col;
			T d;
		};
		VD<tripleta> m;
		char valor_defecto;
	public:
		Matriz_Dispersa<T>();

};
#include "../src/matriz_dispersa.cpp"
#endif