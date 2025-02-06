#include "core/particle_system.h"
#include "graphics/renderer.h"

int main() {
	const int WINDOW_HEIGHT = 1440;
	const int WINDOW_WIDTH = 1080;
	Renderer renderer(WINDOW_HEIGHT, WINDOW_WIDTH);
	ParticleSystem particleSystem;

	for (int i = 0; i < 100; i++) {
		particleSystem.addParticle(
			Particle(glm::vec3(rand() % WINDOW_HEIGHT, rand() % WINDOW_WIDTH, 0.0f), glm::vec3(0.0f), 1.0f));
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
