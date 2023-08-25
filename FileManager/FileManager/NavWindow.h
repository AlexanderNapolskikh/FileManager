#pragma once

#include "Element.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Config.h"

class NavWindow
{

private:
	Element* activeElement = nullptr;
	std::vector<Element> elements;
	sf::RectangleShape rectangle;
	sf::Vector2f position;

public:
	NavWindow(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color color—ontour);
	void removeElement();
	void addElement(Element);
	void render(sf::RenderWindow& window);
};


