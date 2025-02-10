#pragma once

#include <raylib.h>
#include <raymath.h>

class Particle {
public:
	Particle(const Vector3& pos, const Vector3& vel, float m, const Color& col, int sz);

	const Vector3& getPosition() const;
	const Vector3& getVelocity() const;
	const Vector3& getAcceleration() const;
	float getMass() const;
	const Color& getColor() const;
	int getSize() const;

	void setPosition(const Vector3& pos);
	void setVelocity(const Vector3& vel);
	void setAcceleration(const Vector3& accel);
	void setMass(float m);
	void setColor(const Color& col);
	void setSize(const int sz);

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
	void applyForce(const Vector3& force);

private:
	Vector3 position;
	Vector3 velocity;
	Vector3 acceleration;
	float mass;
	Color color;
	int size;
};
