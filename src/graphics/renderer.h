#pragma once

#include "../core/particle.h"
#include <SDL3/SDL.h>
#include <vector>

class Renderer {
public:
	Renderer(int width, int height);
	~Renderer();

	void clear();
	void renderParticles(const std::vector<Particle>& particles);
	void present();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	int screenWidth;
	int screenHeight;
};
