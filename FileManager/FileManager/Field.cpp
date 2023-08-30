#include "Field.h"
#include "Config.h"

Field::Field()
{
}

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

	text.setFillColor(colorFont);
	text.setCharacterSize(fontSize);
	text.setPosition(position.x + 10, position.y + BUTTON_SIZE / 2 - fontSize / 2);
}

Field::Field(const Field& otherField)
{
	this->size = otherField.size;
	this->position = otherField.position;
	this->colorBack = otherField.colorBack;
	this->colorFont = otherField.colorFont;
	this->fontSize = fontSize;
	this->text = otherField.text;
	this->font = otherField.font;

	this->rectangle = otherField.rectangle;
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

bool Field::getActive()
{
	return active;
}

void Field::setActive(bool status)
{
	active = status;
	(!active) ? rectangle.setFillColor(colorBack) : rectangle.setFillColor(sf::Color::Color(205, 92, 92));
}
