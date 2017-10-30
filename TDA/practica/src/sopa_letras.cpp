
Sopa_letras::Sopa_letras(){
	
}

bool Sopa_letras::Comprobar_Palabra(string palabra,int i,int j,string dir){
	char * palabra_char = new char[palabra.length() + 1];
	strcpy(palabra_char, palabra.c_str());
	bool comprobar=true;
    if(dir == "hi"){ // horizontal izquierda
    	int inc = j;
    	for (unsigned int index=0;index<palabra.length();index++,inc--){
	    	//cout << "llamando a setear " << endl;
			if(matriz.Get(i,inc) != palabra_char[index]){
				cout << "matriz.Get(i,inc) " << matriz.Get(i,inc) << " no es igual que " << palabra_char[index] << endl;
				comprobar=false;
			}
    	}
	}
    else if (dir == "hd"){ // horizontal derecha
    	int inc=j;
    	for (unsigned int index=0;index<palabra.length();index++,inc++){
	    	cout << "llamando a setear j:" << inc << endl;
			if(matriz.Get(i,inc) != palabra_char[index]){
				cout << "no puede insertarse " << palabra << endl;

				comprobar=false;
			}
    	}
    }
	else if (dir == "vu"){ // vertical arriba
		int inc = i;
		for (unsigned int index=0;index<palabra.length();index++,inc--){
	    	//cout << "llamando a setear " << endl;
			if(matriz.Get(inc,j) != palabra_char[index]){
				cout << "matriz.Get(i,inc) " << matriz.Get(inc,j) << " no es igual que " << palabra_char[index] << endl;
				comprobar=false;
			}
    	}
    }
	else if (dir == "vd"){ // vertical abajo
		int inc = i;
		for (unsigned int index=0;index<palabra.length();index++,inc++){
	    	//cout << "llamando a setear " << endl;
			if(matriz.Get(inc,j) != palabra_char[index]){
				cout << "matriz.Get(i,inc) " << matriz.Get(inc,j) << " no es igual que " << palabra_char[index] << endl;
				comprobar=false;
			}
    	}
    }
	else if (dir == "dd"){ // diagonal abajo derecha
		int inci = i;
		int incj = j;
		for (unsigned int index=0;index<palabra.length();index++,inci++,incj++){
	    	//cout << "llamando a setear " << endl;
			if(matriz.Get(inci,incj) != palabra_char[index]){
				cout << "no puede insertarse " << palabra << endl;
				comprobar=false;
			}
    	}
    }
	else if (dir == "di"){ // diagonal abajo izquierda
		int inci = i;
		int incj = j;
		for (unsigned int index=0;index<palabra.length();index++,inci++,incj--){
	    	//cout << "llamando a setear " << endl;
			if(matriz.Get(inci,incj) != palabra_char[index]){
				cout << "no puede insertarse " << palabra << endl;
				comprobar=false;
			}
    	}
    }
    return comprobar;
}
