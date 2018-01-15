#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include<iostream>
using namespace std;

template<class T>
class ArbolBinario{
private:
  struct info_nodo{
    T etiqueta;
    info_nodo * padre;
    info_nodo * hijoIzq;
    info_nodo * hijoDer;
    info_nodo(){ padre=hijoIzq=hijoDer=0; }
    info_nodo(const T & et){ etiqueta = et; padre=hijoIzq=hijoDer=0; }
  };

  info_nodo * raiz;
  void Copiar(info_nodo * & dest, const info_nodo * & origen);
  void BorrarInfo(info_nodo * & nodo);
  int NumeroNodos(const info_nodo * nodo)const;
  bool Iguales(const info_nodo * nodo1, const info_nodo * nodo2)const;
  void InsertarHijoIzquierda(info_nodo * nodo, info_nodo * & sub);
  void InsertarHijoIzquierda(info_nodo * nodo, const T & et);
  void InsertarHijoDerecha(info_nodo * nodo, info_nodo * & sub);
  void InsertarHijoDerecha(info_nodo * nodo, const T & et);
  void PodarHijoIzquierda(info_nodo * nodo);
  void PodarHijoDerecha(info_nodo * nodo);
  info_nodo PodarHijoIzquierda_GetSubTree(info_nodo * nodo);
  info_nodo * PodarHijoDerecha_GetSubTree(info_nodo * nodo);
  void RecorridoPostorden(ostream & os, const info_nodo * nodo)const;
  void RecorridoPreorden(ostream & os, const info_nodo * nodo)const;
  void RecorridoInorden(ostream & os, const info_nodo * nodo)const;
  void RecorridoNiveles(ostream & os, const info_nodo * nodo)const;
  void Lee(istream is, info_nodo * & nodo);
  void Escribe(ostream os, const info_nodo *  nodo)const;
public:
};
#include "binaryTree.cpp"

#endif
