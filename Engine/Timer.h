#pragma once

#include "Graphics.h"

class Timer
{
public:
	void Draw(Graphics& gfx);
	void Update();
	void Reset();
	int GetTime() const;

private:
	static constexpr int x = 245;
	static constexpr int y = 500;
	static constexpr int padding = 5;
	static constexpr int bgWidth = 310;
	static constexpr int height = 20; 
	int timeWidth = bgWidth - (padding * 2);
	static constexpr int maxTime = bgWidth - (padding * 2);
	Color darkGray = Color(55, 55, 55);
};