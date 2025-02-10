#include "particle_system.h"

void ParticleSystem::addParticle(const Particle& particle) { particles.push_back(particle); }

void ParticleSystem::update(float deltaTime) {
	for (auto& particle : particles) {
		// 1. Calculate forces on the particle
		Vector3 force = {0.0f, 0.0f, 0.0f};

		// Example: Gravity force
		Vector3 gravity = {0.0f, -9.8f * particle.getMass(), 0.0f};
		force = Vector3Add(force, gravity);

		// 2. Update acceleration
		Vector3 acceleration = Vector3Scale(force, 1.0f / particle.getMass());
		particle.setAcceleration(acceleration);

		// 3. Update velocity based on acceleration and deltaTime
		Vector3 deltaV = Vector3Scale(particle.getAcceleration(), deltaTime);
		Vector3 newVelocity = Vector3Add(particle.getVelocity(), deltaV);
		particle.setVelocity(newVelocity);

		// 4. Update position based on velocity and deltaTime
		Vector3 deltaP = Vector3Scale(particle.getVelocity(), deltaTime);
		Vector3 newPosition = Vector3Add(particle.getPosition(), deltaP);
		particle.setPosition(newPosition);

		// 5. Apply any constraints (e.g., ground collision)
		float radius = particle.getSize() * 0.1f;
		if (particle.getPosition().y < radius) {
			// Set position at ground level
			Vector3 groundPosition = particle.getPosition();
			groundPosition.y = radius;
			particle.setPosition(groundPosition);

			// Bounce with energy loss
			Vector3 velocity = particle.getVelocity();
			velocity.y = -velocity.y * 0.8f; // 80% energy conservation
			particle.setVelocity(velocity);
		}
	}
}

const std::vector<Particle>& ParticleSystem::getParticles() const { return particles; }
