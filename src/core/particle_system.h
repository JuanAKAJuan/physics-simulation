#pragma once

#include "particle.h"
#include <vector>

class ParticleSystem {
public:
	/**
	 * @brief Adds a new particle to the particle system.
	 *
	 * This function adds a copy of the provided particle to the internal vector of particles.
	 *
	 * @param particle The particle to be added.
	 */
	void addParticle(const Particle& particle);

	/**
	 * @brief Updates the state of all particles in the system.
	 *
	 * This function iterates through all particles in the system and updates their position,
	 * velocity, and acceleration based on applied forces and time elapsed. It also handles
	 * basic collision detection with the ground (y = 0).
	 *
	 * @param deltaTime The time elapsed since the last update, in seconds. This is crucial for
	 * accurate physics simulation. Smaller values lead to more precise but potentially more
	 * computationally intensive updates.
	 */
	void update(float deltaTime);

	const std::vector<Particle>& getParticles() const;

private:
	std::vector<Particle> particles;
};
