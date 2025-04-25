#include "Juego.h"
#include <SFML/Window/Event.hpp>
#include "Carrera.h"
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Rect.hpp>



Juego::Juego(Scena *e): w(VideoMode(1204, 1044), "Ride Or Die"), actual(e){
	w.setFramerateLimit(60);
	
	if (icon.loadFromFile("icon.png")) {
		w.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	}
	
}
Juego::~Juego(){
	delete actual;
};
void Juego::jugar() {
	
	while (w.isOpen()) {
		ProcesoEventos();
		w.clear();
		
		Actualizar();
		
		Dibujar();
		
		
		w.display();
		
		if (prox) {
			delete actual;
			actual = prox;
			prox = nullptr;
		}
		
	}
}

void Juego::Actualizar(){
	actual->actualizar(*this);
}
void Juego::Dibujar(){
	actual->dibujar(w);
}

void Juego::ProcesoEventos(){
	sf::Event e;
	while (w.pollEvent(e)) {
		if (e.type == sf::Event::Closed){
			w.close();
		}else {
			actual->ProcesoEventos(*this,e);
		}
	}
}

void Juego::CambiarScena(Scena *scena_nueva){
	prox = scena_nueva;
}
void Juego::Salir(){
	w.close();
}
