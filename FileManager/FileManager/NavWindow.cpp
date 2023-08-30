#include "NavWindow.h"


NavWindow::NavWindow(sf::Vector2f size, sf::Vector2f position, sf::Color colorBack, sf::Color colorContour) :
	rectangle(size),
	inputField(sf::Vector2f(350, BUTTON_SIZE), position, sf::Color::Color(135, 206, 235), colorContour, 24)
{
	// Position
	this->position = position;

	// Rectangle
	rectangle.setFillColor(colorBack);
	rectangle.setPosition(position);
	rectangle.setOutlineColor(colorContour);
	rectangle.setOutlineThickness(3);

	// TextBox
	this->inputField.setText("C:\\\\");

	// Add fields
	for (int i = 0; i < 6; i++)
	{
		addField(Field(sf::Vector2f(350, BUTTON_SIZE), sf::Vector2f(position.x, position.y + (i + 1) * BUTTON_SIZE), sf::Color::Color(95, 158, 160), colorContour, 24));
		fields[fields.size() - 1].setText("Hello " + std::to_string(i));
	}
}

void NavWindow::render(sf::RenderWindow& window)
{
	window.draw(rectangle);
	inputField.render(window);

	for (auto el : fields)
	{
		el.render(window);
	}
}

void NavWindow::processEvent(sf::Event& event, sf::RenderWindow& window)
{

	// Проверка проклацивания мыши
	if (event.type == sf::Event::MouseButtonReleased) {

		sf::Vector2f localPosition(event.mouseButton.x, event.mouseButton.y);

		if (inputField.getRectangle().getGlobalBounds().contains(localPosition)) {

			inputField.setActive(true);
			activeField = &inputField;
		}
		else {

			inputField.setActive(false);
		}

		int count = 0;
		for (auto i : fields)
		{
			if (i.getRectangle().getGlobalBounds().contains(localPosition)) {
				fields[count].setActive(true);
				activeField = &fields[count];
			}
			else {
				fields[count].setActive(false);
			}
			count++;
		}

	}

	// Ввод текста в ведущее окно
	if (inputField.getActive()) {

		if (event.type == sf::Event::TextEntered) {
			std::cout << " in type!" << std::endl;


			if (event.KeyPressed) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {

					inputField.setText(inputField.getText().erase(inputField.getText().size() - 1));
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

					inputField.setActive(false);
				}
				else
				{
					char buf = static_cast<char>(event.text.unicode);
					inputField.setText(inputField.getText() + buf);
				}
			}

		}

	}

}

Field* NavWindow::getActField()
{
	return activeField;
}

void NavWindow::removeField()
{
	for (int i = 0; i < fields.size(); i++)
	{
		if (fields[i].getActive()) {

			// Удаление
			fields.erase(fields.begin() + i);
			break;
		}
	}

	std::vector<Field> buf = fields;
	fields.clear();

	for (int i = 0; i < buf.size(); i++)
	{
		addField(Field(sf::Vector2f(350, BUTTON_SIZE), sf::Vector2f(position.x, position.y + (i + 1) * BUTTON_SIZE), sf::Color::Color(95, 158, 160), sf::Color::White, 24));
		fields[fields.size() - 1].setText(buf[i].getText());
	}
}

void NavWindow::addField(Field field)
{
	this->fields.push_back(field);
}