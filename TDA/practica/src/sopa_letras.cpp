
Sopa_letras::Sopa_letras(){
	nAcertadas=0;
	nPendientes=0;
}

bool Sopa_letras::checkPalabraEnLista(string palabra){
	bool condicion=false;
	for(it=palabras.begin();it!=palabras.end();++it){
		if((*it) == palabra)
			condicion=true;
	}
	return condicion;
}

bool Sopa_letras::Comprobar_Palabra(string palabra,int i,int j,string dir){
	char * palabra_char = new char[palabra.length() + 1];
	strcpy(palabra_char, palabra.c_str());
	bool comprobar=true;
	int indiceUltimaAcertada = acertadas.size();
    if(dir == "hi"){ // horizontal izquierda
    	int inc = j;
    	for (unsigned int index=0;index<palabra.length();index++,inc--){
	    	acertadas.Set(i,inc,false);
			if(matriz.Get(i,inc) != palabra_char[index]){
				comprobar=false;
				acertadas.resize(indiceUltimaAcertada);
			}
    	}
	}
    else if (dir == "hd"){ // horizontal derecha
    	int inc=j;
    	for (unsigned int index=0;index<palabra.length();index++,inc++){
	    	acertadas.Set(i,inc,false);
			if(matriz.Get(i,inc) != palabra_char[index]){
				comprobar=false;
				acertadas.resize(indiceUltimaAcertada);
			}
    	}
    }
	else if (dir == "vu"){ // vertical arriba
		int inc = i;
		for (unsigned int index=0;index<palabra.length();index++,inc--){
	    	acertadas.Set(inc,j,false);
			if(matriz.Get(inc,j) != palabra_char[index]){
				comprobar=false;
				acertadas.resize(indiceUltimaAcertada);
			}
    	}
    }
	else if (dir == "vd"){ // vertical abajo
		int inc = i;
		for (unsigned int index=0;index<palabra.length();index++,inc++){
	    	acertadas.Set(inc,j,false);
			if(matriz.Get(inc,j) != palabra_char[index]){
				comprobar=false;
				acertadas.resize(indiceUltimaAcertada);
			}
    	}
    }
	else if (dir == "dd"){ // diagonal abajo derecha
		int inci = i;
		int incj = j;
		for (unsigned int index=0;index<palabra.length();index++,inci++,incj++){
	    	acertadas.Set(inci,incj,false);
			if(matriz.Get(inci,incj) != palabra_char[index]){
				comprobar=false;
				acertadas.resize(indiceUltimaAcertada);
			}
    	}
    }
	else if (dir == "di"){ // diagonal abajo izquierda
		int inci = i;
		int incj = j;
		for (unsigned int index=0;index<palabra.length();index++,inci++,incj--){
	    	acertadas.Set(inci,incj,false);
			if(matriz.Get(inci,incj) != palabra_char[index]){
				comprobar=false;
				acertadas.resize(indiceUltimaAcertada);
			}
    	}
    }
    
    if(comprobar){
    	cout << "comprobar es " << comprobar << endl;
    	if(!checkPalabraEnLista(palabra)){
    		cout << "no esta" << endl;
    		comprobar=false;
    		acertadas.resize(indiceUltimaAcertada);
    	} else {
    		nAcertadas++;
    		//nPendientes--;
    	}
    }
    	
    return comprobar;
}
