#include "Level.h"


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	text.setFont(font);
	text.setCharacterSize(32);
	text.setFillColor(sf::Color::Black);
	// initialise game objects

}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	sf::Vector2i mousePos;
	mousePos = mouse.getPosition();

	std::string outTextX = std::to_string(mousePos.x);
	std::string outTextY = std::to_string(mousePos.y);

	std::string outText = ("x=" + outTextX + ", y=" + outTextY);

	text.setString(outText);

	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W\n";
	}
	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J);
		std::cout << "JKL\n";
	}
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font.\n";
	}

}

// Update game objects
void Level::update()
{

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(text);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}