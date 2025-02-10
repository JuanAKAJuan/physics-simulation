#include "renderer.h"
#include <raylib.h>

Renderer::Renderer(int width, int height) : screenWidth(width), screenHeight(height) {
	InitWindow(screenWidth, screenHeight, "Physics Simulation");
	SetTargetFPS(60);

	// Initialize 3D camera
	camera.position = Vector3{10.0f, 10.0f, 10.0f};
	camera.target = Vector3{0.0f, 0.0f, 0.0f};
	camera.up = Vector3{0.0f, 1.0f, 0.0f};
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;
}

Renderer::~Renderer() { CloseWindow(); }

void Renderer::clear() {
	BeginDrawing();
	ClearBackground(DARKGRAY);
	BeginMode3D(camera);
}

void Renderer::renderParticles(const std::vector<Particle>& particles) {
	// Draw ground plane
	DrawGrid(20, 1.0f);

	for (const auto& particle : particles) {
		Vector3 pos = particle.getPosition();
		Color color = particle.getColor();
		float size = static_cast<float>(particle.getSize() * 0.1f); // Scale down size for 3D

		DrawSphere(pos, size, color);
	}
}

void Renderer::present() {
	EndMode3D();
	DrawFPS(10, 10);
	EndDrawing();
}

void Renderer::updateCamera() { UpdateCamera(&camera, CAMERA_ORBITAL); }
