#pragma once
#include "Particle.h"

double distance(Particle& src, Particle& dst);
double delta_x(Particle& src, Particle& dst);
double delta_y(Particle& src, Particle& dst);
double gravitational_force(Particle& p0, Particle& p1, double radius);