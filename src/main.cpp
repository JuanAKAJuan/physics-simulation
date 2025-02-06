#include "core/particle_system.h"
#include "graphics/renderer.h"
#include <cstdlib>

int main() {
	const int WINDOW_HEIGHT = 1440;
	const int WINDOW_WIDTH = 1080;
	Renderer renderer(WINDOW_HEIGHT, WINDOW_WIDTH);
	ParticleSystem particleSystem;

	for (int i = 0; i < 100; i++) {
		SDL_Color randomColor;
		randomColor.r = rand() % 256;
		randomColor.g = rand() % 256;
		randomColor.b = rand() % 256;
		randomColor.a = 255;

		int randomSize = rand() % 10 + 5;

		particleSystem.addParticle(Particle(glm::vec3(rand() % WINDOW_HEIGHT, rand() % WINDOW_WIDTH, 0.0f),
											glm::vec3(0.0f), 1.0f, randomColor, randomSize));
	}

	bool running = true;
	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
		}

		particleSystem.update(1.0f / 60.0f);

		renderer.clear();
		renderer.renderParticles(particleSystem.getParticles());
		renderer.present();

		SDL_Delay(16); // ~60 FPS delay
	}

	return 0;
}
