#pragma once

#include <glm/glm.hpp>

class Particle {
public:
	Particle(const glm::vec3& pos, const glm::vec3& vel, float m);

	const glm::vec3& getPosition() const;
	const glm::vec3& getVelocity() const;
	const glm::vec3& getAcceleration() const;
	float getMass() const;

	void setPosition(const glm::vec3& pos);
	void setVelocity(const glm::vec3& vel);
	void setAcceleration(const glm::vec3& accel);
	void setMass(float m);

	/**
	 * @brief Applies a force to the particle, updating its acceleration.
	 *
	 * This function calculates the change in acceleration due to the applied force using
	 * Newton's second law (F = ma, rearranged to a = F/m) and adds it to the particle's
	 * existing acceleration.
	 *
	 * @param force The force vector to apply to the particle. This is a 3D vector representing
	 * the force in x, y, and z directions. Units should be consistent (e.g., Newtons).
	 */
	void applyForce(const glm::vec3& force);

private:
	glm::vec3 position;
	glm::vec3 velocity;
	glm::vec3 acceleration;
	float mass;
};
