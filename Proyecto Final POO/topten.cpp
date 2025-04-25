#include "topten.h"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
#include <cstring>
#include "Juego.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Texto.h"
#include <iostream>
#include <iomanip>
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"
using namespace std;


topten::topten(){
	pt.loadFromFile("fondoTopTen.jpg");
	ps.setTexture(pt);
}

void topten::Entra(float t, string n) {
	
	datos x;
	ifstream archi("datos.dat", ios::binary);
	
	while (archi.read(reinterpret_cast<char*>(&x), sizeof(datos))) {
		lista.push_back(x);
	}
	
	archi.close();
	
	// Ordenada en orden descendente.
	lista.sort([]( datos& a,  datos& b) {
		return a.tim < b.tim;
	});
	
	strcpy(x.nombre, n.c_str());
	x.tim = t;
	
	bool agregado = false;
	for (auto it = lista.begin(); it != lista.end(); ++it) {
		if (x.tim < it->tim) {
			lista.insert(it, x);
			agregado = true;
			break;
		}
	}
	
	if(agregado == false){
		lista.push_back(x);
	}
	
	// Limitar la lista a 10 elementos.
	if (lista.size() > 10) {
		lista.pop_back();
	}
	
	// Guardar la lista actualizada en el archivo solo si el jugador entró en el top ten.

	ofstream archi_out("datos.dat", ios::binary | ios::trunc);
	
	for (const auto& item : lista) {
		archi_out.write(reinterpret_cast<const char*>(&item), sizeof(datos));
	}
	archi_out.close();
}


void topten::dibujar(RenderWindow &w) {
	w.draw(ps);
	

	
	datos x;
	
	ifstream archi("datos.dat", ios::binary | ios::ate);
	int cant = archi.tellg() / sizeof(datos);
	archi.seekg(0);
	
	
	tituloNombre.dibujar(w);
	tituloPuntos.dibujar(w);
	
	for (int i = 0; i < cant; i++) {
		archi.read(reinterpret_cast<char*>(&x), sizeof(datos));
		
		//Paso de char a string
		string s1(x.nombre);
		
		//redusco los 0
		ostringstream oss;
		oss << fixed << setprecision(2) << x.tim;
		string x_tim = oss.str();
		
		nombre.actualizar(Color::Red, s1, 50, 100, 130 + i * 70);
		puntos.actualizar(Color::Red,  x_tim + "s", 50, 700, 130 + i * 70);
		horizontal.actualizar(Color::Red,"---------------------------------------------------------------", 50, 0, 153 + i * 70);
		vertical.actualizar(Color::Red, "|", 70, 602, 100 + i * 70);
		nombre.dibujar(w);
		puntos.dibujar(w);
		horizontal.dibujar(w);
		vertical.dibujar(w);
	}
	
}
void topten::actualizar(Juego &j) {
	tituloNombre.actualizar(Color::Red, "Nombre", 50, 100, 30);
	tituloPuntos.actualizar(Color::Red,  "Tiempo", 50, 700, 30);
}

void topten::ProcesoEventos(Juego &j, Event &event){
	if(event.type==Event::KeyPressed and event.key.code==Keyboard::Escape){
		j.CambiarScena(new Menu);
	}
}


