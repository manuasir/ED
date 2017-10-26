
//Este fichero te permite probar el modulo vector dinámico

#include "vd.h"
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	
	VD<int> p(100);
	VD<int> p2(5);
	std::cout << "creado p1 " << p.size() <<std::endl;
	std::cout << "creado p2 " << p2.size() <<std::endl;
	for(int i=0;i<p.size();++i){
		p[i]=i;
	}
	cout << "tamaño de p2 " << p2.size() << endl;
	p2=p;
	cout << "tamaño de p2 " << p2.size() << endl;


	return 0;
}     