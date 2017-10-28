
// constructor por defecto
template <class T>
Matriz_Dispersa<T>::Matriz_Dispersa() {
	tripleta defecto;
	defecto.fila=9999999;
	defecto.col=9999999;
	defecto.d='0';
	m.set(0,defecto);
	valor_defecto='0';
}

template <class T>
void Matriz_Dispersa<T>::Set(int i,int j,T dato){
	tripleta aux;
	aux.fila=i;
	aux.col=j;
	aux.d=dato;
	m.set(aux);
}

