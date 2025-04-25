#ifndef TIEMPO_H
#define TIEMPO_H
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
using namespace sf;

class Tiempo {
public:
	Tiempo();
	void Empezar();
	float Vertiempo();
private:
	Clock temporizador;
	float tiempo;
};

#endif

