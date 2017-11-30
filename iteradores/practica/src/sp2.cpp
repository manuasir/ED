#include <cstring>
#include <fstream>
#include <list>
#include "../include/sopa_letras.h"
#include "../include/diccionario.h"

list<string> extraerPalabras(Diccionario &D){
  Diccionario::iterator it;
  list<string> palabras;
  for (it=D.begin(); it!=D.end();++it){
    for(int i = 0;i<int((*it).second.size());i++){
      cout<<"una palabra: " << (*it).first<<endl;
    //  palabras.insert( (*it).first);
    }
  }
  return palabras;
}

int main(int argc, char * argv[]){

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
  cout<<"Dime una palabra: ";
  string word;
  cin>>word;
  f>>T; //Cargamos en memoria el diccionario

  Diccionario Dtema = T.ObtainPalabrasconDeficionContiene(word);
  Diccionario::iterator it;
  list<string> palabras = extraerPalabras(Dtema);

  //El usuario ahora tiene que ir descubriendo las palabras
  //en la sopa de letras
  while (Sl.NumPalabras()!=0){
    cout<<Sl<<endl;

    cout<<"Dime la fila :";
    int row;
    cin>>row;
    cout<<"Dime la columna :";
    int col;
    cin>>col;

    cout<<"Direccion Arriba (vu), Abajo (vd), Izquierda (hi) , Derecha (hd), Diagonal abajo derecha (dd),Diagonal abajo izquierda (di) :";

    string direccion;
    cin>>direccion;
    if (!Sl.Comprobar_Palabra(word,row,col,direccion)){//Esta?
      cout<<"La palabra "<<word << " no esta"<<endl;
    } else{
      cout << "bien!" << endl;
      //La pone en negrita. Ademas la pone dentro de la lista de palabras descubiertas.
      Sl.Poner_Acertada(word,row,col,direccion);
    }
  }
}
