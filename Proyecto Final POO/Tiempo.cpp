#include "Tiempo.h"
#include <SFML/System/Clock.hpp>

Tiempo::Tiempo() {
}
void Tiempo::Empezar(){
	temporizador.restart();
}
float Tiempo::Vertiempo() {
	tiempo = temporizador.getElapsedTime().asSeconds();
	return tiempo;
}
