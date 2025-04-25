#include "Animacion.h"
#include <cstdlib>
using namespace std;

Animacion::Animacion(): conteo("SONIDO-SALIDA.wav",50) {
	
}

void Animacion::actualizarCuentaRegresiva() {
	float tiempoTranscurrido = tiempo.Vertiempo();
	
	if (tiempoTranscurrido < 5.0f) {
		int numero = static_cast<int>(5.0f - tiempoTranscurrido);
		mensajeCuentaRegresiva = (numero > 0) ? to_string(numero) : "Go";
		
		cuentaRegresiva.actualizar({rand() , rand(), rand()},mensajeCuentaRegresiva,90, 602, 522);
		
		if (numero == 0) {
			mostrarCuentaRegresiva = false;
			tiempo.Empezar();
			conteo.PlayAndStop(false);
		}
	} else {
		if (mostrarCuentaRegresiva) {
			mostrarCuentaRegresiva = false;
		}
	}
}
void Animacion::iniciarCuentaRegresiva() {
	mensajeCuentaRegresiva = "3";
	cuentaRegresiva.actualizar({rand() , rand(), rand()},mensajeCuentaRegresiva,90, 602, 522);
	mostrarCuentaRegresiva = true;
	tiempo.Empezar();
	conteo.PlayAndStop(true);
}
void Animacion::dibujar(RenderWindow& window) {
	if (mostrarCuentaRegresiva) {
		cuentaRegresiva.dibujar(window);
	}
}
bool Animacion::VerAnimacion(){
	return mostrarCuentaRegresiva;
}


