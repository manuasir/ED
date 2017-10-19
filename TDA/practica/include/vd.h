template <class T>
class VD{

private:
	T * datos;
	int n;
	int reservados;
	void resize(int nuevo_tam);
	void copiar(int nuevo_tam);
	void copiar(const VD<T> & v);
	void liberar();

public:
	VD(int tam=10);


};
#include "../src/vd.cpp"