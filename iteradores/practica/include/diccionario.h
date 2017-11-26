#ifndef _DICCIONARIO_H_
#define _DICCIONARIO_H_
#include "./matriz_dispersa.h"
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

/**
  *  @brief T.D.A. Diccionario
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
class Diccionario{
	/**
	* @page repConjunto Rep del TDA Diccionario
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
	map<string,vector<string> > diccionario;

	public:
		class iterator;
		class iterator{
		private:
			map<string,vector<string> >::iterator it;
		public:
			iterator(){};
			pair<string,vector<string> > & operator*(){
				return *it;
			}

			friend class Diccionario;
		};
		iterator ite;
		/**
		* @brief Constructor
		* Crea un objeto de la clase Sopa de letras 
		*/
		Diccionario();
		iterator begin(){
			iterator i;
			i.it=diccionario.begin();
			return i;
		}

};


#include "../src/diccionario.cpp"
#endif