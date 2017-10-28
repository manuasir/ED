
// constructor por defecto
template <class T>
Matriz_Dispersa<T>::Matriz_Dispersa() {
	valor_defecto='*';
}

template <class T>
void Matriz_Dispersa<T>::Set(int i,int j,T dato){
	tripleta aux;
	aux.fila=i;
	aux.col=j;
	aux.d=dato;
	m.set(aux);
}

