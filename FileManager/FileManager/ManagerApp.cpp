
#include "ManagerApp.h"
#include "NavWindow.h"
#include <SFML/Graphics.hpp>

ManagerApp::ManagerApp() :
	window(sf::VideoMode(WINDOW_W, WINDOW_H), "(_//- File Manager -//_)"),
	navLeft(sf::Vector2f(350, WINDOW_H), sf::Vector2f(0, 0), sf::Color::Color(210, 105, 30), sf::Color::White),
	navRight(sf::Vector2f(350, WINDOW_H), sf::Vector2f(WINDOW_W - 350, 0), sf::Color::Color(210, 105, 30), sf::Color::White)
{
}

void ManagerApp::run()
{
	while (window.isOpen())
	{
		processEvent();
		update();
		render();
	}
}

void ManagerApp::processEvent()
{

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

void ManagerApp::update()
{

}

void ManagerApp::render()
{
	window.clear();

	navLeft.render(window);

	navRight.render(window);

	window.display();
}

void ManagerApp::moveElement()
{

}

void ManagerApp::removeElement()
{

}

void ManagerApp::copyElement()
{

}
