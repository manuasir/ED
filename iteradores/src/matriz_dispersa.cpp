
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
	theList.push_back(aux);
}
template <class T>
T Matriz_Dispersa<T>::Get(int fil,int co){
	T dato = valor_defecto;
	for(it = theList.begin();it<theList.end();++it){
		//cout << "haciendo get de " << m.size() <<  endl;

		if(theList[it].fila == fil && theList[it].col == co){
			dato = theList[it].d;
		}
	}
	return dato;
}

template <class T>
int Matriz_Dispersa<T>::getMinCol(){
	it = theList.begin();
	int minCol=theList[it].col;
	for(it = theList.begin();it<theList.end();it++){
		if(theList[it].col < minCol)
			minCol=theList[it].col;
	}
	return minCol;
}
/*
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
*/