#include "renderer.h"

Renderer::Renderer(int width, int height) : screenWidth(width), screenHeight(height) {
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Physics Simulator", width, height, 0);
	renderer = SDL_CreateRenderer(window, nullptr);
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Renderer::clear() {
	SDL_SetRenderDrawColor(renderer, 17, 17, 17, 255);
	SDL_RenderClear(renderer);
}

void Renderer::renderParticles(const std::vector<Particle>& particles) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	for (const auto& particle : particles) {
		// Convert particle position to screen coordinates (assuming world coords are centered)
		int screenX = static_cast<int>(std::round(particle.getPosition().x));
		int screenY = static_cast<int>(std::round(screenHeight - particle.getPosition().y));

		SDL_RenderPoint(renderer, screenX, screenY);
	}
}

void Renderer::present() { SDL_RenderPresent(renderer); }
