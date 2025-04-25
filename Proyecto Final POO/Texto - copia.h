#ifndef TEXTO_H
#define TEXTO_H
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
using namespace std;
using namespace sf;

class Texto {
public:
	Texto();
	void dibujar(RenderWindow &w);
	void actualizar(Color color,const string& palabra,int size,int x, int y);
private:
	Font fuente;
	Text tex;
};

#endif

