
//Este fichero te permite probar el modulo matriz dispersa.

#include "../include/matriz_dispersa.h"
#include <cstring>
#include <iostream>
using namespace std;
int main(){
 Matriz_Dispersa<char> P;
 cout << "primer tamanño " << P.size() << endl;

 int r,c;
 r=2;c=2;
 //La Ponemos horizontal

 const char * cad="abcdefd";
 for (unsigned int i=0;i<strlen(cad);i++,c++)
     P.Set(r,c,cad[i]);
 r=2;c=2;

cout << P.getValorDefecto() << endl;
P.setValorDefecto('X');
cout << "valor por defecto " << P.getValorDefecto() << endl;
cout << "get min col " << P.getMinCol() << endl;
cout << "get max col " << P.getMaxCol() << endl;
cout << "get min fila " << P.getMinFila() << endl;
cout << "get max fila " << P.getMaxFila() << endl;
cout << "tamaño " << P.size() << endl;
P.Set(-1,15,'U');
cout << "get min col " << P.getMinCol() << endl;
cout << "get max col " << P.getMaxCol() << endl;
cout << "get min fila " << P.getMinFila() << endl;
cout << "get max fila " << P.getMaxFila() << endl;
cout << "tamaño " << P.size() << endl;
cout << "num filas " << P.getNumFilas() << endl;
cout << "num columnas " << P.getNumCols() << endl;
cout << "get at -1,15: " << P.Get(-1,15) << endl;
cout << "get at -1,15: " << P.Get(-1,15) << endl;
cout << "get at 2,2: " << P.Get(2,2) << endl;
cout << "get at 10,10: " << P.Get(10,10) << endl;

}     