#pragma once
#include <string>

using std::string;

class nodo{
	string path;
	int key;
public:
	nodo(string,int);
	nodo();
	string getpath();
	int getkey();
	void setpath(string);
	void setkey(int);
	string tostring();
};
