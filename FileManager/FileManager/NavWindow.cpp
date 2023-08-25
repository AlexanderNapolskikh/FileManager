#include "NavWindow.h"


NavWindow::NavWindow(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color colorŅontour) :
	rectangle(size)
{
	// Position
	this->position = position;

	// Rectangle
	rectangle.setFillColor(colorBack);
	rectangle.setPosition(position);
	rectangle.setOutlineColor(colorŅontour);
	rectangle.setOutlineThickness(3);
}

void NavWindow::render(sf::RenderWindow& window)
{
	window.draw(rectangle);
}

void NavWindow::removeElement()
{

}

void NavWindow::addElement(Element)
{

}



