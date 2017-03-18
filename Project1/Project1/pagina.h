#pragma once
#include <string>
#include "nodo.h"

using std::string;

class pagina{
	nodo arreglo[3];
	pagina* padre;
	pagina* izq;
	pagina* med;
	pagina* der;
	pagina* temp;
public:
	pagina(nodo);
	pagina();
	void setpadre(pagina*);
	void setizq(pagina*);
	void setmed(pagina*);
	void setder(pagina*);
	pagina* getpadre();
	pagina* getizq();
	pagina* getmed();
	pagina* getder();
	nodo get0();
	nodo get1();
	void agregar(pagina,bool);
	void eliminar(int);
	string tostring();
};
