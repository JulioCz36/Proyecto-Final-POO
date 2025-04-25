#include "Audio.h"
#include <string>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
using namespace std;

Audio::Audio(string archi,int volumen) {
	buffer.loadFromFile(archi);
	sound.setBuffer(buffer);
	sound.setVolume(volumen); 
}
void Audio::PlayAndStop(bool a){
	if(a == true){
		sound.setLoop(true);
		sound.play();
	}else{
		sound.setLoop(false);
		sound.stop();
	}
};
