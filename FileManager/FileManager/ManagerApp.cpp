
#include "ManagerApp.h"
#include "NavWindow.h"
#include <SFML/Graphics.hpp>

ManagerApp::ManagerApp() :
	window(sf::VideoMode(WINDOW_W, WINDOW_H), "(_//- File Manager -//_)"),
	navLeft(sf::Vector2f(350, WINDOW_H), sf::Vector2f(0, 0), sf::Color::Color(127, 255, 212), sf::Color::White),
	navRight(sf::Vector2f(350, WINDOW_H), sf::Vector2f(WINDOW_W - 350, 0), sf::Color::Color(127, 255, 212), sf::Color::White),
	butMove(sf::Vector2f(WINDOW_W - 700, BUTTON_SIZE * 3), sf::Vector2f(353, BUTTON_SIZE), sf::Color::Color(255, 222, 173), sf::Color::Black, FONT_SIZE),
	butCopy(sf::Vector2f(WINDOW_W - 700, BUTTON_SIZE * 3), sf::Vector2f(353, BUTTON_SIZE + BUTTON_SIZE * 3), sf::Color::Color(144, 238, 144), sf::Color::Black, FONT_SIZE),
	butDelt(sf::Vector2f(WINDOW_W - 700, BUTTON_SIZE * 3), sf::Vector2f(353, BUTTON_SIZE + BUTTON_SIZE * 6), sf::Color::Color(240, 128, 128), sf::Color::Black, FONT_SIZE)
{
	butMove.setText("Move\n\n   ->\n   <-");
	butCopy.setText("Copy\n\n   ->\n   <-");
	butDelt.setText("Delete\n\n    X");
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

		if (operation == "D") {

			removeField();
			operation = "";
		}
		else if(operation == "M"){

			moveField();
			operation = "";
		}
		else if (operation == "C") {

			copyField();
			operation = "";
		}

		if (event.type == sf::Event::MouseButtonPressed) {

			sf::Vector2f localPosition(event.mouseButton.x, event.mouseButton.y);

			if (butMove.getRectangle().getGlobalBounds().contains(localPosition)) {

				sf::Color buf = butMove.getBackColor();

				butMove.changeBackColor(butMove.getFontColor());
				butMove.changeFontColor(buf);

				operation = "M";
			}
			else if (butCopy.getRectangle().getGlobalBounds().contains(localPosition)) {

				sf::Color buf = butCopy.getBackColor();

				butCopy.changeBackColor(butCopy.getFontColor());
				butCopy.changeFontColor(buf);

				operation = "C";
			}
			else if (butDelt.getRectangle().getGlobalBounds().contains(localPosition)) {

				sf::Color buf = butDelt.getBackColor();

				butDelt.changeBackColor(butDelt.getFontColor());
				butDelt.changeFontColor(buf);

				operation = "D";
			}
		}

		if (event.type == sf::Event::MouseButtonReleased) {

			sf::Vector2f localPosition(event.mouseButton.x, event.mouseButton.y);

			if (butMove.getRectangle().getGlobalBounds().contains(localPosition)) {

				sf::Color buf = butMove.getBackColor();

				butMove.changeBackColor(butMove.getFontColor());
				butMove.changeFontColor(buf);
			}
			else if (butCopy.getRectangle().getGlobalBounds().contains(localPosition)) {

				sf::Color buf = butCopy.getBackColor();

				butCopy.changeBackColor(butCopy.getFontColor());
				butCopy.changeFontColor(buf);
			}
			else if (butDelt.getRectangle().getGlobalBounds().contains(localPosition)) {

				sf::Color buf = butDelt.getBackColor();

				butDelt.changeBackColor(butDelt.getFontColor());
				butDelt.changeFontColor(buf);
			}
		}

		navLeft.processEvent(event, window);
		navRight.processEvent(event, window);
	}

}

void ManagerApp::update()
{
	navLeft.createFields();
	navRight.createFields();
}

void ManagerApp::render()
{
	window.clear(sf::Color::Color(47, 79, 79));

	navLeft.render(window);

	butMove.render(window);
	butCopy.render(window);
	butDelt.render(window);

	navRight.render(window);

	window.display();
}

void ManagerApp::moveField()
{

}

void ManagerApp::copyField()
{
	if (navLeft.getActField() != nullptr) {
		navRight.addField(Field{ *navLeft.getActField() });
	}else if (navRight.getActField() != nullptr) {
		navLeft.addField(Field{ *navRight.getActField() });
	}
}

void ManagerApp::removeField()
{
	navLeft.removeField();
	navRight.removeField();
}

