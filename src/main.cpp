#include "core/particle_system.h"
#include "graphics/renderer.h"
#include <cstdlib>

int main() {
	const int WINDOW_HEIGHT = 1440;
	const int WINDOW_WIDTH = 1080;
	Renderer renderer(WINDOW_HEIGHT, WINDOW_WIDTH);
	ParticleSystem particleSystem;

	for (int i = 0; i < 100; i++) {
		Color randomColor = {(unsigned char)(rand() % 256), (unsigned char)(rand() % 256),
							 (unsigned char)(rand() % 256), 255};

		int randomSize = rand() % 10 + 5;

		particleSystem.addParticle(
			Particle(Vector3{(float)(rand() % 20 - 10), (float)(rand() % 10 + 5), (float)(rand() % 20 - 10)},
					 Vector3{0.0f, 0.0f, 0.0f}, 1.0f, randomColor, randomSize));
	}

	while (!WindowShouldClose()) {
		renderer.updateCamera();
		particleSystem.update(GetFrameTime());

		renderer.clear();
		renderer.renderParticles(particleSystem.getParticles());
		renderer.present();
	}

	return 0;
}
