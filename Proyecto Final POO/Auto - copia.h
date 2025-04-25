#ifndef AUTO_H
#define AUTO_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "Objeto.h"
#include <iostream>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Audio.h"
using namespace std;
using namespace sf;

class Auto{
	Texture t;
	Sprite s;
	Keyboard::Key acel,fren,izq,der;
	float velocidad = 5.0f;
	vector<bool> puntosControlCruzados;
	Audio avanza,parado;
	bool acelerando;
	
public:
	Auto(bool player_one,int puntos,Vector2f pos1,Vector2f pos2,int rotacion);
	
	void actualizar();
	
	void dibujar(RenderWindow &w);
	
	void verificarLimitesPantalla();
	
	void TocoPasto(vector<Objeto*>pas);
		
	bool HizoVuelta(vector<Objeto*>puntosDeControl,Objeto* meta);
		
	void evitarSuperposicion( Auto* otroAuto); 
		
	template<class T>
	bool Interaccion(T &m) {
		FloatRect rectMeta = m->verGlobalBounds();
		FloatRect rectAuto = s.getGlobalBounds();
		
		return rectMeta.intersects(rectAuto);
	}
	
	~Auto();
		
};

#endif

