#pragma once

#include <SFML/Graphics/CircleShape.hpp>

struct Particle {
    double x;
    double y;
    double m;
    double r;
    double ax;
    double ay;
    double vx;
    double vy;
    bool isStatic;
    sf::CircleShape shape;
};