#ifndef _DICCIONARIO_H_
#define _DICCIONARIO_H_
#include "./matriz_dispersa.h"
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
*  @brief T.D.A. Diccionario
*
* Una instancia @e c del tipo de datos abstracto @c Diccionario contiene un conjunto clave-valor de palabras
* con sus significados asociados.
* Se representa:
*
* key : [values]
*
* Un ejemplo de su uso:
* @include pruebadiccionario.cpp
*
* @author Manuel Jiménez Bernal
* @date Diciembre 2017
*/
class Diccionario{

	/**
	* @page repConjunto Rep del TDA Diccionario
	*
	* @section invConjunto Invariante de la representación
	*
	* El invariante es \e rep.diccionario.size() > 0
	*
	* @section faConjunto Función de abstracción
	*
	* Un objeto válido @e rep del TDA Diccionario representa a la estructura
	*
	* rep.diccionario[key] = [value1,value2,...,valueN]
	*
	*/

private:
	map<string,vector<string> > diccionario; /**< el mapa en que se almacena el diccionario */
public:
	/**
	* @brief Constructor
	* Crea un objeto de la clase Diccionario
	*/
	Diccionario(){};

	class iterator; /**< pre-declaración de la clase iteradora sobre el diccionario */

	/**
	* @brief Devuelve la primera palabra del Diccionario
	* @return iterator devuelve una instancia de iterador de la clase Diccionario
	*/
	iterator begin(){
		iterator i;
		i.it=diccionario.begin();
		return i;
	}
	/**
	* @brief Devuelve la última palabra del diccionario
	* @return iterator devuelve una instancia de iterador de la clase Diccionario
	*/
	iterator end(){
		iterator i;
		i.it=diccionario.end();
		return i;
	}

	/**
	* @brief Inserta una nueva palabra con su significado, si existiera añade un nuevo significado a esa clave
	*/
	void set(string key,string value){
		diccionario[key].push_back(value);
	}

	/**
	* @brief Devuelve significados
	* @param key la palabra de la cual se quiere extraer los significados
	* @return devuelve los significados de esa palabra
	*/
	vector<string> get(string key){
		return diccionario[key];
	}
	/**
	* @brief Crea un diccionario a partir de otro
	* @param key la palabra de la cual se quiere generar un diccionario
	* @return nuevo diccionario
	*/
	Diccionario ObtainPalabrasconDeficionContiene(string key);
	//class iterator;
	class iterator{
		private:
			map<string,vector<string> >::iterator it;
		public:
			iterator(){};
			pair<string,vector<string>> operator*(){ return *it; }
			iterator & operator++(){ ++it; return *this; }
			bool operator!=(const iterator & i){ return i.it!=it; }
			bool operator==(const iterator & i){ return i.it==it; }
			friend class Diccionario;
	};

	/**
	* @brief Sobrecarga del operador <<
	* Imprime el diccionario
	* @param s el flujo de salida
	* @param diccionario la referencia al objeto que llama al método
	*/
	friend ostream & operator<<(ostream & s, Diccionario & diccionario){
		Diccionario::iterator ite;
		for(ite=diccionario.begin();ite!=diccionario.end();++ite){
			s << "palabra: " << (*ite).first << endl;
			for(int i = 0;i<int((*ite).second.size());i++){
				s << "definición : " << (*ite).second[i] << endl;
			}
		}
		return s;
	}

	/**
	* @brief Sobrecarga del operador >>
	* Lee el diccionario a partir de un fichero.
	* @param is el flujo de entrada
	* @param diccionario la referencia al objeto que llama al método
	*/
	friend istream & operator>>(istream & is, Diccionario & diccionario) {
		string line;
		while (getline(is, line)) {
			string palabra = line.substr(0, line.find(';'));
			string definicion = line.substr(line.find(';')+1, line.size());
			diccionario.set(palabra,definicion);
		}
		return is;
	}
};

#include "../src/diccionario.cpp"
#endif
