#include "Auto.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
using namespace sf;

Auto::Auto(bool player_one,int puntos,Vector2f pos,int rotacion):avanza("motorAvance1.wav",40),parado("motorParado.wav",30) {
	if (player_one) {
		t.loadFromFile("auto_blanco.png");
	} else {
		t.loadFromFile("auto_negro.png");
	}
	
	s.setTexture(t);
	
	if (player_one) {
		s.setPosition(pos);
		s.setRotation(rotacion);
		der = Keyboard::Right;
		izq = Keyboard::Left;
		acel = Keyboard::Up;
		fren = Keyboard::Down;
	} else {
		s.setPosition(pos);
		s.setRotation(rotacion);
		der = Keyboard::D;
		izq = Keyboard::A;
		acel = Keyboard::W;
		fren = Keyboard::S;
	}
	s.setScale(0.2, 0.2);
	s.setOrigin(106.5, 211.5);
	
	puntosControlCruzados.resize(puntos, false);
}
Auto::~Auto() {
	avanza.PlayAndStop(false);
	parado.PlayAndStop(false);
}

void Auto::actualizar() {
	
	if(acelerando){
		parado.PlayAndStop(true);
	}
	
	if (Keyboard::isKeyPressed(der)) {
		s.rotate(2);
	}
	if (Keyboard::isKeyPressed(izq)) {
		s.rotate(-2);
	}
	if (Keyboard::isKeyPressed(acel)) {
		if (!acelerando) {
			avanza.PlayAndStop(true);
			acelerando = true; // Marca que ahora está acelerando
			parado.PlayAndStop(false);
		}
		
		float ang = s.getRotation() * M_PI / 180;
		s.move(velocidad * sin(ang), -velocidad * cos(ang));
	} else {
			avanza.PlayAndStop(false);
			acelerando = false; // Marca que ya no está acelerando
	}
	if (Keyboard::isKeyPressed(fren)) {
		float ang = s.getRotation() * M_PI / 180;
		s.move(-velocidad * sin(ang), velocidad * cos(ang));
	}
	verificarLimitesPantalla();
}

void Auto::verificarLimitesPantalla() {
	sf::Vector2f posicion = s.getPosition();
	sf::FloatRect bounds = s.getGlobalBounds();
	
	if (posicion.x < 0) {
		s.setPosition(0, posicion.y);
	} else if (posicion.x + bounds.width > 1204) {
		s.setPosition(1204 - bounds.width, posicion.y);
	}
	
	if (posicion.y < 0) {
		s.setPosition(posicion.x, 0);
	} else if (posicion.y + bounds.height > 1044) {
		s.setPosition(posicion.x, 1044 - bounds.height);
	}
}


void Auto::dibujar(RenderWindow &w) {
	w.draw(s);
}

void Auto::TocoPasto(vector<Objeto*>pas){
	for (Objeto* p : pas) {
		if (Interaccion(p)) {
			velocidad = 2.0f;
			break;
		}else {
			velocidad = 5.0f;
		}
	}
}

bool Auto::HizoVuelta(vector<Objeto*>puntosDeControl,Objeto* meta) {
	
	// Verificar colisiones con puntos de control
	for (size_t i = 0; i < puntosDeControl.size(); ++i) {
		if (Interaccion(puntosDeControl[i]) && !puntosControlCruzados[i]) {
			puntosControlCruzados[i] = true;
		}
	}
	
	int c = 0;
	for (size_t i = 0; i < puntosControlCruzados.size(); ++i) {
		if (puntosControlCruzados[i] == true) {
			c++;
		}
	}
	
	//Ver si hizo la vuelta
	if(c == puntosDeControl.size() && Interaccion(meta)) {
		for (int i = 0; i < puntosControlCruzados.size(); i++) {
			puntosControlCruzados[i] = false;
		}
		return true;
		
	}
	return false;
}



void Auto::evitarSuperposicion(Auto *otroAuto) {
	FloatRect bounds1 = s.getGlobalBounds();
	FloatRect bounds2 = otroAuto->s.getGlobalBounds();
	
	float separacionX = fabs(bounds1.left - bounds2.left);
	float separacionY = fabs(bounds1.top - bounds2.top);
	
	float superposicionX = bounds1.width / 2 + bounds2.width / 2 - separacionX;
	float superposicionY = bounds1.height / 2 + bounds2.height / 2 - separacionY;
	
	if (superposicionX > 0 && superposicionY > 0) {
		if (superposicionX < superposicionY) {
			if (bounds1.left < bounds2.left) {
				s.move(-superposicionX / 2, 0);
				otroAuto->s.move(superposicionX / 2, 0);
			} else {
				s.move(superposicionX / 2, 0);
				otroAuto->s.move(-superposicionX / 2, 0);
			}
		} else {
			if (bounds1.top < bounds2.top) {
				s.move(0, -superposicionY / 2);
				otroAuto->s.move(0, superposicionY / 2);
			} else {
				s.move(0, superposicionY / 2);
				otroAuto->s.move(0, -superposicionY / 2);
			}
		}
	}
}




