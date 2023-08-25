#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include <iostream>

class Button
{
private:

	sf::RectangleShape rectangle;
	sf::Font font;
	int fontSize;
	sf::Color colorFont;
	sf::Text text;
	sf::Vector2f position;
	sf::Vector2f size;

public:

	Button(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color colorFont, int fontSize);
	void render(sf::RenderWindow& window);
	void setText(std::string str);
	void changeBackColor(sf::Color colorBack);
	void changeFontColor(sf::Color colorFont);
	sf::RectangleShape& getRectangle();
	sf::Color getFontColor();
	sf::Color getBackColor();
};

