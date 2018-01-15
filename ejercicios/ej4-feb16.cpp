#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class Mapa {

  public:
    unordered_map<int,vector<int> > mapa;

    class Iterador;

    Mapa(){
      vector<int> vec;
      vec.push_back(2);
      vec.push_back(2);
      mapa[0]=vec;
      mapa[1]=vec;
      mapa[2]=vec;
      mapa[3]=vec;
      mapa[4]=vec;
      mapa[5]=vec;
      mapa[6]=vec;
    }

    class Iterador {
      private:
        unordered_map<int,vector<int> >::iterator ite;

      public:
        Iterador(){};
        pair<int, vector<int> > operator*(){ return *ite; }
        bool operator!=(Iterador it){ return it.ite!=ite; }
        unordered_map<int,vector<int> >::iterator operator++(){
          int sum = 0;
          int cont = 0;
          do {
            ++ite;
            ++cont;
            for(int i=0;i<(*ite).second.size();i++){
              sum+=(*ite).second[i];
            }
          }while(sum%2 == 0 and cont < 6);
          return ite;
        }
        friend class Mapa;
    };

    Iterador begin() {
      Iterador ite;
      ite.ite = mapa.begin();
      return ite;
    }

    Iterador end() {
      Iterador ite;
      ite.ite = mapa.end();
      return ite;
    }

};
int main(){
  Mapa miMapa;
  Mapa::Iterador ite;
  for(ite = miMapa.begin();ite!=miMapa.end();++ite) {
    cout << (*ite).first << endl;
  }
  return 0;

}
