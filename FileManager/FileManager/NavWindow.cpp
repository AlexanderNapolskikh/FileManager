#include "NavWindow.h"


NavWindow::NavWindow(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color color—ontour) :
	rectangle(size)
{
	// Position
	this->position = position;

	// Rectangle
	rectangle.setFillColor(colorBack);
	rectangle.setPosition(position);
	rectangle.setOutlineColor(color—ontour);
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



