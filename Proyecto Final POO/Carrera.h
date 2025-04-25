#ifndef CARRERA_H
#define CARRERA_H

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Objeto.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Auto.h"
#include "Texto.h"
#include "Tiempo.h"
#include "Animacion.h"
#include "Scena.h"
#include "Juego.h"
#include <vector>
using namespace std;
using namespace sf;

struct Dato {
	string gana;
	float tiem;
};



class Carrera {
public:
	Carrera(string nombre,Vector2f pos1,Vector2f pos2,int rotacion);
	void dibujar(RenderWindow &w);
	void actualizar(Juego &j);
	
	void Objetos(vector<Objeto*>pas, vector<Objeto*>puntos, Objeto *m);
	
	pair<float,float> VerResultado();
	
	bool termino();
	
	~Carrera();
	
private:
	
	Texture pt;
	Sprite ps;
	
	Texto t1, t2;
	
	vector<Objeto*> pasto;
	vector<Objeto*> puntosDeControl;
	Objeto *meta;
	
	Auto *a1, *a2;
	
	int vuelA1 = 0;
	int vuelA2 = 0;
	
	Tiempo tiempo1, tiempo2;
	
	float tiempoTotalJugador1, tiempoTotalJugador2;
	
	Animacion cuentaRegreciba;
};

#endif


