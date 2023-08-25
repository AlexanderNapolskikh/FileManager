#include "NavWindow.h"


NavWindow::NavWindow(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color colorÑontour) :
	rectangle(size),
	inputField(sf::Vector2f(SIZE_NAV_W, 40), position, sf::Color::Color(135, 206, 235), colorÑontour, 24)
{
	// Position
	this->position = position;

	// Rectangle
	rectangle.setFillColor(colorBack);
	rectangle.setPosition(position);
	rectangle.setOutlineColor(colorÑontour);
	rectangle.setOutlineThickness(3);

	// TextBox
	this->inputField.setText("C:\\\\");
}

void NavWindow::render(sf::RenderWindow& window)
{
	window.draw(rectangle);
	inputField.render(window);
}

bool NavWindow::getActBox()
{
	return actBox;
}

void NavWindow::setActBox(bool flag)
{
	actBox = flag;
}

void NavWindow::removeElement()
{

}

void NavWindow::addElement(Element)
{

}



