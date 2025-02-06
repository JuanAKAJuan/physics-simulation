#include "particle.h"

Particle::Particle(const glm::vec3& pos, const glm::vec3& vel, float m, const SDL_Color& col, int sz)
	: position(pos), velocity(vel), mass(m), color(col), size(sz) {}

const glm::vec3& Particle::getPosition() const { return position; }
const glm::vec3& Particle::getVelocity() const { return velocity; }
const glm::vec3& Particle::getAcceleration() const { return acceleration; }
float Particle::getMass() const { return mass; }
const SDL_Color& Particle::getColor() const { return color; }
int Particle::getSize() const { return size; }

void Particle::setPosition(const glm::vec3& pos) { position = pos; }
void Particle::setVelocity(const glm::vec3& vel) { velocity = vel; }
void Particle::setAcceleration(const glm::vec3& accel) { acceleration = accel; }
void Particle::setMass(float m) { mass = m; }
void Particle::setColor(const SDL_Color& col) { color = col; }
void Particle::setSize(const int sz) { size = sz; }

void Particle::applyForce(const glm::vec3& force) { acceleration += force / mass; }
