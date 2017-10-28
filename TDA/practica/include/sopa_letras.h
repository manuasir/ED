#ifndef _SOPA_LETRAS_H_
#define _SOPA_LETRAS_H_
#include "./matriz_dispersa.h"
#include <iostream>
#include <sstream>
using namespace std;
class Sopa_letras{
	private:
		string titulo;
		Matriz_Dispersa<char> matriz;
	public:
		Sopa_letras();
		friend ostream & operator<<(ostream & s, Sopa_letras & sopa){
			return s;
		}

		friend istream & operator>>(istream & is, Sopa_letras & sopa) {
			cout << "operador entrada! " << endl;
			string titulo;
			getline(is, titulo);
			string line;
			while (std::getline(is, line))
			{
			    istringstream iss(line);
			    //cout << line << endl;
			    int i, j;
			    string dir,palabra;
			    if (!(iss >> i >> j >> dir >> palabra)) { break; } // error
			    //cout << a << b << endl;
			    cout << dir << endl;
			}
		    return is;
		}
};


#include "../src/sopa_letras.cpp"
#endif