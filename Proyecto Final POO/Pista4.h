#ifndef PISTA4_H
#define PISTA4_H
#include <vector>
#include "Objeto.h"
#include "Carrera.h"
using namespace std;

class Pista4: public Carrera{
public:
	Pista4();
private:
	vector<Objeto*>pasto;
	vector<Objeto*>puntosDeControl;
	Objeto *meta;
};
#endif

