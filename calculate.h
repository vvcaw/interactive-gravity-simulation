#pragma once
#include "Particle.h"

float distance(Particle& src, Particle& dst);
float delta_x(Particle& src, Particle& dst);
float delta_y(Particle& src, Particle& dst);
float gravitational_force(Particle& p0, Particle& p1, float radius);