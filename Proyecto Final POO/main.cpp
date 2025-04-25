#include <SFML/Graphics.hpp>
#include <cmath>
#include "Carrera.h"
#include "Menu.h"
#include <SFML/Window/Keyboard.hpp>
#include "Juego.h"
#include "Ganador.h"
#include "IgresoName.h"
using namespace std;
using namespace sf;

int main(int argc, char *argv[]) {
	Juego j(new Menu());
	j.jugar();
	
	return 0;
}

