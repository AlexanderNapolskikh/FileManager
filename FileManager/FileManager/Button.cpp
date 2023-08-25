#include "Button.h"

Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color colorFont, int fontSize) :
	rectangle(size)
{
	this->fontSize = fontSize;
	this->colorFont = colorBack;
	this->position = position;

	rectangle.setFillColor(colorBack);
	rectangle.setPosition(position);
	rectangle.setOutlineColor(colorFont);
	rectangle.setOutlineThickness(3);
}

void Button::render(sf::RenderWindow& window)
{
	window.draw(rectangle);

	text.setFont(font);
	font.loadFromFile("arial.ttf");
	text.setCharacterSize(fontSize);
	text.setPosition(position.x + BUTTON_SIZE / 2 - fontSize / 2, position.y + BUTTON_SIZE / 2 - fontSize / 2);
	window.draw(text);
}

void Button::setText(std::string str)
{
	this->text.setString(str);
}

void Button::changeBackColor(sf::Color colorBack)
{
	rectangle.setFillColor(colorBack);
}

void Button::changeFontColor(sf::Color colorFont)
{
	this->colorFont = colorFont;
	text.setFillColor(colorFont);
}

sf::RectangleShape& Button::getRectangle()
{
	return this->rectangle;
}

sf::Color Button::getFontColor()
{
	return colorFont;
}

sf::Color Button::getBackColor()
{
	return rectangle.getFillColor();
}


