#pragma once

#include "Element.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Field.h"
#include "InputField.h"

class NavWindow
{

private:
	Element* activeElement = nullptr;
	std::vector<Element> elements;
	sf::RectangleShape rectangle;
	sf::Vector2f position;
	sf::Text text;
	sf::Font font;
	InputField inputField;
	bool actBox = false;

public:
	NavWindow(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color color—ontour);
	void removeElement();
	void addElement(Element);
	void render(sf::RenderWindow& window);
	bool getActBox();
	void setActBox(bool flag);
};

