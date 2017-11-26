
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
	for(it = theList.begin();it!=theList.end();++it){
		//cout << "haciendo get de " << m.size() <<  endl;
		if((*it).fila == fil && (*it).col == co){
			dato = (*it).d;
		}
	}
	return dato;
}

template <class T>
int Matriz_Dispersa<T>::getMinCol(){
	it = theList.begin();
	int minCol=(*it).col;
	for(it = theList.begin();it!=theList.end();it++){
		if((*it).col < minCol)
			minCol=(*it).col;
	}
	return minCol;
}

template <class T>
int Matriz_Dispersa<T>::getMaxCol(){
	it = theList.begin();
	int maxCol=(*it).col;
	for(it = theList.begin();it!=theList.end();it++){
		if((*it).col > maxCol){
			maxCol=(*it).col;
		}
	}
	return maxCol;
}

template <class T>
int Matriz_Dispersa<T>::getMaxFila(){
	it = theList.begin();
	int maxFila=(*it).fila;
	for(it = theList.begin();it!=theList.end();it++){
		if((*it).fila > maxFila)
			maxFila=(*it).fila;
	}
	return maxFila;
}

template <class T>
int Matriz_Dispersa<T>::getMinFila(){
	it = theList.begin();
	int minFila=(*it).fila;
	for(it = theList.begin();it!=theList.end();it++){
		if((*it).fila < minFila)
			minFila=(*it).fila;
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
