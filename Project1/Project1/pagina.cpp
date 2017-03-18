#include "pagina.h"
#include "nodo.h"
#include <string>
#include <sstream>
#include <iostream>

using std::cout;
using std::stringstream;
using std::string;

pagina::pagina(nodo nuevo){
	arreglo[0] = nuevo;
	arreglo[1] = nodo();
	arreglo[2] = nodo();
	padre = NULL;
	izq = NULL;
	med = NULL;
	der = NULL;
	temp = NULL;
}
pagina::pagina(){
	padre = NULL;
	izq = NULL;
	med = NULL;
	der = NULL;
	temp = NULL;
}

nodo pagina::get0(){
	return arreglo[0];
}
nodo pagina::get1(){
	return arreglo[1];
}
void pagina::setpadre(pagina* nuevo){
	padre = nuevo;
}
void pagina::setizq(pagina* nuevo){
	izq = nuevo;
}
void pagina::setmed(pagina* nuevo){
	med = nuevo;

}
void pagina::setder(pagina* nuevo){
	der = nuevo;

}
pagina* pagina::getpadre(){
	return padre;
}
pagina* pagina::getizq(){
	return izq;
}
pagina* pagina::getmed(){
	return med;
}
pagina* pagina::getder(){
	return der;
}
void pagina::agregar(pagina nuevonodo ,bool validacion){
	nodo nuevo = nuevonodo.get0();
	if (nuevo.getkey() < arreglo[0].getkey() && izq != NULL &&validacion == true){
		izq->agregar(nuevonodo,true);
	}else if (nuevo.getkey() > arreglo[0].getkey() && med != NULL && validacion == true && arreglo[1].getkey() == -1){
		med->agregar(nuevonodo,true);
	}else if(nuevo.getkey() > arreglo[1].getkey() && der != NULL && validacion == true){
		der->agregar(nuevonodo,true);
	}else if(nuevo.getkey() > arreglo[0].getkey() && nuevo.getkey() < arreglo[1].getkey() && med != NULL && validacion == true){
		med->agregar(nuevonodo,true);
	}else if(nuevo.getkey() > arreglo[0].getkey() && arreglo[1].getkey() == -1){
		arreglo[1] = nuevo;
		med = nuevonodo.getizq();
		der = nuevonodo.getmed();
	}else if(nuevo.getkey() < arreglo[0].getkey() && arreglo[1].getkey() == -1){
		arreglo[1] = arreglo[0];
		arreglo[0] = nuevo;
		der = med;
		izq = nuevonodo.getizq();
		med = nuevonodo.getmed();
	}else{
		if(nuevo.getkey() < arreglo[0].getkey()){
			arreglo[2] = arreglo[1];
			arreglo[1] = arreglo[0];
			arreglo[0] = nuevo;
			temp = der;
			der = med;
			med = nuevonodo.getmed();
			izq = nuevonodo.getizq();
		}else if(nuevo.getkey() > arreglo[1].getkey()){
			arreglo[2] = nuevo;
			der = nuevonodo.getizq();
			temp = nuevonodo.getmed();
		}else if(nuevo.getkey() > arreglo[0].getkey() && nuevo.getkey() < arreglo[1].getkey()){
			arreglo[2] = arreglo[1];
			arreglo[1] = nuevo;
			temp = der;
			med = nuevonodo.getizq();
			der = nuevonodo.getmed();
		}
		//pagina izquierda = new pagina(arreglo[0]);
		//pagina derecha = new pagina(arreglo[2]);
		pagina medio(arreglo[1]);
		medio.setizq(new pagina(arreglo[0]));
		medio.setmed(new pagina(arreglo[2]));
		medio.getizq()->setpadre(&medio);
		medio.getizq()->setizq(izq);
		medio.getizq()->setmed(med);
		medio.getmed()->setpadre(&medio);
		medio.getmed()->setizq(der);
		medio.getmed()->setmed(temp);
		if(padre != NULL){
			padre->agregar(medio,false);
		}else{
			padre = new pagina(arreglo[1]);
			padre->setizq(new pagina(arreglo[0]));
			padre->setmed(new pagina(arreglo[2]));
			padre->getizq()->setpadre(&medio);
			padre->getizq()->setizq(izq);
			padre->getizq()->setmed(med);
			padre->getmed()->setpadre(&medio);
			padre->getmed()->setizq(der);
			padre->getmed()->setmed(temp);
		}
	}
}
void pagina::eliminar(int key){

}
string pagina::tostring(){
	stringstream ss;
	string temp = "";
	for(int i = 0; i < 2; i++){
		temp += arreglo[i].tostring();
	}
	if(izq != NULL){
		ss << arreglo[0].getkey() << "\n";
		temp += "Izquierda de: " + ss.str();
		temp += izq->tostring();
	}
	ss.str("");
	if(med != NULL){
		ss << arreglo[0].getkey() << "\n";
		temp += "Medio de: " + ss.str();
		temp += med->tostring();
	}
	ss.str("");
	if(der != NULL){
		ss << arreglo[1].getkey() << "\n";
		temp += "Derecha de: " + ss.str();
		temp += der->tostring();
	}
	return temp;
}
