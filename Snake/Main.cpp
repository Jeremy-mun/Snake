#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char * argv[])
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");

	sf::RectangleShape head(sf::Vector2f(25, 25));
	head.setFillColor(sf::Color::Green);
	head.setPosition(400, 400);

	sf::Font myFont;

	if (!myFont.loadFromFile("fonts/arial.ttf"))
	{
		std::cerr << "Could not load font!\n";
		exit(-1);
	}

	sf::Text score("Score", myFont, 24);
	score.setPosition(0, 0);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(head);
		window.draw(score);
		window.display();
	}

	return 0;
}