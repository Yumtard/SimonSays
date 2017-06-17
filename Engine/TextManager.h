#pragma once

#include "Text.h"
#include "Graphics.h"

class TextManager
{
public:
	TextManager();
	void Update(int score);
	void Draw(Graphics& gfx, int score);
private:
	Text firstNumber;
	Text secondNumber;
	Text thirdNumber;
};