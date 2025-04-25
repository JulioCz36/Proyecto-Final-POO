#include "Menu.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include "Scena.h"
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "Juego.h"
#include "Carrera.h"
#include "Pista1.h"
#include "topten.h"
#include "Partida.h"
using namespace std;
using namespace sf;


Menu::Menu(){
	pt.loadFromFile("fondoMenu.jpg");
	ps.setTexture(pt);
	CuadroS = new Rectangulo(Vector2f(360.0f,410.0f),5,0,{255,255,255});
	CuadroT = new Rectangulo(Vector2f(360.0f,610.0f),5,0,{255,255,255});
	CuadroSe = new Rectangulo(Vector2f(360.0f,610.0f),5,0,{255,255,255,0});
}


void Menu::actualizar(Juego &j) {
	start.actualizar(Color::Red, "START", 100, 410, 420);
	top.actualizar(Color::Red, "TOPTEN", 100, 370, 620);
}
	

void Menu::dibujar(RenderWindow &w){
	w.draw(ps);
	CuadroS->dibujar(w);
	CuadroT->dibujar(w);
	start.dibujar(w);
	top.dibujar(w);
	CuadroSe->dibujar(w);
	select.dibujar(w);
}

void Menu::ProcesoEventos(Juego &j, Event &event){
	if(event.type==Event::KeyPressed and event.key.code==Keyboard::Escape){
		j.Salir();
	
	}
	if(event.type==Event::KeyPressed and event.key.code==Keyboard::Up){
		select.actualizar({255,255,255}, "START", 100, 410, 420);
		seleccionado = true;
		CuadroSe = new Rectangulo(Vector2f(360.0f,410.0f),5,0,Color::Red);
	}
	
	if(event.type==Event::KeyPressed and event.key.code==Keyboard::Down){
		select.actualizar({255,255,255}, "TOPTEN", 100, 370, 620);
		seleccionado = false;
		CuadroSe = new Rectangulo(Vector2f(360.0f,610.0f),5,0,Color::Red);
		
	}
	if(event.type==Event::KeyPressed and event.key.code==Keyboard::Return){
		if(seleccionado ==true){
			j.CambiarScena(new Partida());
		}else{
			j.CambiarScena(new topten());
		}
	}
}
