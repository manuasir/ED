#ifndef _SOPA_LETRAS_H_
#define _SOPA_LETRAS_H_
#include "./matriz_dispersa.h"
#include "./vd.h"
#include <iostream>
#include <sstream>
using namespace std;

/**
  *  @brief T.D.A. Sopa de Letras
  *
  * Una instancia @e c del tipo de datos abstracto @c Sopa de Letras contiene un conjunto de palabras 
  * dispuesto en la direcciones verticales, horizontal o diagonal en una matriz dispersa.
  * Se representa:
  *
  * [{fila1,columna1,letra},...,{filaN,columnaN,valorN}]
  *
  * Un ejemplo de su uso:
  * @include prueba_sp.cpp
  *
  * @author Manuel Jiménez Bernal
  * @date Octubre 2017
  */
class Sopa_letras{
	/**
	* @page repConjunto Rep del TDA Sopa de letras
	*
	* @section invConjunto Invariante de la representación
	*
	* El invariante es \e rep.matriz.size() > 0
	*
	* @section faConjunto Función de abstracción
	*
	* Un objeto válido @e rep del TDA Sopa de letras representa a la estructura
	* 
	* rep.matriz[<0,0,'V'>,<0,1,'A'>..<i,j,'*'>]
	*
	*/
	private:
		string titulo;
		Matriz_Dispersa<char> matriz;
		Matriz_Dispersa<bool> acertadas;
		VD<string> palabras;
		VD<string> palabras_acertadas;

	public:
		Sopa_letras();

		int NumPalabras() { return palabras.size(); }
		int size() { return matriz.size(); }
		int getMaxCol() { return matriz.getMaxCol(); }
		int getNumCols() { return matriz.getNumCols(); }
		char getPrimerCaracter() { return matriz.Get(7,7); }
		bool Comprobar_Palabra(string palabra,int i,int j,string dir);
		void Poner_Acertada(string palabra,int i,int j,string dir){ palabras_acertadas.set(palabra); }
		bool checkPalabraEnLista(string palabra);
		friend ostream & operator<<(ostream & s, Sopa_letras & sopa){
			if(sopa.matriz.getMinCol() < 0 or sopa.matriz.getMinCol() > 9)
				s << "    ";
			else 
				s << "     ";
			for(int i=sopa.matriz.getMinCol();i<=sopa.matriz.getMaxCol();i++){
				if(i<10 || i<0)
					s << i << "  ";
				else
					s << i << " ";
			}
			s << '\n';
			for(int i=sopa.matriz.getMinFila();i<=sopa.matriz.getMaxFila();i++){
				if(i < 0 || i > 9)
					s << "|" << i << "|";
				else
					s << "| " << i << "|";
				//cout << "mincol " << sopa.matriz.getMinCol() << endl;
				for(int j=sopa.matriz.getMinCol();j<=sopa.matriz.getMaxCol();j++){
					if(sopa.matriz.Get(i,j) != sopa.matriz.getValorDefecto()){
						if(sopa.acertadas.Get(i,j) == false)
							s << "\e[0m" << " " << sopa.matriz.Get(i,j) << " " ;
						else
							s << "\e[1m" << " " << sopa.matriz.Get(i,j) << " "  << "\e[0m";
					} else {
						s << "\e[1m" << " " << "X" << " " << "\e[0m";
					}
				}		
				s << '\n';
			}
			return s;
		}

		friend istream & operator>>(istream & is, Sopa_letras & sopa) {
			string titulo;
			getline(is, titulo);
			string line;
			while (std::getline(is, line))
			{
			    istringstream iss(line);
			    int i, j;
			    string dir,palabra;
			   
			    if (!(iss >> i >> j >> dir >> palabra)) { break; } // error
			    cout << "!! " << palabra << " i:" << i << endl;
			    char * palabra_char = new char[palabra.length() + 1];
				strcpy(palabra_char, palabra.c_str());
				bool puedeInsertarse=true;
			    sopa.palabras.set(palabra);
			    if(dir == "hi"){ // horizontal izquierda
			    	int inc = j;
			    	for (unsigned int index=0;index<palabra.length();index++,inc--){
	    				if(sopa.matriz.Get(i,inc) != sopa.matriz.getValorDefecto() and sopa.matriz.Get(i,inc) != palabra_char[index]){
	    					puedeInsertarse=false;
	    				}
			    	}
			    	if(puedeInsertarse)
					    for (unsigned int index=0;index<palabra.length();index++,j--){
		    				sopa.matriz.Set(i,j,palabra_char[index]);
					    }
				}
			    else if (dir == "hd"){ // horizontal derecha
			    	int inc=j;
			    	for (unsigned int index=0;index<palabra.length();index++,inc++){
	    				if(sopa.matriz.Get(i,inc) != sopa.matriz.getValorDefecto() and sopa.matriz.Get(i,inc) != palabra_char[index]){
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
	    				if(sopa.matriz.Get(inc,j) != sopa.matriz.getValorDefecto() and sopa.matriz.Get(inc,j) != palabra_char[index]){
	    					puedeInsertarse=false;
	    				}
			    	}
			    	if(puedeInsertarse)
				    	for (unsigned int index=0;index<palabra.length();index++,i--){
		    				sopa.matriz.Set(i,j,palabra_char[index]);
				    	}
			    }
    			else if (dir == "vd"){ // vertical abajo
    				int inc = i;
    				for (unsigned int index=0;index<palabra.length();index++,inc++){
	    				if(sopa.matriz.Get(inc,j) != sopa.matriz.getValorDefecto() and sopa.matriz.Get(inc,j) != palabra_char[index] and sopa.matriz.Get(inc,j) != '\0'){
	    					puedeInsertarse=false;
	    				}
			    	}
			    	if(puedeInsertarse)
				    	for (unsigned int index=0;index<palabra.length();index++,i++){
		    				sopa.matriz.Set(i,j,palabra_char[index]);
				    	}
			    }
    			else if (dir == "dd"){ // diagonal abajo derecha
    				int inci = i;
    				int incj = j;
    				for (unsigned int index=0;index<palabra.length();index++,inci++,incj++){
	    				if(sopa.matriz.Get(inci,incj) != sopa.matriz.getValorDefecto() and sopa.matriz.Get(inci,incj) != palabra_char[index]){
	    					puedeInsertarse=false;
	    				}
			    	}
			    	if(puedeInsertarse)
				    	for (unsigned int index=0;index<palabra.length();index++,i++,j++){
		    				sopa.matriz.Set(i,j,palabra_char[index]);
				    	}
			    }
    			else if (dir == "di"){ // diagonal abajo izquierda
    				int inci = i;
    				int incj = j;
    				for (unsigned int index=0;index<palabra.length();index++,inci++,incj--){
	    				if(sopa.matriz.Get(inci,incj) != sopa.matriz.getValorDefecto() and sopa.matriz.Get(inci,incj) != palabra_char[index]){
	    					puedeInsertarse=false;
	    				}
			    	}
			    	if(puedeInsertarse)
				    	for (unsigned int index=0;index<palabra.length();index++,i++,j--){
		    				sopa.matriz.Set(i,j,palabra_char[index]);
				    	}
			    }
				delete[] palabra_char;

			}

		    return is;
		}
};


#include "../src/sopa_letras.cpp"
#endif