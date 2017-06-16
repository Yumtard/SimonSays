#pragma once

#include "Graphics.h"
#include "Colors.h"
#include "Timer.h"
#include "Sound.h"

class PlayField
{
public:
	void Update();
	void Draw(Graphics& gfx);
	Color Green();
	Color Red();
	Color Blue();
	Color Yellow();
	void Flash(int color);
	void Reset();
	bool OverLapsRed(int in_x, int in_y);
	bool OverLapsGreen(int in_x, int in_y);
	bool OverLapsBlue(int in_x, int in_y);
	bool OverLapsYellow(int in_x, int in_y);
	void UpdateTimer();
	void ResetTimer();
	bool TimeOver() const;

private:
	static constexpr int x = 245;
	static constexpr int y = 145;
	static constexpr int dim = 150;
	static constexpr int padding = 10;
	bool yellowIsFlashing = false;
	bool redIsFlashing = false;
	bool blueIsFlashing = false;
	bool greenIsFlashing = false;
	int flashCounter = 0;
	static constexpr int flashOver = 30;
	Timer timer;
	Sound redSound = L"red.wav";
	Sound blueSound = L"blue.wav";
	Sound yellowSound = L"yellow.wav";
	Sound greenSound = L"green.wav";
};