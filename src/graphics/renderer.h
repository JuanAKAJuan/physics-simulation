#pragma once

#include "../core/particle.h"
#include <raylib.h>
#include <vector>

class Renderer {
public:
	Renderer(int width, int height);
	~Renderer();

	/**
	 * @brief Clears the renderer with a dark background color
	 *
	 * Sets the render draw color to a dark gray (RGB: 17, 17, 17) and
	 * clears the entire rendering target with this color.
	 */
	void clear();

	/**
	 * @brief Renders a collection of particles to the screen.
	 *
	 * This function iterates through a vector of `Particle` objects and draws each particle
	 * as a filled rectangle on the screen using the particle's position, size, and color.
	 * The y-coordinate is inverted to account for typical screen coordinate systems where
	 * the origin is at the top-left corner. The particle is centered on its position.
	 *
	 * @param particles A vector of `Particle` objects to be rendered.
	 */
	void renderParticles(const std::vector<Particle>& particles);

	/**
	 * @brief Presents the rendered scene to the screen.
	 *
	 * This function updates the screen with the contents of the rendering buffer,
	 * making the drawn graphics visible to the user. It typically synchronizes
	 * with the display's refresh rate to avoid tearing.
	 */
	void present();

	void updateCamera();

private:
	int screenWidth;
	int screenHeight;
	Camera3D camera;
};
