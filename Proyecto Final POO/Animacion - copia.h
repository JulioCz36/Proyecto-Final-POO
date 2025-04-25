#ifndef ANIMACION_H
#define ANIMACION_H
#include <SFML/System/Clock.hpp>
#include "Texto.h"
#include "Audio.h"
#include "Tiempo.h"

class Animacion {
public:
	Animacion();
	
	void actualizarCuentaRegresiva();
	
	void iniciarCuentaRegresiva();
	
	void dibujar(RenderWindow& window);
	bool VerAnimacion();
	
		
private:
		float tiempoCuentaRegresiva;
		Tiempo tiempo;
		Texto cuentaRegresiva;
		bool mostrarCuentaRegresiva;
		string mensajeCuentaRegresiva;
		Audio conteo;
};

#endif

