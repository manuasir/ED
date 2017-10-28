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
			    char * palabra_char = new char[palabra.length() + 1];
				strcpy(palabra_char, palabra.c_str());
			    cout << "palabra string " << palabra << endl;
			    if(dir == "hi") // horizontal izquierda
				    for (unsigned int index=0;index<palabra.length();index++,j++){
				    	cout << "llamando a setear " << endl;
	    				sopa.matriz.Set(i,j,palabra_char[index]);
				    }
			    else if (dir == "hd"){ // horizontal derecha
				    	cout << "llamando a setear " << palabra.length() << palabra << endl;

			    	for (unsigned int index=0;index<palabra.length();index++,j--){
				    	cout << "llamando a setear " << palabra_char[index] << endl;

	    				sopa.matriz.Set(i,j,palabra_char[index]);
			    	}
			    }
    			else if (dir == "vu") // vertical arriba
			    	for (unsigned int index=0;index<palabra.length();index++,i--){
				    	cout << "llamando a setear " << endl;
	    				sopa.matriz.Set(i,j,palabra_char[index]);
			    	}
    			else if (dir == "vd") // vertical abajo
			    	for (unsigned int index=0;index<palabra.length();index++,i++){
						cout << "llamando a setear " << endl;
	    				sopa.matriz.Set(i,j,palabra_char[index]);
			    	}
    			else if (dir == "dd") // diagonal abajo derecha
			    	for (unsigned int index=0;index<palabra.length();index++,i++,j++){
				    	cout << "llamando a setear " << endl;
	    				sopa.matriz.Set(i,j,palabra_char[index]);
			    	}
    			else if (dir == "di") // diagonal abajo izquierda
			    	for (unsigned int index=0;index<palabra.length();index++,i++,j--){
			    		cout << "llamando a setear " << endl;
	    				sopa.matriz.Set(i,j,palabra_char[index]);
			    	}
    			else
    				cout << "NO COINCIDE" << dir << endl;
				delete[] palabra_char;

			}
		    return is;
		}
};


#include "../src/sopa_letras.cpp"
#endif