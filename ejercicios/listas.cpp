#include <iostream>
#include <list>
#include <vector>
using namespace std;

bool sumaigual(list< list<int> > lista){

  list< list<int> >::iterator ite;
  vector<int> vectorFil;
  vector<int> vectorCol(4);
  int comprobacion = 0;
  bool resultado = true;
  bool flag = false;
  int i = 0;
  for(ite = lista.begin(); ite!=lista.end(); ++ite){
    list<int>::iterator itc;
    int sum = 0;
    int j = 0;
    for(itc = (*ite).begin(); itc !=(*ite).end(); ++itc){
      // suma una fila
      sum+=(*itc);
      int aux = vectorCol[j];
      vectorCol[j] = (*itc+aux);
      j++;
    }
    vectorFil.push_back(sum);
    ++i;
  }
  return resultado;
}

int main(){

  list< list<int> > myList;
  list<int> a;
  list<int> b;
  list<int> c;
  list<int> d;

  a.push_back(0);
  a.push_back(1);
  a.push_back(1);
  a.push_back(1);

  b.push_back(2);
  b.push_back(1);
  b.push_back(0);
  b.push_back(0);

  c.push_back(1);
  c.push_back(0);
  c.push_back(2);
  c.push_back(0);

  d.push_back(5);
  d.push_back(1);
  d.push_back(0);
  d.push_back(2);

  myList.push_back(a);
  myList.push_back(b);
  myList.push_back(c);
  myList.push_back(d);

  bool resultado = sumaigual(myList);
  cout << "el resultado " << resultado << endl;
  return 0;

}
