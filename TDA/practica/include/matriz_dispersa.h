#ifndef _MATRIZ_DISPERSA_H
#define _MATRIZ_DISPERSA_H
#include "./vd.h"
#include <iostream>
using namespace std;
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
		void Set(int i,int j,T dato);
		int size(){ return m.size(); }
		const char getValorDefecto() const { return valor_defecto; }
		void setValorDefecto(const char & car) { m[m.size()-1].d = car; valor_defecto=car; }
		int getMinCol();
		int getMaxCol();
		int getMinFila();
		int getMaxFila();
};


#include "../src/matriz_dispersa.cpp"
#endif