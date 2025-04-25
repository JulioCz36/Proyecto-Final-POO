#ifndef PISTA1_H
#define PISTA1_H
#include <vector>
#include "Objeto.h"
#include "Carrera.h"
#include "Juego.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;

class Pista1: public Carrera {
public:
	Pista1();
private:
	vector<Objeto*>pasto;
	vector<Objeto*>puntosDeControl;
	Objeto *meta;
protected: 
};

#endif

