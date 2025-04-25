#ifndef PISTA3_H
#define PISTA3_H
#include <vector>
#include "Objeto.h"
#include "Carrera.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scena.h"
#include "Pista3.h"
using namespace std;

class Pista3: public Carrera{
public:
	Pista3();
private:
	vector<Objeto*>pasto;
	vector<Objeto*>puntosDeControl;
	Objeto *meta;
};

#endif

