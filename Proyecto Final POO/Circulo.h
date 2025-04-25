#ifndef CIRCULO_H
#define CIRCULO_H
#include <SFML/Graphics/CircleShape.hpp>
#include "Objeto.h"

class Circulo : public Objeto {
public:
	Circulo(Vector2f pos,float escala,Color col);
	void dibujar(RenderWindow &w) override;
	FloatRect verGlobalBounds() override;
	void Actulizar(Color col)override{
		circulo.setFillColor(col);
	};
private:
	CircleShape circulo;
};

#endif

