#include <cmath>
#include "Particle.h"

// Custom gravitational constant
#define G 300.0

double distance(Particle& src, Particle& dst) {
    return std::sqrt((dst.x + dst.r - src.x + src.r) * (dst.x + dst.r - src.x + src.r) + (dst.y + dst.r - src.y + src.r) * (dst.y + dst.r - src.y + src.r));
}

double delta_x(Particle& src, Particle& dst) {
    return (dst.x + dst.r - src.x + src.r);
}

double delta_y(Particle& src, Particle& dst) {
    return (dst.y + dst.r - src.y + src.r);
}

double gravitational_force(Particle& p0, Particle& p1, double radius) {
    return G * (p0.m * p1.m) / (radius * radius);
}