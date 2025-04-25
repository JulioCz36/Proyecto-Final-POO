#include "Pista1.h"
#include "Circulo.h"
#include "Rectangulo.h"

Pista1::Pista1():Carrera("pista_1.png",Vector2f (220.0f, 580.0f), Vector2f (270.0f, 580.0f),0){
	pasto = {
		new Circulo(Vector2f(895.0f, 620.0f),2.2f,{0,0,0,0}),
			new Rectangulo(Vector2f(320.0f, 630.0f),5.0f,0,{0,0,0,0}),
			new Rectangulo(Vector2f(320.0f, 630.0f),2.8f,-90,{0,0,0,0}),
			new Rectangulo(Vector2f(0.0f, 520.0f),5.5f,-90,{0,0,0,0}),
			new Rectangulo(Vector2f(0.0f, 1000.0f),5.5f,-90,{0,0,0,0}),
			new Rectangulo(Vector2f(200.0f, 0.0f),3.0f,0,{0,0,0,0}),
			new Rectangulo(Vector2f(600.0f, 0.0f),12.0f,0,{0,0,0,0}),
			new Rectangulo(Vector2f(570.0f, 0.0f),2.0f,90,{0,0,0,0}),
			new Rectangulo(Vector2f(580.0f, 420.0f),1.5f,0,{0,0,0,0}),
			new Rectangulo(Vector2f(1100.0f, 470.0f),1.5f,-90,{0,0,0,0}),
			new Rectangulo(Vector2f(900.0f, 900.0f),6.5f,0,{0,0,0,0}),
			new Circulo(Vector2f(1105.0f, 850.0f),2.2f,{0,0,0,0}),
			new Rectangulo(Vector2f(320.0f, 410.0f),1.5f,-90,{0,0,0,0}),	
	};
	
	puntosDeControl={
		new Rectangulo (Vector2f(300.0f, 232.0f),1.5f,-90,{255,200,90}),
			new Rectangulo (Vector2f(650.0f, 630.0f),1.5f,-90,{255,200,90}),
			new Rectangulo (Vector2f(950.0f, 690.0f),1.5f,65,{255,200,90}),
			new Rectangulo (Vector2f(390.0f, 960.0f),1.5f,-90,{255,200,90}),
	};
	meta = new Rectangulo (Vector2f(175.0f, 500.0f),1.5f,0,{0,0,0,0});
	Carrera::Objetos(pasto,puntosDeControl,meta);
}

