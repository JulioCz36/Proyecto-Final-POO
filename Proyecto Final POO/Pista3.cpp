#include "Pista3.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include <SFML/Graphics/RenderWindow.hpp>

Pista3::Pista3() : Carrera("pista_3.png",Vector2f (920.0f, 500.0f), Vector2f (970.0f, 500.0f),-180){
	pasto = {
		new Rectangulo(Vector2f(425.0f, 185.0f),1.0f,-90,{0,0,0,0}), // rectangulo sobre mapa
			new Rectangulo(Vector2f(380.0f, 655.0f),2.0f,-90,{0,0,0,0}), //rectangulo dentro a la izquierda
			new Rectangulo(Vector2f(815.0f, 690.0f),2.0f,-90,{0,0,0,0}), //dentro derecha del mapa
			new Rectangulo(Vector2f(248.0f, 550.0f),1.0f,180,{0,0,0,0}), //izquierda primer chekpoint 
			new Rectangulo(Vector2f(480.0f, 550.0f),3.0f,0,{0,0,0,0}), //Rectangulo dentro abajo 
			new Rectangulo(Vector2f(515.0f, 770.0f),2.0f,0,{0,0,0,0}), //rectangulo bajo del todo
			new Rectangulo(Vector2f(875.0f, 700.0f),1.5f,90,{0,0,0,0}), //rectangulo dentro a la derecha del mapa
			new Rectangulo(Vector2f(795.0f, 370.0f),1.9f,-90,{0,0,0,0}), //rectangulo arriba a la derecha
			new Rectangulo(Vector2f(570.0f, 480.0f),2.5f,-90,{0,0,0,0}), //rectangulo dentro arriba 
			new Rectangulo(Vector2f(1000.0f, 900.0f),6.0f,-90,{0,0,0,0}), //derecha del todo de pista cuadrado grande
			new Circulo(Vector2f(315.0f, 720.0f),2.5f,{0,0,0,0}), //Circulo centro de pista abajo izquierda
			new Rectangulo(Vector2f(200.0f, 380.0f),2.5f,-90,{0,0,0,0}),//centro de pista	
	};
	puntosDeControl={
		new Rectangulo (Vector2f(430.0f, 232.0f),1.5f,180,{255,200,90}),
			new Rectangulo (Vector2f(500.0f, 750.0f),1.5f,-90,{255,200,90}),
			new Rectangulo (Vector2f(1020.0f, 690.0f),1.5f,180,{255,200,90}),
			new Rectangulo (Vector2f(200.0f, 525.0f),1.5f,-90,{255,200,90}),
	};
	meta = new Rectangulo (Vector2f(885.0f, 550.0f),1.5f,0,{0,0,0,0});
	
	Carrera::Objetos(pasto,puntosDeControl,meta);
}

