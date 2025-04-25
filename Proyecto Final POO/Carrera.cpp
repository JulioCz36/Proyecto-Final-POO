#include "Carrera.h"
#include <vector>
#include "Objeto.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Texto.h"
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include "Animacion.h"
#include "Juego.h"
using namespace std;
using namespace sf;

Carrera::Carrera(string nombre,Vector2f pos1,Vector2f pos2,int rotacion):a1(new Auto(true, 4, pos1,rotacion)),a2(new Auto(false, 4,pos2,rotacion)){
	pt.loadFromFile(nombre);
	ps.setTexture(pt);
	
	cuentaRegreciba.iniciarCuentaRegresiva();
	
	tiempo1.Empezar();
	tiempo2.Empezar();
};

Carrera::~Carrera() {
	for (Objeto* objeto : pasto) {
		delete objeto;
	}
	for (Objeto* objeto : puntosDeControl) {
		delete objeto;
	}
	delete meta;
}

void Carrera::Objetos(vector<Objeto*>pas, vector<Objeto*>puntos, Objeto *m){
	pasto = pas;
	puntosDeControl = puntos;
	meta = m;
}

void Carrera::dibujar(RenderWindow &w){
	w.draw(ps);
	
	
	for (Objeto* pasto : pasto) {
		pasto->dibujar(w);
	}
	meta->dibujar(w);
	
	//Dibujar solo si el objeto Auto no es nulo
	if (a1 != nullptr) {
		a1->dibujar(w);
	}
	if (a2 != nullptr) {
		a2->dibujar(w);
	}
	
	for ( Objeto* puntoControl : puntosDeControl) {
		puntoControl->dibujar(w);
	}
	
	t1.dibujar(w);
	t2.dibujar(w);
	cuentaRegreciba.dibujar(w);
}



void Carrera::actualizar(Juego &j){
	unsigned char r=rand();
	unsigned char g=rand();
	unsigned char b=rand();
	for ( Objeto* puntoControl : puntosDeControl) {
		puntoControl->Actulizar({r,g,b});
	}
	
	cuentaRegreciba.actualizarCuentaRegresiva();
	
	if (!cuentaRegreciba.VerAnimacion()) {
			
			if (a1 != nullptr) {
				a1->actualizar();
				
				if (a2 != nullptr) {
					a1->evitarSuperposicion(a2);
				}
				
				a1->TocoPasto(pasto);
				
				// Verificar si el jugador 1 ha completado las 3 vueltas
				if (a1->HizoVuelta(puntosDeControl, meta)) {
					vuelA1++;
					if (vuelA1 == 3) {
						tiempoTotalJugador1 = tiempo1.Vertiempo();
						delete a1;
						a1 = nullptr;
					}
				}
			}
			
			
			if (a2 != nullptr) {
				a2->actualizar();
				
				if (a1 != nullptr) {
					a2->evitarSuperposicion(a1);
				}
				
				a2->TocoPasto(pasto);
				
				// Verificar si el jugador 2 ha completado las 3 vueltas
				if (a2->HizoVuelta(puntosDeControl, meta)) {
					vuelA2++;
					if (vuelA2 == 3) {
						tiempoTotalJugador2 = tiempo2.Vertiempo();
						delete a2;
						a2 = nullptr;
					}
				}
			}
			
			t1.actualizar({255,200,90},"Player 1: " + to_string(vuelA1),20,10,10);
			
			t2.actualizar({255,200,90},"Player 2: " + to_string(vuelA2),20,10,40);
			
	}
	
}
bool Carrera::termino(){
	if (a1 == nullptr && a2 == nullptr) {
		return true;
	}
	return false;
}

pair<float,float>Carrera::VerResultado(){
	
	return {tiempoTotalJugador1 ,tiempoTotalJugador2};
	
}


