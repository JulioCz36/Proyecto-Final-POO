#ifndef META_H
#define META_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Meta {
public:
	Meta(Vector2f pos);
	
	void dibujar(RenderWindow &w);
	
	FloatRect verGlobalBounds() {
		return m_meta.getGlobalBounds();
	}
	
	
private:
	RectangleShape m_meta;
};

#endif

