#include "Meta.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

Meta::Meta(Vector2f pos) {
	m_meta.setPosition(pos);
	m_meta.setSize(Vector2f(135.0f, 35.0f));
	m_meta.setOrigin(67.5,25);
	m_meta.setFillColor({255,255,255});
}

void Meta::dibujar(RenderWindow &w){
	w.draw(m_meta);
}
