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
	else if (score < 100 && order == first || order == second)
	{
		DrawNumber(gfx);
	}
	else if (score >= 100)
	{
		DrawNumber(gfx);
	}
}

void Text::DrawNumber(Graphics & gfx)
{
	switch (value)
	{
	case 0:
		gfx.PutBigPixel(x, 0, y, 1, color);
		gfx.PutBigPixel(x, 0, y, 2, color);
		gfx.PutBigPixel(x, 0, y, 3, color);
		gfx.PutBigPixel(x, 0, y, 4, color);
		gfx.PutBigPixel(x, 0, y, 5, color);

		gfx.PutBigPixel(x, 1, y, 0, color);
		gfx.PutBigPixel(x, 2, y, 0, color);
		gfx.PutBigPixel(x, 3, y, 0, color);

		gfx.PutBigPixel(x, 4, y, 1, color);
		gfx.PutBigPixel(x, 4, y, 2, color);
		gfx.PutBigPixel(x, 4, y, 3, color);
		gfx.PutBigPixel(x, 4, y, 4, color);
		gfx.PutBigPixel(x, 4, y, 5, color);

		gfx.PutBigPixel(x, 1, y, 6, color);
		gfx.PutBigPixel(x, 2, y, 6, color);
		gfx.PutBigPixel(x, 3, y, 6, color);
		break;
	case 1:
		gfx.PutBigPixel(x, 0, y, 1, color);
		gfx.PutBigPixel(x, 1, y, 1, color);
		gfx.PutBigPixel(x, 2, y, 1, color);

		gfx.PutBigPixel(x, 0, y, 6, color);
		gfx.PutBigPixel(x, 1, y, 6, color);
		gfx.PutBigPixel(x, 2, y, 6, color);
		gfx.PutBigPixel(x, 3, y, 6, color);
		gfx.PutBigPixel(x, 4, y, 6, color);

		gfx.PutBigPixel(x, 2, y, 0, color);
		gfx.PutBigPixel(x, 2, y, 2, color);
		gfx.PutBigPixel(x, 2, y, 3, color);
		gfx.PutBigPixel(x, 2, y, 4, color);
		gfx.PutBigPixel(x, 2, y, 5, color);

		break;
	case 2:
		gfx.PutBigPixel(x, 0, y, 1, color);
		gfx.PutBigPixel(x, 0, y, 5, color);
		gfx.PutBigPixel(x, 0, y, 6, color);

		gfx.PutBigPixel(x, 1, y, 0, color);
		gfx.PutBigPixel(x, 1, y, 4, color);
		gfx.PutBigPixel(x, 1, y, 6, color);

		gfx.PutBigPixel(x, 2, y, 0, color);
		gfx.PutBigPixel(x, 2, y, 3, color);
		gfx.PutBigPixel(x, 2, y, 6, color);

		gfx.PutBigPixel(x, 3, y, 0, color);
		gfx.PutBigPixel(x, 3, y, 2, color);
		gfx.PutBigPixel(x, 3, y, 6, color);

		gfx.PutBigPixel(x, 4, y, 1, color);
		gfx.PutBigPixel(x, 4, y, 6, color);
		break;
	case 3:
		gfx.PutBigPixel(x, 0, y, 1, color);
		gfx.PutBigPixel(x, 1, y, 0, color);
		gfx.PutBigPixel(x, 2, y, 0, color);
		gfx.PutBigPixel(x, 3, y, 0, color);
		gfx.PutBigPixel(x, 4, y, 1, color);
		gfx.PutBigPixel(x, 4, y, 2, color);
		gfx.PutBigPixel(x, 3, y, 3, color);
		gfx.PutBigPixel(x, 2, y, 3, color);
		gfx.PutBigPixel(x, 4, y, 4, color);
		gfx.PutBigPixel(x, 4, y, 5, color);
		gfx.PutBigPixel(x, 3, y, 6, color);
		gfx.PutBigPixel(x, 2, y, 6, color);
		gfx.PutBigPixel(x, 1, y, 6, color);
		gfx.PutBigPixel(x, 0, y, 5, color);
		break;
	case 4:
		gfx.PutBigPixel(x, 0, y, 0, color);
		gfx.PutBigPixel(x, 0, y, 1, color);
		gfx.PutBigPixel(x, 0, y, 2, color);
		gfx.PutBigPixel(x, 0, y, 3, color);
		gfx.PutBigPixel(x, 0, y, 4, color);

		gfx.PutBigPixel(x, 1, y, 4, color);
		gfx.PutBigPixel(x, 2, y, 4, color);
		gfx.PutBigPixel(x, 3, y, 4, color);
		gfx.PutBigPixel(x, 4, y, 4, color);

		gfx.PutBigPixel(x, 2, y, 3, color);
		gfx.PutBigPixel(x, 2, y, 5, color);
		gfx.PutBigPixel(x, 2, y, 6, color);
		break;
	case 5:
		gfx.PutBigPixel(x, 0, y, 0, color);
		gfx.PutBigPixel(x, 1, y, 0, color);
		gfx.PutBigPixel(x, 2, y, 0, color);
		gfx.PutBigPixel(x, 3, y, 0, color);
		gfx.PutBigPixel(x, 4, y, 0, color);

		gfx.PutBigPixel(x, 0, y, 1, color);
		gfx.PutBigPixel(x, 0, y, 2, color);
		gfx.PutBigPixel(x, 0, y, 3, color);

		gfx.PutBigPixel(x, 1, y, 3, color);
		gfx.PutBigPixel(x, 2, y, 3, color);
		gfx.PutBigPixel(x, 3, y, 3, color);

		gfx.PutBigPixel(x, 4, y, 4, color);
		gfx.PutBigPixel(x, 4, y, 5, color);

		gfx.PutBigPixel(x, 3, y, 6, color);
		gfx.PutBigPixel(x, 2, y, 6, color);
		gfx.PutBigPixel(x, 1, y, 6, color);
		gfx.PutBigPixel(x, 0, y, 6, color);
		break;
	case 6:
		gfx.PutBigPixel(x, 0, y, 1, color);
		gfx.PutBigPixel(x, 0, y, 2, color);
		gfx.PutBigPixel(x, 0, y, 3, color);
		gfx.PutBigPixel(x, 0, y, 4, color);
		gfx.PutBigPixel(x, 0, y, 5, color);

		gfx.PutBigPixel(x, 1, y, 0, color);
		gfx.PutBigPixel(x, 2, y, 0, color);
		gfx.PutBigPixel(x, 3, y, 0, color);
		gfx.PutBigPixel(x, 4, y, 1, color);

		gfx.PutBigPixel(x, 1, y, 3, color);
		gfx.PutBigPixel(x, 2, y, 3, color);
		gfx.PutBigPixel(x, 3, y, 3, color);
		gfx.PutBigPixel(x, 4, y, 4, color);
		gfx.PutBigPixel(x, 4, y, 5, color);

		gfx.PutBigPixel(x, 1, y, 6, color);
		gfx.PutBigPixel(x, 2, y, 6, color);
		gfx.PutBigPixel(x, 3, y, 6, color);
		
		break;
	case 7:
		gfx.PutBigPixel(x, 0, y, 0, color);
		gfx.PutBigPixel(x, 1, y, 0, color);
		gfx.PutBigPixel(x, 2, y, 0, color);
		gfx.PutBigPixel(x, 3, y, 0, color);
		gfx.PutBigPixel(x, 4, y, 0, color);
		gfx.PutBigPixel(x, 4, y, 1, color);
		gfx.PutBigPixel(x, 3, y, 2, color);
		gfx.PutBigPixel(x, 2, y, 3, color);
		gfx.PutBigPixel(x, 2, y, 4, color);
		gfx.PutBigPixel(x, 2, y, 5, color);
		gfx.PutBigPixel(x, 2, y, 6, color);
		break;
	case 8:
		gfx.PutBigPixel(x, 1, y, 0, color);
		gfx.PutBigPixel(x, 2, y, 0, color);
		gfx.PutBigPixel(x, 3, y, 0, color);

		gfx.PutBigPixel(x, 1, y, 3, color);
		gfx.PutBigPixel(x, 2, y, 3, color);
		gfx.PutBigPixel(x, 3, y, 3, color);

		gfx.PutBigPixel(x, 1, y, 6, color);
		gfx.PutBigPixel(x, 2, y, 6, color);
		gfx.PutBigPixel(x, 3, y, 6, color);

		gfx.PutBigPixel(x, 0, y, 1, color);
		gfx.PutBigPixel(x, 0, y, 2, color);

		gfx.PutBigPixel(x, 0, y, 4, color);
		gfx.PutBigPixel(x, 0, y, 5, color);

		gfx.PutBigPixel(x, 4, y, 1, color);
		gfx.PutBigPixel(x, 4, y, 2, color);

		gfx.PutBigPixel(x, 4, y, 4, color);
		gfx.PutBigPixel(x, 4, y, 5, color);
		
		break;
	case 9:
		gfx.PutBigPixel(x, 1, y, 0, color);
		gfx.PutBigPixel(x, 2, y, 0, color);
		gfx.PutBigPixel(x, 3, y, 0, color);

		gfx.PutBigPixel(x, 1, y, 3, color);
		gfx.PutBigPixel(x, 2, y, 3, color);
		gfx.PutBigPixel(x, 3, y, 3, color);

		gfx.PutBigPixel(x, 1, y, 6, color);
		gfx.PutBigPixel(x, 2, y, 6, color);
		gfx.PutBigPixel(x, 3, y, 6, color);

		gfx.PutBigPixel(x, 0, y, 1, color);
		gfx.PutBigPixel(x, 0, y, 2, color);
		gfx.PutBigPixel(x, 0, y, 5, color);

		gfx.PutBigPixel(x, 4, y, 1, color);
		gfx.PutBigPixel(x, 4, y, 2, color);
		gfx.PutBigPixel(x, 4, y, 3, color);
		gfx.PutBigPixel(x, 4, y, 4, color);
		gfx.PutBigPixel(x, 4, y, 5, color);
		
		break;
	}
}
