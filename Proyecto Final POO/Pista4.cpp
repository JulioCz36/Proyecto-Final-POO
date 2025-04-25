#include "Pista4.h"

Pista4::Pista4() :Carrera("pista_4.png",Vector2f (550.0f, 350.0f), Vector2f (550.0f, 320.0f),90){
	pasto = {
		new Circulo(Vector2f(890.0f, 480.0f),3.2f,{0,0,0,0}), // circulo centro derecha 
			new Rectangulo(Vector2f(1000.0f, 260.0f),9.0f,180,{0,0,0,0}), //grande superior
			new Rectangulo(Vector2f(1100.0f, 700.0f),5.0f,-90,{0,0,0,0}), //derecha del todo fuera de pista
			new Rectangulo(Vector2f(650.0f, 700.0f),1.5f,-90,{0,0,0,0}), //curba inferior fuera
			new Rectangulo(Vector2f(700.0f, 450.0f),1.5f,180,{0,0,0,0}),  //centro de pista
			new Rectangulo(Vector2f(900.0f, 1055.0f),9.0f,180,{0,0,0,0}),  //bajo fuera de la pista
			new Rectangulo(Vector2f(780.0f, 700.0f),4.0f,0,{0,0,0,0}),  //derecha debajo de la pista
			new Rectangulo(Vector2f(00.0f, 700.0f),4.5f,-90,{0,0,0,0}), // 
			new Circulo(Vector2f(400.0f, 540.0f),5.5f,{0,0,0,0}), //circulo centro de pista izquierda
	};
	puntosDeControl={
		new Rectangulo (Vector2f(800.0f, 400.0f),1.5f,-90,{255,200,90}),
			new Rectangulo (Vector2f(900.0f, 700.0f),1.5f,-90,{255,200,90}),
			new Rectangulo (Vector2f(390.0f, 800.0f),1.5f,-90,{255,200,90}),
			new Rectangulo (Vector2f(400.0f, 400.0f),1.5f,-90,{255,200,90}),
	};
	meta = new Rectangulo (Vector2f(590.0f, 400.0f),1.5f,-90,{0,0,0,0});
	Carrera::Objetos(pasto,puntosDeControl,meta);
}

