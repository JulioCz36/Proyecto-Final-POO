#ifndef GANADOR_H
#define GANADOR_H
#include "Scena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Texto.h"
#include <string>
#include <SFML/Window/Event.hpp>
using namespace std;

class Ganador : public Scena {
public:
	Ganador(string nombre,int carreras, float tim);
	void dibujar(RenderWindow &w) override;
	void actualizar(Juego &j) override;
	void ProcesoEventos(Juego &j, Event &event) override;
private:
	Texto t1,t2,t3,t4;
	Texture pt;
	Sprite ps;
	string ganador;
	int nroCarreras;
	float tiempo;
};

#endif

