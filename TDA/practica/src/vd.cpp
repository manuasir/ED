
// constructor por defecto
template <class T>
VD<T>::VD(int tam) {
	//assert(n>=0);
	if(tam>0)
		datos = new T[tam];
	else
		datos=0;
	reservados = tam;
}

// constructor de copias
template <class T>
VD<T>::VD(const VD<T>& original) {
	//assert(n>=0);
	n=original.n;
	if(n>0){
		datos = new T[n];
		for(int i=0;i<n;i++){
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
	if(n>0){
		delete[] datos;
		n=0;
	}
}

// operador de asignación
template <class T>
VD<T> & VD<T>::operator=(const VD<T> & original) {
	if(this!=&original){
		if(n>0) delete[] datos;
		n=original.n;
		if(n>0){
			datos=new T[n];
			for(int i=0;i<n;++i)
				datos[i]=original.datos[i];
		}
	
		else datos=0;
	}	 
	return *this;
}
