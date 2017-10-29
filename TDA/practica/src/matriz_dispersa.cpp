
// constructor por defecto
template <class T>
Matriz_Dispersa<T>::Matriz_Dispersa() {
	valor_defecto='0';
}

template <class T>
void Matriz_Dispersa<T>::Set(int i,int j,T dato){
	cout << "seteando en fila: " << i << " columna: " << j << " valor: " << dato << endl;
	//cout << "max fila " << getMaxFila() << " max col: " << getMaxCol() << " valor: " << dato << endl;
	tripleta aux;
	aux.fila=i;
	aux.col=j;
	aux.d=dato;
	m.set(aux);
}

template <class T>
T Matriz_Dispersa<T>::Get(int fil,int co){
	T dato = valor_defecto;
	for(int i=0;i<m.size();++i){
		if(m[i].fila == fil && m[i].col == co){
			dato = m[i].d;
		}
	}
	return dato;
}

template <class T>
int Matriz_Dispersa<T>::getMinCol(){
	int minCol=m[0].col;
	for(int i=0;i<m.size();i++){
		if(m[i].col < minCol)
			minCol=m[i].col;
	}
	return minCol;
}

template <class T>
int Matriz_Dispersa<T>::getMaxCol(){
	int maxCol=m[0].col;
	for(int i=0;i<m.size();i++){
		if(m[i].col > maxCol){
			maxCol=m[i].col;
		}
	}
	return maxCol;
}

template <class T>
int Matriz_Dispersa<T>::getMaxFila(){
	int maxFila=m[0].fila;
	for(int i=0;i<m.size();i++){
		if(m[i].fila > maxFila)
			maxFila=m[i].fila;
	}
	return maxFila;
}

template <class T>
int Matriz_Dispersa<T>::getMinFila(){
	int minFila=m[0].fila;
	for(int i=0;i<m.size();i++){
		if(m[i].fila < minFila)
			minFila=m[i].fila;
	}
	return minFila;
}


template <class T>
int Matriz_Dispersa<T>::getNumFilas(){

	return getMaxFila()-getMinFila();
}

template <class T>
int Matriz_Dispersa<T>::getNumCols(){

	return getMaxCol()-getMinCol();
}