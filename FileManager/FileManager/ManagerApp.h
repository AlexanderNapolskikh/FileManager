#pragma once

#include "NavWindow.h"
#include "Button.h"
#include<vector>

class ManagerApp
{

private:

	sf::RenderWindow window;
	// Окна навигации
	NavWindow navLeft;
	NavWindow navRight;
	// Кнопки управления
	Button butMove;
	Button butCopy;
	Button butDelt;

	// Oper
	std::string operation = "";

public:
	ManagerApp();
	void run();

private:
	void processEvent();
	void update();
	void render();
	void moveField();
	void copyField();
	void removeField();
};

