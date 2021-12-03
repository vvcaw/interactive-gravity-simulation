#include <cmath>
#include "Particle.h"

// Custom gravitational constant
#define G 1.0

double distance(Particle& src, Particle& dst) {
    return std::sqrt((dst.x - src.x) * (dst.x - src.x) + (dst.y - src.y) * (dst.y - src.y));
}

double delta_x(Particle& src, Particle& dst) {
    return (dst.x - src.x);
}

double delta_y(Particle& src, Particle& dst) {
    return (dst.y - src.y);
}

double gravitational_force(Particle& p0, Particle& p1, double radius) {
    return G * (p0.m * p1.m) / (radius * radius);
}