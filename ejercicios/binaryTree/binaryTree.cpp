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
      Iguales(nodo1->hijoIzq,nodo2->hijoIzq) && Iguales(nodo1->hijoDer,nodo2->hijoDer);
    } else
    return false;
  }
}

template <class T>
void ArbolBinario<T>::InsertarHijoIzquierda(info_nodo * nodo, info_nodo * & sub){
  info_nodo * aux = nodo->hijoIzq;
  if (sub != 0) {
    nodo->hijoIzq = sub;
    BorrarInfo(aux);
    nodo->hijoIzq->padre = nodo;
    sub = 0;
  } else {
    nodo->hijoIzq = 0;
    BorrarInfo(aux);
  }
}

template <class T>
void ArbolBinario<T>::InsertarHijoIzquierda(info_nodo * nodo, const T & et){
  info_nodo * aux = new info_nodo(et);
  InsertarHijoIzquierda(nodo,aux);
}

template <class T>
void ArbolBinario<T>::InsertarHijoDerecha(info_nodo * nodo, info_nodo * & sub) {
  info_nodo * aux = nodo->hijoDer;
  if (sub != 0) {
    nodo->hijoDer = sub;
    BorrarInfo(aux);
    nodo->hijoDer->padre = nodo;
    sub = 0;
  } else {
    nodo->hijoDer = 0;
    BorrarInfo(aux);
  }
}

template <class T>
void ArbolBinario<T>::InsertarHijoDerecha(info_nodo * nodo, const T & et) {
  info_nodo * aux = new info_nodo(et);
  InsertarHijoDerecha(nodo,aux);
}

template <class T>
void ArbolBinario<T>::PodarHijoIzquierda(info_nodo * nodo) {
  if(nodo->hijoIzq != 0) {
    BorrarInfo(nodo->hijoIzq);
    nodo->hijoIzq = 0;
  }
}

template <class T>
void ArbolBinario<T>::PodarHijoDerecha(info_nodo * nodo) {
  if(nodo->hijoDer != 0) {
    BorrarInfo(nodo->hijoDer);
    nodo->hijoDer = 0;
  }
}

template <class T>
typename ArbolBinario<T>::info_nodo ArbolBinario<T>::PodarHijoIzquierda_GetSubTree(info_nodo * nodo) {
  info_nodo * aux = nodo->hijoIzq;
  nodo->hijoIzq = 0;
  if(aux != 0) {
    aux->padre = 0;
  }
  return aux;
}
