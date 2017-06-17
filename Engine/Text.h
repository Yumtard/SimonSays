#pragma once

#include "Graphics.h"

class Text	
{
public:
	enum Order
	{
		first, second, third
	};
	Text(int x_in, int y_in, Order order_in);
	void Update(int score);
	void SetValue(int score);
	void Draw(Graphics& gfx, int score);
	void DrawNumber(Graphics& gfx);

private:
	int x;
	int y;
	int value;
	Order order;
	Color color = Colors::Green;
};

