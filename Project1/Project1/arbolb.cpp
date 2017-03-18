#include "arbolb.h"
#include <string>

using std::string;


arbolb::arbolb(pagina raiz){
	root = raiz;
}
pagina arbolb::getroot(){
	return root;
}
void arbolb::setroot(pagina newroot){
	root = newroot;
}
void arbolb::refresh(){
	if(root.getpadre() != NULL){
		root = *root.getpadre();
	}
}
void arbolb::agregar(pagina nuevovalor,bool validacion){
	root.agregar(nuevovalor,validacion);
	refresh();
}
void arbolb::eliminar(int key){

}
string arbolb::tostring(){
	string imprimir = root.tostring();
	return imprimir;
}
