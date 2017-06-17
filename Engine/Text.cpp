#include "Text.h"

Text::Text(int x_in, int y_in, Order order_in)
	:
	x(x_in),
	y(y_in),
	order(order_in)
{
}

void Text::Update(int score)
{
	SetValue(score);
}

void Text::SetValue(int score)
{
	if (score < 10)
	{
		if (order == first)
		value = score;
	}

	else if (score < 100)
	{
		switch (order)
		{
		case first:
			value = score / 10 % 10;
			break;
		case second:
			value = score % 10;
			break;
		default:
			break;

		}
	}

	else
	{
		switch (order)
		{
		case first:
			value = score / 100 % 10;
			break;
		case second:
			value = score / 10 % 10;
			break;
		case third:
			value = score % 10;
			break;

		}
	}
}

void Text::Draw(Graphics & gfx, int score)
{
	if (score < 10 && order == first)
	{
		DrawNumber(gfx);
	}
	else if (score < 100)
	{
		switch (order)
		{
		case first:
			//drawnumber() based on value
			break;
		case second:
			//drawnumber() based on value
			break;
		default:
			break;
		}
	}
	else
	{
		switch (order)
		{
		case first:
			//drawnumber() based on value
			break;
		case second:
			//drawnumber() based on value
			break;
		case third:
			//drawnumber() based on value
			break;
		}
	}
}

void Text::DrawNumber(Graphics & gfx)
{
	switch (value)
	{
	case 0:
		gfx.PutBigPixel(x, 0, y, 1, Colors::Green);
		gfx.PutBigPixel(x, 0, y, 2, Colors::Green);
		gfx.PutBigPixel(x, 0, y, 3, Colors::Green);
		gfx.PutBigPixel(x, 0, y, 4, Colors::Green);
		gfx.PutBigPixel(x, 0, y, 5, Colors::Green);

		gfx.PutBigPixel(x, 1, y, 0, Colors::Green);
		gfx.PutBigPixel(x, 2, y, 0, Colors::Green);
		gfx.PutBigPixel(x, 3, y, 0, Colors::Green);

		gfx.PutBigPixel(x, 4, y, 1, Colors::Green);
		gfx.PutBigPixel(x, 4, y, 1, Colors::Green);
		gfx.PutBigPixel(x, 4, y, 1, Colors::Green);
		gfx.PutBigPixel(x, 4, y, 1, Colors::Green);
		gfx.PutBigPixel(x, 4, y, 1, Colors::Green);

		gfx.PutBigPixel(x, 1, y, 6, Colors::Green);
		gfx.PutBigPixel(x, 2, y, 6, Colors::Green);
		gfx.PutBigPixel(x, 3, y, 6, Colors::Green);
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	}
}
