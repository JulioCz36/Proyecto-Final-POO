#include "Partida.h"
#include "Ganador.h"
#include <numeric>
#include "Menu.h"
using namespace std;

Partida::Partida() {
	pista = new Pista1();
	cantGano1 = 0;
	cantGano2 = 0;
	
	tiempo1 = 0.0f; 
	tiempo2 = 0.0f;
	c = 0;
}


Partida::~Partida() {
	delete pista;
}

void Partida::actualizar(Juego& j) {		
		
	if (pista != nullptr && !pista->termino()) {
		pista->actualizar(j);
	} else {
				
		p = pista->VerResultado();
				
		if (p.first < p.second) {
			cantGano1++;
		} else {
			cantGano2++;
		}
				
		tiempo1 += p.first;
		tiempo2 += p.second;
					
		c++;
				
		delete pista;
				
		switch (c) {
			case 1:
				
				pista = new Pista4();
			break;
					
			case 2:
					
/*				pista = new Pista3();*/
				
				if (cantGano1 > cantGano2) {
					
					j.CambiarScena(new Ganador("Player1", cantGano1, tiempo1/2));
					
				} else if (cantGano1 < cantGano2) {
					
					j.CambiarScena(new Ganador("Player2", cantGano2, tiempo2/2));
					
				} else {
					
					if ((tiempo1) < (tiempo2)) {
						
						j.CambiarScena(new Ganador("Player1", cantGano1, tiempo1/2));
						
					} else{
						
						j.CambiarScena(new Ganador("Player2", cantGano2, tiempo2/2));
						
					}
				}
				break;
					
//			case 3:
//				
//				pista = new Pista4();
//				break;
//					
//			case 4:
				// logica para saber quien gano
/*				break;*/
					
				default:
					break;
				}
		}
}
	


void Partida::dibujar(RenderWindow& w) {
	if (pista != nullptr && !pista->termino()) {
		pista->dibujar(w);
	}
}




