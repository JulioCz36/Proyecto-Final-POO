#include "Circulo.h"

Circulo::Circulo(Vector2f pos,float escala,Color col) {
	// Configurar el círculo
	circulo.setRadius(20 * escala);
	circulo.setPosition(pos);
	circulo.setOrigin(circulo.getRadius(), circulo.getRadius());
	circulo.setFillColor(col);
}


FloatRect Circulo::verGlobalBounds(){
	return circulo.getGlobalBounds();
}

void Circulo::dibujar(RenderWindow &w){
	w.draw(circulo);
}

