#include "Texto.h"
#include <SFML/Graphics/Color.hpp>

Texto::Texto() {
	fuente.loadFromFile("tipografia.ttf");
	tex.setFont(fuente);
}
void Texto::dibujar(RenderWindow &w){
	w.draw(tex);
}
void Texto::actualizar(Color color,const string& palabra,int size, int x, int y) {
	tex.setCharacterSize(size);
	tex.setPosition(x,y);
	tex.setString(palabra);
	tex.setFillColor(color);
}

