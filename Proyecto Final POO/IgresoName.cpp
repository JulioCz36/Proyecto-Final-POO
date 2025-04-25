#include "IgresoName.h"
#include <iostream>
#include "Menu.h"
using namespace std;

IgresoName::IgresoName(float tiem):tiempo(tiem) {
	fuente.loadFromFile("tipografia.ttf");
	
	
	input.setFont(fuente);
	input.setCharacterSize(70);
	input.setPosition(560,550);
	input.setFillColor({255,255,255});
	input.setMaxChars(10);
	
	pt.loadFromFile("fondoGanador.jpg");
	ps.setTexture(pt);
}


void IgresoName::ProcesoEventos(Juego &j, Event &event){
	input.processEvent(event);
	if(event.type==Event::KeyPressed and event.key.code==Keyboard::Return and input.getValue() != "" ){
		nombre = input.getValue();
		
		top.Entra(tiempo,nombre);
		
		j.CambiarScena(new Menu());
		
	}
};
void IgresoName::actualizar(Juego &j){
	t1.actualizar({255,255,255},"WINNER!",120,370, 330);
	t2.actualizar({255,255,255},"Insert Name:",70,100, 550);
	input.update();
	
};
void IgresoName::dibujar(RenderWindow &w){
	w.draw(ps);
	t1.dibujar(w);
	t2.dibujar(w);
	w.draw(input);
}
