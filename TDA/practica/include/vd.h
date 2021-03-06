/**
  * @file vd.h
  * @brief Fichero cabecera del TDA Vector Dinámico
  *
  */

#ifndef _VD_H_
#define _VD_H_
#include <iostream>
using namespace std; 
template <class T>

/**
  *  @brief T.D.A. Vector Dinámico
  *
  * Una instancia @e c del tipo de datos abstracto @c Vector Dinámico es una 
  * sucesión de elementos almacenados y accesibles en memoria.
  * Se representa:
  *
  * datos[n] donde n > 0
  *
  * Un ejemplo de su uso:
  * @include pruebaVector.cpp
  *
  * @author Manuel Jiménez Bernal
  * @date Octubre 2017
  */

class VD{
	private:
		/**
		* @page repConjunto Rep del TDA Vector Dinámico
		*
		* @section invConjunto Invariante de la representación
		*
		* El invariante es \e rep.n>=0
		*
		* @section faConjunto Función de abstracción
		*
		* Un objeto válido @e rep del TDA Vector Dinámico representa a la estructura
		*
		* rep.datos[n]
		*
		*/
		T * datos; /**< estructura */
		int reservados; /**< cantidad de memoria reservada */
		int n; /**< cantidad de elementos en el vector */

		void copiar(const VD<T> & v);
		void liberar();

	public:
		/**
		* @brief Constructor por defecto
		* @param tam tamaño a reservar
		* @pre tam debe ser mayor de cero
		*/
		VD<T>(int tam=5);

		/**
		* @brief Constructor de copia
		* @param original objeto desde el cual crear el nuevo
		* @return Crea una nueva instancia
		*/
		VD<T>(const VD<T>& original);

		/**
		* @brief Destructor. Libera memoria.
		*/
		~VD<T>();

		/**
		* @brief Devuelve el numero de elementos que haya en el vector
		*/
		const int size() const { return n; }

		/**
		* @brief Devuelve la cantidad de memoria reservada
		*/
		const int getReservados() const { return reservados; }

		/**
		* @brief Sobrecarga del operador =
		* @param original objeto desde el cual crear el nuevo
		* @return Asigna el contenido de un vector en otro
		*/
		VD<T> & operator=(const VD<T> & original);

		/**
		* @brief Sobrecarga del operador []
		* @param i indice que se quiere obtener
		* @return Devuelve una constante por referencia del objeto
		* @pre i debe ser mayor que 0
		*/
		const T & operator[](int i) const { return datos[i]; }

		/**
		* @brief Sobrecarga del operador []
		* @param i indice que se quiere obtener
		* @return Devuelve el objeto por referencia
		* @pre i debe ser mayor que 0
		*/
		T & operator[](int i){ return datos[i]; }

		/**
		* @brief Añade un elemento al final del vector
		*/
		void set(T element);

		/**
		* @brief Coloca un elemento en la posición i
		* @param i posición en la que colocar el elemento
		* @pre i debe ser mayor que 0
		*/
		void set(int i,T element);

		/**
		* @brief Dimensiona el tamaño del vector
		* @param n nuevo tamaño
		* @pre n debe ser mayor o igual que 0
		*/
		void resize(int n);

};
#include "../src/vd.cpp"
#endif