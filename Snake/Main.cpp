#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <time.h>

int main(int argc, char * argv[])
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");

	window.setFramerateLimit(10);

	sf::RectangleShape head(sf::Vector2f(10, 10));
	head.setFillColor(sf::Color::Green);
	head.setPosition(400, 400);

	float headMoveSpeedX = 0.0;
	float headMoveSpeedY = 0.0;

	srand(time(NULL));

	sf::CircleShape apple(5.0);
	apple.setFillColor(sf::Color::Red);
	apple.setPosition(((rand() % 80) * 10), ((rand() % 55) * 10) + 50);

	sf::Font myFont;

	if (!myFont.loadFromFile("fonts/arial.ttf"))
	{
		std::cerr << "Could not load font!\n";
		exit(-1);
	}

	int points = 0;
	sf::Text score("Score: " + std::to_string(points), myFont, 24);
	score.setPosition(0, 0);

	sf::Text gameOver("GameOver", myFont, 50);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
				{
					headMoveSpeedX = 0.0f;
					headMoveSpeedY = -10.0f;
				}
				else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
				{
					headMoveSpeedX = 0.0f;
					headMoveSpeedY = 10.0f;
				}
				else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
				{
					headMoveSpeedX = -10.0f;
					headMoveSpeedY = 0.0f;
				}
				else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
				{
					headMoveSpeedX = 10.0f;
					headMoveSpeedY = 0.0f;
				}
				break;
			}
		}

		head.setPosition(head.getPosition() + sf::Vector2f(headMoveSpeedX, headMoveSpeedY));

		if (head.getPosition().x < 0 || head.getPosition().x >= 800 || head.getPosition().y < 50 || head.getPosition().y >= 600)
		{
			gameOver.setPosition(400, 300);
			window.clear();
			window.draw(gameOver);
			window.draw(score);
			window.display();
			while (window.isOpen())
			{
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						window.close();
					}
				}
			}
		}
		if (head.getPosition() == apple.getPosition())
		{ 
			++points;
			score.setString("Score: " + std::to_string(points));
			apple.setPosition(((rand() % 80) * 10), ((rand() % 55) * 10) + 50);
		}

		window.clear();
		window.draw(apple);
		window.draw(head);
		window.draw(score);
		window.display();
	}

	return 0;
}