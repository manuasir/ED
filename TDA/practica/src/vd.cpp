
// constructor por defecto
template <class T>

VD<T>::VD(int tam) {
	if(tam>0)
		datos = new T[tam*2];
	else
		datos=0;
	reservados = tam;
	maximo=tam*2;
}

// constructor de copias
template <class T>
VD<T>::VD( const VD<T>& original ) {
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

// operador de cambiar el tamaño
template <class T>
void VD<T>::resize(int n) {
	if(n!=reservados){
		if(n!=0){
			T * nuevos_datos;
			nuevos_datos = new T[n];
			if(reservados>0){
				int minimo;
				minimo = reservados<n?reservados:n;
				for(int i=0;i<minimo;++i){
					nuevos_datos[i] = datos[i];
				}
				delete[] datos;
			}
			reservados=n;
			datos=nuevos_datos;
		} else {
			if(reservados>0)
				delete[] datos;
			datos=0;
			reservados=0;
		}
	}
}

template <class T>
void VD<T>::set(T element) {
	resize(reservados+1);
	datos[reservados-1] = element;
}