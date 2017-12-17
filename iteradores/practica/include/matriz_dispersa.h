/**
  * @file matriz_dispersa.h
  * @brief Fichero cabecera del TDA Matriz Dispersa
  *
  */

#ifndef _MATRIZ_DISPERSA_H
#define _MATRIZ_DISPERSA_H
#include <list>
#include <iostream>
using namespace std;
template <class T>

/**
  *  @brief T.D.A. Matriz Dispersa
  *
  * Una instancia @e c del tipo de datos abstracto @c Matriz Dispersa es un array 1-d de tripletas
  * formadas por: una fila, columna y un valor asociado.
  * Se representa:
  *
  * [{fila1,columna1,valor1},...,{filaN,columnaN,valorN}]
  *
  * Un ejemplo de su uso:
  * @include prueba.cpp
  *
  * @author Manuel Jiménez Bernal
  * @date Diciembre 2017
  */
class Matriz_Dispersa{

	/**
	* @page repConjunto Rep del TDA Matriz Dispersa
	*
	* @section invConjunto Invariante de la representación
	*
	* El invariante es \e rep.tripleta!=0
	*
	* @section faConjunto Función de abstracción
	*
	* Un objeto válido @e rep del TDA Matriz Dispersa representa a la estructura
	*
	* rep.m[<0,0,'A'>,<0,1,'B'>..<i,j,'*'>]
	*
	*/

	private:
		struct tripleta{
			int fila,col;
			T d;
		}; /**< estructura */

		list<tripleta> theList; /**< vector 1d */
		typename list<tripleta>::iterator it; /**< iterator  */
		char valor_defecto; /**< valor por defecto */
	public:
		/**
		* @brief Constructor por defecto
		* Crea un objeto de la clase Matriz Dispersa con valor por defecto '0'
		*/
		Matriz_Dispersa<T>();
		/**
		* @brief Coloca un elemento en la fila i y columna j
		* @param i fila
		* @param j columna
		*/
		void Set(int i,int j,T dato);
		/**
		* @brief Obtiene un elemento de una posición
		* @param i fila
		* @param j columna
		* @return Devuelve el objeto por copia
		*/
		T Get(int fil, int co);
		/**
		* @brief Dimensiona el tamaño del vector 1d
		* @param tam nuevo tamaño
		* @pre n debe ser mayor o igual que 0
		*/
		void resize(int tam){ theList.resize(tam); }
		/**
		* @brief Devuelve el numero de elementos que haya en el vector
		*/
		int size(){ return theList.size(); }
		/**
		* @brief Devuelve el valor por defecto
		*/
		const char getValorDefecto() const { return valor_defecto; }
		/**
		* @brief Proporciona el valor por defecto
		* @param car nuevo valor por defecto
		*/
		void setValorDefecto(const char & car) { valor_defecto=car; }
		/**
		* @brief Devuelve la menor columna
		*/
		int getMinCol();
		/**
		* @brief Devuelve la máxima columna
		*/
		int getMaxCol();
		/**
		* @brief Devuelve la menor fila
		*/
		int getMinFila();
		/**
		* @brief Devuelve la máxima fila
		*/
		int getMaxFila();
		/**
		* @brief Devuelve el número de filas
		*/
		int getNumFilas();
		/**
		* @brief Devuelve el número de columnas
		*/
		int getNumCols();
};


#include "../src/matriz_dispersa.cpp"
#endif
