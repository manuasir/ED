
//Este fichero te permite probar el modulo vector dinámico

#include "vd.h"
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	
	VD<int> P(100);
	VD<int> P2(5);
	std::cout << "creado p1 " << P.size() <<std::endl;
	std::cout << "creado p2 " << P2.size() <<std::endl;
	for(int i=0;i<P.size();++i){
		P[i]=i;
	}
	for(int i=0;i<P.size();++i){
		cout << P[i] << endl;
	}
	cout << "tamaño de p2 " << P2.size() << endl;
	P2[0] = 1;

	return 0;
}     