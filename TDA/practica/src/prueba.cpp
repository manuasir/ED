
//Este fichero te permite probar el modulo matriz dispersa.

#include "../include/matriz_dispersa.h"
#include <cstring>
#include <iostream>
using namespace std;
int main(){

  
 Matriz_Dispersa<char> P;
 int r,c;
 r=2;c=2;
 //La Ponemos horizontal

 const char * cad="hola";
 for (unsigned int i=0;i<strlen(cad);i++,c++)
     P.Set(r,c,cad[i]);
 r=2;c=2;
 
 for (unsigned int i=0;i<strlen(cad);i++,r++)
     P.Set(r,c,cad[i]);
cout<<P<<endl;
cout << P.getValorDefecto() << endl;
P.setValorDefecto('X');
cout << P.getValorDefecto() << endl;

}     