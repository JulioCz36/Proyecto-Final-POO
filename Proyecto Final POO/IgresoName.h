#ifndef IGRESONAME_H
#define IGRESONAME_H
#include "Scena.h"
#include <SFML/Window/Event.hpp>
#include "Juego.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "InputText.hpp"
#include <string>
#include "Texto.h"
#include "topten.h"
using namespace std;

class IgresoName: public Scena {
public:
	IgresoName(float tiem);
	void ProcesoEventos(Juego &j, Event &event)override;
	void actualizar(Juego &j)override;
	void dibujar(RenderWindow &w)override;
private:
	InputText input;
	Font fuente;
	string nombre;
	Texture pt;
	Sprite ps;
	Texto t1,t2;
	topten top;
	
	float tiempo;
};

#endif

