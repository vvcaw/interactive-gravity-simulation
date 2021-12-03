#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Particle.h"
#include <chrono>
#include "calculate.h"

int main()
{
    using clock = std::chrono::high_resolution_clock;

    // Enable anti-aliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity Simulation", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);

    std::vector<Particle> particles;
    particles.push_back({200.0, 250.0, 5000.0, 20.0, 0.0, 0.0, 0.0, 100.0, sf::CircleShape(20.0)});
    particles.push_back({400.0, 250.0, 1000.0, 20.0, 0.0, 0.0, 0.0, 0.0, sf::CircleShape(20.0)});

    auto last = clock::now();

    window.setFramerateLimit(60.0f);

    int i = 0;
    sf::CircleShape rect1(5.0);
    sf::CircleShape rect2(5.0);
    rect2.setPosition(5.0, 0.0);

    // Run the program as long as the window is open
    while (window.isOpen())
    {
        window.clear(sf::Color::Black);
        // Check all events since last iteration
        /*sf::Event event{};
        while (window.pollEvent(event))
        {
            // Close window when requested
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear window
        window.clear(sf::Color::Black);

        // Restart clock for next iteration here, then elapsed time in next iteration is correct
        auto now = clock::now();
        auto elapsed = ((double) std::chrono::duration_cast<std::chrono::microseconds>(now - last).count()) / 1000000.0;
        last = now;

        if (elapsed > 0.017) {
            std::cout << elapsed << std::endl;
        }

        for (auto& p0 : particles) {

            p0.ax = p0.ay = 0.0;

            *//*for (auto& p1 : particles) {
                if (&p0 == &p1)
                    continue;

                double dist = distance(p0, p1);
                double force = gravitational_force(p0, p1, dist);

                // F = m * a => a = F / m
                double acceleration = force / p0.m;

                // Update acceleration
                p0.ax += acceleration * (delta_x(p0, p1) / dist);
                p0.ay += acceleration * (delta_y(p0, p1) / dist);
            }*//*

            double lastX = p0.x;
            double lastY = p0.y;

            // Update position with velocity from last iteration (initial velocity) and acceleration
            // s = ut + (1/2)at^2
            p0.vx += p0.ax * elapsed;
            p0.vy += p0.ay * elapsed;

            p0.x += p0.vx * elapsed;
            p0.y += p0.vy * elapsed;

            //std::cout << p0.x - lastX << std::endl;
            //std::cout << p0.y - lastY << std::endl;

            // Draw each individual particle
            p0.shape.setPosition((float) p0.x, (float) p0.y);
            p0.shape.setFillColor(sf::Color(100, 250, 50));
            window.draw(p0.shape);



        }*/

        auto now = clock::now();
        auto elapsed = ((double) std::chrono::duration_cast<std::chrono::microseconds>(now - last).count()) / 1000000.0;
        last = now;


            std::cout << elapsed << std::endl;


        if (i % 2 == 0) {
            window.draw(rect1);
        } else {
            window.draw(rect2);
        }
        i++;

        // Draw current state of window
        window.display();
    }

    return 0;
}


