
// constructor por defecto
template <class T>
VD<T>::VD(int tam) {
	//assert(n>=0);
	//cout << "tam " << tam << endl;
	if(tam>0)
		datos = new T[tam];
	else
		datos=0;
	reservados = tam;
}

// constructor de copias
template <class T>
VD<T>::VD( const VD<T>& original ) {
	//assert(n>=0);
	reservados=original.reservados;
	if(reservados>0){
		datos = new T[reservados];
		for(int i=0;i<reservados;i++){
			datos[i]=original.datos[i];
		}
	}
	else
		datos=0;
}

// destructor
template <class T>
VD<T>::~VD() {
	//assert(n>=0);
	if(reservados>0){
		delete[] datos;
		reservados=0;
	}
}

// operador de asignación
template <class T>
VD<T> & VD<T>::operator=(const VD<T> & original) {
	if(this!=&original){
		if(reservados>0) delete[] datos;
		reservados=original.reservados;
		if(reservados>0){
			datos=new T[reservados];
			for(int i=0;i<reservados;++i)
				datos[i]=original.datos[i];
		}
	
		else datos=0;
	}	 
	return *this;
}