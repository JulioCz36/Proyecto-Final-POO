#ifndef MENU_H
#define MENU_H
#include "Objeto.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Scena.h"
#include "Texto.h"
#include "Juego.h"
#include <SFML/Window/Event.hpp>
using namespace std;

class Menu : public Scena{
public:
	Menu();
	void dibujar(RenderWindow &w) override;
	void actualizar(Juego &j) override;
	void ProcesoEventos(Juego &j, Event &event)override;
private:
	Texto start,top,select;
	Texture pt;
	Sprite ps;
	bool seleccionado;
	Objeto *CuadroS,*CuadroT,*CuadroSe;
};

#endif

