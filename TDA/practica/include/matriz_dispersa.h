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
		friend ostream & operator<<(ostream & s, Matriz_Dispersa<T> & mat){
			for(int i=0;i<mat.m.size();++i){
				 s << mat.m[i].d << endl;
			}
			return s;
		}
};


#include "../src/matriz_dispersa.cpp"
#endif