#include "Field.h"
#include "Config.h"

Field::Field(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color colorFont, int fontSize) :
	rectangle(size)
{

	this->colorFont = colorFont;
	this->fontSize = fontSize;
	this->position = position;

	rectangle.setFillColor(colorBack);
	rectangle.setPosition(position);
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setOutlineThickness(3);

	text.setFillColor(colorFont);
	text.setCharacterSize(fontSize);
	text.setPosition(position.x, position.y + BUTTON_SIZE / 2 - fontSize / 2);
}

void Field::render(sf::RenderWindow& window)
{
	window.draw(rectangle);

	text.setFont(font);
	font.loadFromFile("arial.ttf");

	window.draw(text);
}

void Field::setText(std::string str)
{
	this->text.setString(str);
}

void Field::changeBackColor(sf::Color colorBack)
{
	rectangle.setFillColor(colorBack);
}

void Field::changeFontColor(sf::Color colorFont)
{
	this->colorFont = colorFont;
	text.setFillColor(colorFont);
}

sf::RectangleShape& Field::getRectangle()
{
	return this->rectangle;
}

sf::Color Field::getFontColor()
{
	return colorFont;
}

sf::Color Field::getBackColor()
{
	return rectangle.getFillColor();
}