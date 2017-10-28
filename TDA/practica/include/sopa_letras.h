#ifndef _SOPA_LETRAS_H_
#define _SOPA_LETRAS_H_
#include "./matriz_dispersa.h"
#include <iostream>
using namespace std;

class Sopa_letras{
	private:
		
		Matriz_Dispersa<char> matriz;
	public:
		Sopa_letras();
		friend ostream & operator<<(ostream & s, Sopa_letras & sopa){
			return s;
		}

		friend istream & operator>>(istream & is, Sopa_letras & sopa) {
		    return is;
		}
};


#include "../src/sopa_letras.cpp"
#endif