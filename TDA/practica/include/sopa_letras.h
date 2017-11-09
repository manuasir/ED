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
		string titulo; /**< el título de la sopa de letras */
		Matriz_Dispersa<char> matriz; /**< la matriz dispersa */
		Matriz_Dispersa<bool> acertadas; /**< mapa espejo para controlar las compatibilidades y acertadas */
		VD<string> palabras; /**< las palabras cargadas */
		VD<string> palabras_acertadas; /**< las palabras acertadas */
		int nAcertadas; /**< el número de acertadas */
		int nPendientes; /**< el número de pendientes */

	public:
		/**
		* @brief Constructor
		* Crea un objeto de la clase Sopa de letras 
		*/
		Sopa_letras();
		/**
		* @brief Obtiene el numero total de palabras cargadas al inicio
		*/
		int NumPalabras() { return palabras.size(); }
		/**
		* @brief Obtiene el tamaño total de la matriz
		*/
		int size() { return matriz.size(); }

		/**
		* @brief Obtiene el titulo
		*/
		string getTitulo() { return titulo; }
		
		/**
		* @brief Obtiene la mayor columna
		*/
		int getMaxCol() { return matriz.getMaxCol(); }
		/**
		* @brief Obtiene el total de columnas
		*/
		int getNumCols() { return matriz.getNumCols(); }
		/**
		* @brief Obtiene el total de columnas
		*/
		int getNumAcertadas() { return nAcertadas; }
		/**
		* @brief Obtiene el total de columnas
		*/
		int getNumAPendientes() { return nPendientes; }
		/**
		* @brief Comprueba si ha acertado una palabra
		* @param palabra La palabra que se quiere comprobar
		* @param i la fila en la que empieza
		* @param j la columna en la que empieza
		* @param dir la dirección en que debe leerse
		*/
		bool Comprobar_Palabra(string palabra,int i,int j,string dir);
		/**
		* @brief Incluir una palabra en la lista de acertadas
		* @param palabra La palabra a incluir
		*/
		void Poner_Acertada(string palabra,int i,int j,string dir){ palabras_acertadas.set(palabra); }		/**
		* @brief Comprueba que la sucesión de letras que ha introducido corresponde a una palabra de la lista
		* @param palabra La palabra que se quiere comprobar
		*/
		bool checkPalabraEnLista(string palabra);

		/**
		* @brief Sobrecarga del operador <<
		* Imprime la sopa de letras
		* @param s el flujo de salida
		* @param sopa la referencia al objeto que llama al método
		*/
		friend ostream & operator<<(ostream & s, Sopa_letras & sopa){
			if(sopa.matriz.getMinCol() < 0 or sopa.matriz.getMinCol() > 9)
				s << "    ";
			else 
				s << "     ";

			s << "Titulo: " << sopa.getTitulo() << " Numero de palabras ocultas " << sopa.palabras.size() << " Palabras descubiertas" << sopa.getNumAcertadas() << '\n';
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

		/**
		* @brief Sobrecarga del operador >>
		* Lee la sopa de letras a partir de un fichero. Comprueba que todas las palabras son aptas para introducir.
		* Esto significa que si dos palabras se cruzan, ha de ser por una letra en común.
		* @param is el flujo de entrada
		* @param sopa la referencia al objeto que llama al método
		*/
		friend istream & operator>>(istream & is, Sopa_letras & sopa) {
			getline(is, sopa.titulo);
			string line;
			while (std::getline(is, line))
			{
			    istringstream iss(line);
			    int i, j;
			    string dir,palabra;
			   
			    if (!(iss >> i >> j >> dir >> palabra)) { break; } // error
			    //cout << "!! " << palabra << " i:" << i << endl;
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
			    	if(puedeInsertarse){
				    	for (unsigned int index=0;index<palabra.length();index++,i++,j--){
		    				sopa.matriz.Set(i,j,palabra_char[index]);
				    	}
				    	
				    }
			    }
				delete[] palabra_char;

			}

		    return is;
		}
};


#include "../src/sopa_letras.cpp"
#endif