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
		int numPalabras;
	public:
		Sopa_letras();

		int NumPalabras() { return numPalabras; }
		int size() { return matriz.size(); }
		int getMaxCol() { return matriz.getMaxCol(); }
		int getNumCols() { return matriz.getNumCols(); }
		char getPrimerCaracter() { return matriz.Get(7,7); }

		friend ostream & operator<<(ostream & s, Sopa_letras & sopa){
			for(int i=sopa.matriz.getMinFila();i<=sopa.matriz.getMaxFila();i++){
				for(int j=sopa.matriz.getMinCol();j<=sopa.matriz.getMaxCol();j++){
					if(sopa.matriz.Get(i,j) != sopa.matriz.getValorDefecto())
						s << sopa.matriz.Get(i,j) << " ";
					else
						s << sopa.matriz.getValorDefecto() << " ";
				}		
				s << '\n';
			}
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
				bool puedeInsertarse=true;
			    cout << "palabra string " << palabra << endl;
			    cout << "J:  " << j << endl;
			    if(dir == "hi"){ // horizontal izquierda
			    	int inc = j;
			    	for (unsigned int index=0;index<palabra.length();index++,inc--){
				    	//cout << "llamando a setear " << endl;
	    				if(sopa.matriz.Get(i,inc) != sopa.matriz.getValorDefecto() and sopa.matriz.Get(i,inc) != palabra_char[index]){
	    					cout << "no puede insertarse " << palabra << endl;
	    					puedeInsertarse=false;
	    				}
			    	}
			    	if(puedeInsertarse)
					    for (unsigned int index=0;index<palabra.length();index++,j--){
					    //	cout << "llamando a setear " << endl;
		    				sopa.matriz.Set(i,j,palabra_char[index]);
					    }
				}
			    else if (dir == "hd"){ // horizontal derecha
			    	int inc=j;
			    	for (unsigned int index=0;index<palabra.length();index++,inc++){
				    	cout << "llamando a setear j:" << inc << endl;
	    				if(sopa.matriz.Get(i,inc) != sopa.matriz.getValorDefecto() and sopa.matriz.Get(i,inc) != palabra_char[index]){
							cout << "no puede insertarse " << palabra << endl;

	    					puedeInsertarse=false;
	    				}
			    	}
			    	if(puedeInsertarse)
				    	for (unsigned int index=0;index<palabra.length();index++,j++){
		    				sopa.matriz.Set(i,j,palabra_char[index]);
				    	}
			    }
    			else if (dir == "vu"){ // vertical arriba
    				int inc = i;
    				for (unsigned int index=0;index<palabra.length();index++,inc--){
				    	//cout << "llamando a setear " << endl;
	    				if(sopa.matriz.Get(inc,j) != sopa.matriz.getValorDefecto() and sopa.matriz.Get(inc,j) != palabra_char[index]){
	    					cout << "no puede insertarse " << palabra << endl;
	    					puedeInsertarse=false;
	    				}
			    	}
			    	if(puedeInsertarse)
				    	for (unsigned int index=0;index<palabra.length();index++,i--){
					    	//cout << "llamando a setear " << endl;
		    				sopa.matriz.Set(i,j,palabra_char[index]);
				    	}
			    }
    			else if (dir == "vd"){ // vertical abajo
    				int inc = i;
    				for (unsigned int index=0;index<palabra.length();index++,inc++){
				    	//cout << "llamando a setear " << endl;
	    				if(sopa.matriz.Get(inc,j) != sopa.matriz.getValorDefecto() and sopa.matriz.Get(inc,j) != palabra_char[index]){
	    					cout << "no puede insertarse " << palabra << endl;
	    					puedeInsertarse=false;
	    				}
			    	}
			    	if(puedeInsertarse)
				    	for (unsigned int index=0;index<palabra.length();index++,i++){
							//cout << "llamando a setear " << endl;
		    				sopa.matriz.Set(i,j,palabra_char[index]);
				    	}
			    }
    			else if (dir == "dd"){ // diagonal abajo derecha
    				int inci = i;
    				int incj = j;
    				for (unsigned int index=0;index<palabra.length();index++,inci++,incj++){
				    	//cout << "llamando a setear " << endl;
	    				if(sopa.matriz.Get(inci,incj) != sopa.matriz.getValorDefecto() and sopa.matriz.Get(inci,incj) != palabra_char[index]){
	    					cout << "no puede insertarse " << palabra << endl;
	    					puedeInsertarse=false;
	    				}
			    	}
			    	if(puedeInsertarse)
				    	for (unsigned int index=0;index<palabra.length();index++,i++,j++){
					    	//cout << "llamando a setear " << endl;
		    				sopa.matriz.Set(i,j,palabra_char[index]);
				    	}
			    }
    			else if (dir == "di"){ // diagonal abajo izquierda
    				int inci = i;
    				int incj = j;
    				for (unsigned int index=0;index<palabra.length();index++,inci++,incj--){
				    	//cout << "llamando a setear " << endl;
	    				if(sopa.matriz.Get(inci,incj) != sopa.matriz.getValorDefecto() and sopa.matriz.Get(inci,incj) != palabra_char[index]){
	    					cout << "no puede insertarse " << palabra << endl;
	    					puedeInsertarse=false;
	    				}
			    	}
			    	if(puedeInsertarse)
				    	for (unsigned int index=0;index<palabra.length();index++,i++,j--){
				    		//cout << "llamando a setear " << endl;
		    				sopa.matriz.Set(i,j,palabra_char[index]);
				    	}
			    }
    			sopa.numPalabras++;
				delete[] palabra_char;

			}

		    return is;
		}
};


#include "../src/sopa_letras.cpp"
#endif