#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Particle.h"

int main()
{
    // Enable anti-aliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity Simulation", sf::Style::Default, settings);

    std::vector<Particle> particles;
    particles.push_back({100.0f, 100.0f, 10.0f, 20.0f, 0.0f, 0.0f});
    particles.push_back({200.0f, 200.0f, 10.0f, 20.0f, 0.0f, 0.0f});

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

            }

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


