#pragma once

#include <SFML/Graphics.hpp>

class Field
{

	sf::RectangleShape rectangle;
	sf::Font font;
	int fontSize;
	sf::Color colorFont;
	sf::Color colorBack;
	sf::Text text;
	sf::Vector2f position;
	sf::Vector2f size;


protected:
	std::string txt;
	bool active;

public:
	Field();
	//Construct
	Field(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color colorFont, int fontSize);
	//Construct copy
	Field(const Field& otherField);

	void render(sf::RenderWindow& window);
	void setText(std::string str);
	std::string getText();
	void changeBackColor(sf::Color colorBack);
	void changeFontColor(sf::Color colorFont);
	sf::RectangleShape& getRectangle();
	sf::Color getFontColor();
	sf::Color getBackColor();

	bool getActive();
	void setActive(bool status);

};

