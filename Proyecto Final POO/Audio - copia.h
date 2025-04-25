#ifndef AUDIO_H
#define AUDIO_H
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <string>
using namespace std;
using namespace sf;

class Audio {
public:
	Audio(string archi,int volumen);
	void PlayAndStop(bool a);
private:
	SoundBuffer buffer;
	Sound sound;
};

#endif

