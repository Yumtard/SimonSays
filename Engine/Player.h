#pragma once

#include "PlayField.h"
#include <vector>
#include "Mouse.h"

class Player
{
public:
	bool UserInput(Mouse& mouse, PlayField& playField, int n);
	std::vector<int> GetChoices() const;
	void Reset();
	void HandleClick(PlayField& playField, int color);

private:
	std::vector<int> choices;
	bool inhibitMouse = false;
	int numChoices = 0;
	static constexpr int red = 1;
	static constexpr int blue = 2;
	static constexpr int yellow = 3;
	static constexpr int green = 4;
};