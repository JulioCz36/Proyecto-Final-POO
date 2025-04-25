#include "Pista2.h"
#include "Circulo.h"
#include "Rectangulo.h"

Pista2::Pista2() :Carrera("pista_2.png",Vector2f (630.0f, 820.0f), Vector2f (630.0f, 790.0f),-90){
	pasto = {
		new Circulo(Vector2f(880.0f, 700.0f),2.0f,{0,0,0,0}), ///circulo 1 abajo del todo antes de la meta
			new Rectangulo(Vector2f(720.0f, 630.0f),2.0f,-90,{0,0,0,0}),
			new Rectangulo(Vector2f(650.0f, 750.0f),2.0f,180,{0,0,0,0}),///rectangulo sobre la meta
			new Rectangulo(Vector2f(0.0f, 750.0f),4.0f,-90,{0,0,0,0}),///izquierda de la pista
			new Rectangulo(Vector2f(250.0f, 750.0f),4.0f,-90,{0,0,0,0}), ///rectangulo centro de la pista
			new Rectangulo(Vector2f(200.0f, 175.0f),3.0f,0,{0,0,0,0}), ///rectangulo sobre punto de control 1
			new Rectangulo(Vector2f(650.0f, 10.0f),4.0f,0,{0,0,0,0}), ///rectangulo  arriba de todo.
			new Rectangulo(Vector2f(575.0f, 383.0f),2.0f,90,{0,0,0,0}),///circulo que se encuentra en la 2da curva
			new Rectangulo(Vector2f(790.0f, 275.0f),2.0f,90,{0,0,0,0}),///medio de la carrera entre la pista y las curvas
			new Rectangulo(Vector2f(1040.0f, 400.0f),1.5f,-90,{0,0,0,0}),///derecha sobre el circulo
			new Rectangulo(Vector2f(700.0f, 900.0f),6.5f,0,{0,0,0,0}),
			new Circulo(Vector2f(960.0f,500.0f),2.2f,{0,0,0,0}), ///circulo 2 
			new Rectangulo(Vector2f(375.0f, 450.0f),1.5f,180,{0,0,0,0}), ///sobre el punto de control 1	
	};
	puntosDeControl={
		new Rectangulo (Vector2f(300.0f, 400.0f),1.5f,-90,{255,200,90}),
			new Rectangulo (Vector2f(725.0f, 300.0f),1.5f,180,{255,200,90}),
			new Rectangulo (Vector2f(905.0f, 670.0f),1.5f,-90,{225,200,90}),
			new Rectangulo (Vector2f(450.0f, 870.0f),1.5f,-90,{225,200,90}),
	};
	meta = new Rectangulo (Vector2f(550.0f, 870.0f),1.5f,-90,{0,0,0,0});
	Carrera::Objetos(pasto,puntosDeControl,meta);
}
