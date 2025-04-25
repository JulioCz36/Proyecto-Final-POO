#ifndef TOPTEN_H
#define TOPTEN_H

#include <string>
#include <fstream>
#include <cstring>
#include <list>
#include <SFML/Graphics.hpp>
#include "Scena.h"
#include "Texto.h"
#include <SFML/Window/Event.hpp>
using namespace std;

struct datos {
	float tim;
	char nombre[10]; 
};


class Juego;

class topten : public Scena {
public:
	topten();
	void Entra(float t, std::string n);
	void dibujar(RenderWindow &w) override;
	void actualizar(Juego &j) override;
	void ProcesoEventos(Juego &j, Event &event)override;
	
private:
	Texto nombre, puntos, horizontal, vertical, tituloNombre, tituloPuntos;
	std::list<datos> lista;
	Texture pt;
	Sprite ps;
};

#endif

