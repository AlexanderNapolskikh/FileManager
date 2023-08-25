#pragma once

#include "Button.h"

class UI
{

private:
	std::vector<Button> buttons;
	std::vector<std::string> fields;

public:
	void push();
};
