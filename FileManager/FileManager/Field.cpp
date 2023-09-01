#include "Field.h"
#include "Config.h"

Field::Field(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color colorFont, int fontSize) :
	rectangle(size)
{

	this->active = false;

	this->colorFont = colorFont;
	this->colorBack = colorBack;
	this->fontSize = fontSize;
	this->position = position;

	rectangle.setFillColor(colorBack);
	rectangle.setPosition(position);

	font.loadFromFile("arial.ttf");
	text.setCharacterSize(fontSize);
	text.setFont(font);

}

void Field::render(sf::RenderWindow& window)
{
	window.draw(rectangle);
	text.setFont(font);
	text.setPosition(position.x + 10, position.y + BUTTON_SIZE / 2 - fontSize / 2);

	font.loadFromFile("arial.ttf");
	text.setCharacterSize(fontSize);
	text.setFillColor(colorFont);

	window.draw(text);
}

void Field::setText(std::string str)
{
	this->text.setString(str);
	txt = str;
}

std::string Field::getText()
{
	return txt;
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

sf::Vector2f Field::getSize()
{
	return size;
}

sf::Vector2f Field::getPosition()
{
	return position;
}

bool Field::getActive()
{
	return active;
}

void Field::setActive(bool status)
{
	active = status;
	(!active) ? rectangle.setFillColor(colorBack) : rectangle.setFillColor(sf::Color::Color(205, 92, 92));
}
