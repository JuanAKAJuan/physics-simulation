#include "particle_system.h"

void ParticleSystem::addParticle(const Particle& particle) { particles.push_back(particle); }

void ParticleSystem::update(float deltaTime) {
	for (auto& particle : particles) {
		// 1. Calculate forces on the particle
		glm::vec3 force(0.0f);

		// Example: Gravity force
		force += glm::vec3(0.0f, -9.8f * particle.getMass(), 0.0f);

		// 2. Update acceleration
		particle.setAcceleration(force / particle.getMass());

		// 3. Update velocity based on acceleration and deltaTime
		particle.setVelocity(particle.getVelocity() + particle.getAcceleration() * deltaTime);

		// 4. Update position based on velocity and deltaTime
		particle.setPosition(particle.getPosition() + particle.getVelocity() * deltaTime);

		// 5. Apply any constraints (e.g., ground collision)
		if (particle.getPosition().y < 0.0f) {
			particle.setPosition(glm::vec3(particle.getPosition().x, 0.0f, particle.getPosition().z));
			particle.setVelocity(
				glm::vec3(particle.getVelocity().x, -particle.getVelocity().y * 0.8f, particle.getVelocity().z));
		}
	}
}

const std::vector<Particle>& ParticleSystem::getParticles() const { return particles; }
