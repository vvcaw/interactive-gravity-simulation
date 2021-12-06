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
    sf::RenderWindow window(sf::VideoMode(600, 600), "Gravity Simulation", sf::Style::Default, settings);

    std::vector<Particle> particles;
    particles.push_back({200.0, 100.0, 1.0, 5.0, 0.0, 0.0, 0.0, 0.0, false, sf::CircleShape(5.0)});
    particles.push_back({370.0, 280.0, 10000.0, 15.0, 0.0, 0.0, 0.0, 0.0, true, sf::CircleShape(15.0)});
    particles.push_back({250.0, 350.0, 10000.0, 15.0, 0.0, 0.0, 0.0, 0.0, true, sf::CircleShape(15.0)});

    window.setFramerateLimit(200.0f);

    // Setup sfml clock
    sf::Clock clock;

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

        // Restart clock for next iteration here, then elapsed time in next iteration is correct
        double elapsed = clock.restart().asMilliseconds() / 1000.0;

        std::cout << particles.size() << std::endl;

        for (int i = 0; i < particles.size(); ++i) {
            Particle& p0 = particles[i];

            // Reset acceleration
            p0.ax = p0.ay = 0.0;

            bool toBeDeleted = false;

            // Don't evaluate force of self if static
            if (!p0.isStatic) {
                for (auto& p1 : particles) {
                    // Don't evaluate force on self
                    if (&p0 == &p1)
                        continue;

                    double dist = distance(p0, p1);
                    double force = gravitational_force(p0, p1, dist);

                    // F = m * a => a = F / m
                    double acceleration = force / p0.m;

                    if (dist < p1.r) {
                        toBeDeleted = true;
                    }

                    // Update acceleration
                    p0.ax += acceleration * (delta_x(p0, p1) / dist);
                    p0.ay += acceleration * (delta_y(p0, p1) / dist);
                }

                if (toBeDeleted) {
                    particles.erase(particles.begin() + i);
                    continue;
                }

                // Update velocity
                p0.vx += p0.ax * elapsed;
                p0.vy += p0.ay * elapsed;

                // Update position based on velocity
                p0.x += p0.vx * elapsed;
                p0.y += p0.vy * elapsed;
            }

            // Draw each individual particle
            p0.shape.setPosition((float) p0.x, (float) p0.y);
            p0.shape.setFillColor(sf::Color(100, 250, 50));
            window.draw(p0.shape);
        }

        // Draw current state of window
        window.display();
    }

    return 0;
}


