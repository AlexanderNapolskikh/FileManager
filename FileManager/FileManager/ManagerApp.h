#pragma once

#include "UI.h"
#include "NavWindow.h"

class ManagerApp
{

private:

	sf::RenderWindow window;
	UI buttons;
	NavWindow navLeft;
	NavWindow navRight;

public:
	ManagerApp();
	void run();

private:
	void processEvent();
	void update();
	void render();
	void moveElement();
	void removeElement();
	void copyElement();
};
