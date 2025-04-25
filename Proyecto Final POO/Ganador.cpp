#include "Ganador.h"
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"
#include <sstream>
#include <iomanip>
#include "IgresoName.h"
using namespace std;

Ganador::Ganador(string nombre,int carreras, float tim):ganador(nombre),nroCarreras(carreras),tiempo(tim) {
	pt.loadFromFile("fondoGanador.jpg");
	ps.setTexture(pt);
}

void Ganador::dibujar(RenderWindow &w){
	w.draw(ps);
	t1.dibujar(w);
	t2.dibujar(w);
	t3.dibujar(w);
	t4.dibujar(w);
	t5.dibujar(w);
	t6.dibujar(w);
	t7.dibujar(w);
	
}
void Ganador::actualizar(Juego &j){
	//redusco los 0
	ostringstream oss;
	oss << fixed << setprecision(2) << tiempo;
	string x_tiempo = oss.str();
	
	
	t1.actualizar({255,255,255}, "Ganador!!", 100, 380, 30);
	t2.actualizar({255,255,255}, ganador, 70, 480, 800);
	t3.actualizar({255,200,155}, "Carreras: " + to_string(nroCarreras), 70, 400, 470);
	t4.actualizar({255,200,155}, "Tiempo: " +  x_tiempo + "s", 70, 350, 570);
	t5.actualizar({255,200,155}, "Enter ->", 50, 950, 670);
	t6.actualizar({255,200,155}, "Cont.", 50, 950, 720);
	t7.actualizar({255,200,155}, "Esc", 50, 20, 20);
}

void Ganador::ProcesoEventos(Juego &j, Event &event){
	if(event.type==Event::KeyPressed and event.key.code==Keyboard::Escape){
		j.CambiarScena(new Menu());
	}if(event.type==Event::KeyPressed and event.key.code==Keyboard::Return){
		
		j.CambiarScena(new IgresoName(tiempo));
	}
	
}


