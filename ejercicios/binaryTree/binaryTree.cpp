template <class T>
void ArbolBinario<T>::Copiar(info_nodo * & origen, const info_nodo * & destino){
  if(origen == 0) {
    destino = 0;
  } else {
    destino = new info_nodo(origen->etiqueta);
    Copiar(origen->hijoIzq, destino->hijoIzq);
    Copiar(origen->hijoDer, destino->hijoDer);
    if (destino->hijoIzq != 0) {
      destino->hijoIzq->padre = destino;
    }
    if (destino->hijoDer != 0) {
      destino->hijoDer->padre = destino;
    }
  }
}

template <class T>
void ArbolBinario<T>::BorrarInfo(info_nodo * & nodo){
  if(nodo != 0) {
    BorrarInfo(nodo->hijoIzq);
    BorrarInfo(nodo->hijoDer);
    delete nodo;
  }
}

template <class T>
int ArbolBinario<T>::NumeroNodos(const info_nodo * nodo)const{
  if(nodo == 0)
    return 0;
  else {
    return NumeroNodos(nodo->hijoIzq) + NumeroNodos(nodo->hijoDer)+1;
  }
}

template <class T>
bool ArbolBinario<T>::Iguales(const info_nodo * nodo1, const info_nodo * nodo2)const{
  if(nodo1 == 0  and nodo2 == 0)
    return true;
  if(nodo1 == 0  or nodo2 == 0)
    return false;
  else {
    if (nodo1->etiqueta == nodo2->etiqueta) {
       Iguales(nodo1->hijoIzq,nodo2->hijoIzq) && (nodo1->hijoDer,nodo2->hijoDer);
    } else
      return false;
  }
}
