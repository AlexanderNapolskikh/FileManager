#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Field.h"
#include "InputField.h"
#include <iostream>

class NavWindow
{

private:
	Field* activeField = nullptr;
	std::vector<Field> fields;
	sf::RectangleShape rectangle;
	sf::Vector2f position;
	sf::Text text;
	sf::Font font;
	InputField inputField;

public:
	NavWindow(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color color—ontour);
	void removeField();
	void addField(Field field);
	void render(sf::RenderWindow& window);
	void processEvent(sf::Event& event, sf::RenderWindow& window);
	Field* getActField();
};
