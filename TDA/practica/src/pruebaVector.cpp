
//Este fichero te permite probar el modulo vector dinámico

#include "vd.h"
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	

	VD<int> p(20);
	VD<int> p2(5);
	std::cout << "creado p1 " << p.size() <<std::endl;
	std::cout << "creado p2 " << p2.size() <<std::endl;
	for(int i=0;i<p.size();++i){
		p[i]=i;
	}
	cout << "tamaño de p2 debe ser 5 :" << p2.size() << endl;
	p2=p;
	cout << "tamaño de p2 debe ser 20 :" << p2.size() << endl;
	cout << "tamaño de reservados debe ser 20 :" << p2.getReservados() << endl;
	cout << "en posicion 15 de p2 debe ser 14 :" << p2[15] << endl;
	p2.set(15,666);
	cout << "tamaño de reservados debe ser 40 :" << p2.getReservados() << endl;

	cout << "en posicion 15 de p2  debe ser 666 :" << p2[15] << endl;
	cout << "tamaño de vector tras insercion debe ser 21 :" << p2.size() << endl;
	p2.resize(5);
	cout << "n despues de resize debe ser 5 :" << p2.size() << endl;
	cout << "reservados debe ser 5 :" << p2.getReservados() << endl;


	return 0;
}     