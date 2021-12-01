#include <cmath>
#include "Particle.h"

// Custom gravitational constant
#define G 0.003f

float distance(Particle& src, Particle& dst) {
    return std::sqrt((dst.x - src.x) * (dst.x - src.x) + (dst.y - src.y) * (dst.y - src.y));
}

float delta_x(Particle& src, Particle& dst) {
    return (dst.x - src.x);
}

float delta_y(Particle& src, Particle& dst) {
    return (dst.y - src.y);
}

float gravitational_force(Particle& p0, Particle& p1, float radius) {
    return G * (p0.m * p1.m) / (radius * radius);
}