#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

struct

int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // Run the program as long as the window is open
    while (window.isOpen())
    {
        // Check all events since last iteration
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window when requested
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear window
        window.clear(sf::Color::Black);

        sf::CircleShape shape(50.f);

        // set the shape color to green
        shape.setFillColor(sf::Color(100, 250, 50));
        window.draw(shape);


        // end the current frame
        window.display();
    }

    return 0;
}


