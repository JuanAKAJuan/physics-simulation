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
	for (const auto& particle : particles) {
		int screenX = static_cast<int>(std::round(particle.getPosition().x));
		int screenY = static_cast<int>(std::round(screenHeight - particle.getPosition().y));

		SDL_SetRenderDrawColor(renderer, particle.getColor().r, particle.getColor().g, particle.getColor().b,
							   particle.getColor().a);

		SDL_FRect rect;
		rect.x = screenX - static_cast<float>(particle.getSize()) / 2;
		rect.y = screenY - static_cast<float>(particle.getSize()) / 2;
		rect.w = particle.getSize();
		rect.h = particle.getSize();
		SDL_RenderFillRect(renderer, &rect);
	}
}

void Renderer::present() { SDL_RenderPresent(renderer); }
