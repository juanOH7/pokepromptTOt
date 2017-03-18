#pragma once
#include <string>
#include "pagina.h"

using std::string;

class arbolb{
	pagina root;
public:
	arbolb(pagina);
	pagina getroot();
	void setroot(pagina);
	void refresh();
	void agregar(pagina,bool);
	void eliminar(int);
	string tostring();

};
