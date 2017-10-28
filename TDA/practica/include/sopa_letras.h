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
};


#include "../src/sopa_letras.cpp"
#endif