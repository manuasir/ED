#include <cstring>
#include <fstream>
#include <list>
#include <stdlib.h>
#include "../include/sopa_letras.h"
#include "../include/diccionario.h"


list<string> extraerPalabras(Diccionario &D){
  Diccionario::iterator it;
  list<string> palabras;
  for (it=D.begin(); it!=D.end();++it){
    for(int i = 0;i<int((*it).second.size());i++){
      palabras.push_back( (*it).first);
    }
  }
  return palabras;
}

int main(int argc, char * argv[]){
  srand (time(NULL));
  if (argc!=4){
    cout<<"Dime el nombre del fichero con las palabras de la sopa de letras, el tema y el número máximo de palabras"<<endl;
    return 0;
  }
  ifstream f(argv[1]);
  if (!f){
    cout<<"No puedo abrir "<<argv[1]<<endl;
    return 0;
  }

  Sopa_letras Sl;
  Diccionario T;
  string word(argv[2]);
  int maxPalabras = atoi(argv[3]);
  int indiceActual = 0;
  f>>T; //Cargamos en memoria el diccionario

  Diccionario Dtema = T.ObtainPalabrasconDeficionContiene(word);
  Diccionario::iterator it;
  list<string> palabras = extraerPalabras(Dtema);
  list<string>::iterator listIterator;
  //int fila,columna,maxPalabras;

  for(listIterator=palabras.begin();listIterator!=palabras.end() and indiceActual<maxPalabras;++listIterator){
    cout << "una palabra: " << (*listIterator) << endl;
    string dir;
    int randomDir = rand()%5;
    switch(randomDir){
      case 0: dir = "vd"; break;
      case 1: dir = "vu"; break;
      case 2: dir = "hd"; break;
      case 3: dir = "hi"; break;
      case 4: dir = "dd"; break;
      case 5: dir = "di"; break;
    }
    Sl.addPalabra(5,5,(*listIterator),dir);
    indiceActual++;
  }
  //El usuario ahora tiene que ir descubriendo las palabras
  //en la sopa de letras
  while (Sl.NumPalabras()!=0){
    cout<<Sl<<endl;
    string pal;
    cout<<"Dime una palabra :";
    cin>>pal;
    cout<<"Dime la fila :";
    int row;
    cin>>row;
    cout<<"Dime la columna :";
    int col;
    cin>>col;

    cout<<"Direccion Arriba (vu), Abajo (vd), Izquierda (hi) , Derecha (hd), Diagonal abajo derecha (dd),Diagonal abajo izquierda (di) :";

    string direccion;
    cin>>direccion;
    if (!Sl.Comprobar_Palabra(pal,row,col,direccion)){//Esta?
      cout<<"La palabra "<<pal << " no esta"<<endl;
    } else{
      cout << "bien!" << endl;
      //La pone en negrita. Ademas la pone dentro de la lista de palabras descubiertas.
      Sl.Poner_Acertada(pal,row,col,direccion);
    }
  }
}
