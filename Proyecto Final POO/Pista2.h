#ifndef PISTA2_H
#define PISTA2_H
#include <vector>
#include "Objeto.h"
#include "Carrera.h"
#include "Juego.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;

class Pista2 : public Carrera {
public:
	Pista2();
private:
	vector<Objeto*>pasto;
	vector<Objeto*>puntosDeControl;
	Objeto *meta;
};

#endif

