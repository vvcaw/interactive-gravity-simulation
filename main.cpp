#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Particle.h"
#include "calculate.h"

int main()
{
    // Enable anti-aliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity Simulation", sf::Style::Default, settings);

    std::vector<Particle> particles;
    particles.push_back({200.0f, 250.0f, 10.0f, 20.0f, 0.0f, 0.0f, 0.0f, 0.0f});
    particles.push_back({400.0f, 250.0f, 10.0f, 20.0f, 0.0f, 0.0f, 0.0f, 0.0f});

    int timeElapsed = 1;

    // Run the program as long as the window is open
    while (window.isOpen())
    {
        // Check all events since last iteration
        sf::Event event{};
        while (window.pollEvent(event))
        {
            // Close window when requested
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear window
        window.clear(sf::Color::Black);

        for (auto& p0 : particles) {
            for (auto& p1 : particles) {
                if (&p0 == &p1)
                    continue;

                float dist = distance(p0, p1);
                float force = gravitational_force(p0, p1, dist);

                // F = m * a => a = F / m
                float acceleration = force / p0.m;

                // Update acceleration
                p0.ax += acceleration * (delta_x(p0, p1) / dist);
                p0.ay += acceleration * (delta_y(p0, p1) / dist);
            }

            // Update position with velocity from last iteration (initial velocity) and acceleration
            // s = ut + (1/2)at^2
            p0.x += p0.vx * timeElapsed + .5f * p0.ax * timeElapsed * timeElapsed;
            p0.y += p0.vy * timeElapsed + .5f * p0.ay * timeElapsed * timeElapsed;

            // Update velocity of particle after moving it
            p0.vx += p0.ax * timeElapsed;
            p0.vy += p0.ay * timeElapsed;

            std::cout << p0.x << std::endl;

            // Draw each individual particle
            sf::CircleShape shape(p0.r);
            shape.setPosition(p0.x, p0.y);
            shape.setFillColor(sf::Color(100, 250, 50));
            window.draw(shape);
        }

        // Draw current state of window
        window.display();
    }

    return 0;
}


