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
	/**
	* @brief Constructor
	* Crea un objeto de la clase Diccionario
	*/
	Diccionario(){};
	class iterator;

	iterator begin(){
		iterator i;
		i.it=diccionario.begin();
		return i;
	}

	iterator end(){
		iterator i;
		i.it=diccionario.end();
		return i;
	}

	void set(string key,string value){
		diccionario[key].push_back(value);
	}

	vector<string> get(string key){
		return diccionario[key];
	}

	Diccionario ObtainPalabrasconDeficionContiene(string key){
		Diccionario aux;
		iterator ite;
		for(ite=begin();ite!=end();++ite){
			for(int i = 0;i<int((*ite).second.size());i++){
				if ((*ite).second[i].find(key) != std::string::npos) {
					// cout << (*ite).second[i] << endl;
					aux.set((*ite).first,(*ite).second[i]);
				}
			}
		}
		return aux;
	}

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
	* Imprime la sopa de letras
	* @param s el flujo de salida
	* @param sopa la referencia al objeto que llama al método
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
	* Lee la sopa de letras a partir de un fichero. Comprueba que todas las palabras son aptas para introducir.
	* Esto significa que si dos palabras se cruzan, ha de ser por una letra en común.
	* @param is el flujo de entrada
	* @param sopa la referencia al objeto que llama al método
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
