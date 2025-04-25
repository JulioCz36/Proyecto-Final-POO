#ifndef PARTIDA_H
#define PARTIDA_H

#include "Auto.h"
#include <vector>
#include "Carrera.h"
#include "Scena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include "Pista1.h"
#include "Pista2.h"
#include "Pista3.h"
#include "Pista4.h"
using namespace std;
using namespace sf;


class Partida : public Scena {
public:
	Partida();
	void actualizar(Juego &j) override;
	void dibujar(RenderWindow &w) override;	
	void ProcesoEventos(Juego &j, Event &event) override;
	~Partida();
	
private:
	Carrera* pista = new Pista1();
	int c;
	int cantGano1 ,cantGano2;
	float tiempo1, tiempo2;
	float tiempoTotal1, tiempoTotal2;
	pair<float,float> p ;
	
	Tiempo tiempoPausa;
	float tiempoPausaTotal;
	
	bool EsPausa;
};

#endif 


