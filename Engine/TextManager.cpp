#include "TextManager.h"

TextManager::TextManager()
	:
	firstNumber(600, 490, Text::Order::first),
	secondNumber(635, 490, Text::Order::second),
	thirdNumber(670, 490, Text::Order::third)
{
}

void TextManager::Update(int score)
{
	firstNumber.Update(score);
	secondNumber.Update(score);
	thirdNumber.Update(score);
}

void TextManager::Draw(Graphics & gfx, int score)
{
	firstNumber.Draw(gfx, score);
	secondNumber.Draw(gfx, score);
	thirdNumber.Draw(gfx, score);
}

