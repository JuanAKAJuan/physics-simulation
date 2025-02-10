#include "particle.h"

Particle::Particle(const Vector3& pos, const Vector3& vel, float m, const Color& col, int sz)
	: position(pos), velocity(vel), mass(m), color(col), size(sz) {}

const Vector3& Particle::getPosition() const { return position; }
const Vector3& Particle::getVelocity() const { return velocity; }
const Vector3& Particle::getAcceleration() const { return acceleration; }
float Particle::getMass() const { return mass; }
const Color& Particle::getColor() const { return color; }
int Particle::getSize() const { return size; }

void Particle::setPosition(const Vector3& pos) { position = pos; }
void Particle::setVelocity(const Vector3& vel) { velocity = vel; }
void Particle::setAcceleration(const Vector3& accel) { acceleration = accel; }
void Particle::setMass(float m) { mass = m; }
void Particle::setColor(const Color& col) { color = col; }
void Particle::setSize(const int sz) { size = sz; }

void Particle::applyForce(const Vector3& force) {
	Vector3 scaledForce = Vector3Scale(force, 1.0f / mass);
	acceleration = Vector3Add(acceleration, scaledForce);
}
