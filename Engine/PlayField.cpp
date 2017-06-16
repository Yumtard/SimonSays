#include "PlayField.h"

void PlayField::Update()
{
	if (greenIsFlashing || yellowIsFlashing || redIsFlashing || blueIsFlashing)
	{
		flashCounter++;
	}

	if (flashCounter >= flashOver)
	{
		flashCounter = 0;
		Reset();
	}
}

void PlayField::Draw(Graphics & gfx)
{
	//Top left
	gfx.DrawRect(x, y, dim, dim, Green());
	//Bottom left
	gfx.DrawRect(x, y + dim + padding, dim, dim, Yellow());
	//Top right
	gfx.DrawRect(x + dim + padding, y, dim, dim, Red());
	//Bottom right
	gfx.DrawRect(x + dim + padding, y + dim + padding, dim, dim, Blue());

	timer.Draw(gfx);
}

Color PlayField::Green()
{
	if (greenIsFlashing)
	{
		Color green = Color(0, 240, 43);
		return green;
	}
	Color green = Color(0, 85, 15);
	return green;
}

Color PlayField::Red()
{
	if (redIsFlashing)
	{
		Color red = Color(255, 0, 0);
		return red;
	}
	Color red = Color(130, 0, 0);
	return red;
}

Color PlayField::Blue()
{
	if (blueIsFlashing)
	{
		Color blue = Color(0, 0, 255);
		return blue;
	}
	Color blue = Color(0, 0, 150);
	return blue;
}

Color PlayField::Yellow()
{
	if (yellowIsFlashing)
	{
		Color yellow = Color(240, 240, 0);
		return yellow;
	}
	Color yellow = Color(147, 147, 0);
	return yellow;
}

void PlayField::Flash(int color)
{
	Reset();
	switch (color)
	{
	case 1:
		redIsFlashing = true;
		redSound.Play();
		break;
	case 2:
		blueIsFlashing = true;
		blueSound.Play();
		break;
	case 3:
		yellowIsFlashing = true;
		yellowSound.Play();
		break;
	case 4:
		greenIsFlashing = true;
		greenSound.Play();
		break;
	}
}

void PlayField::Reset()
{
	greenIsFlashing = false;
	redIsFlashing = false;
	blueIsFlashing = false;
	yellowIsFlashing = false;
	flashCounter = 0;
}

bool PlayField::OverLapsRed(int in_x, int in_y)
{
	return in_x > (x + dim + padding) &&
		in_x < (x + (dim * 2) + padding) &&
		in_y > y &&
		in_y < (y + dim);
}

bool PlayField::OverLapsGreen(int in_x, int in_y)
{
	return in_x > x &&
		in_x < (x + dim) &&
		in_y > y &&
		in_y < (y + dim) ;
}

bool PlayField::OverLapsBlue(int in_x, int in_y)
{
	return in_x > (x + dim + padding) &&
		in_x < (x + (dim * 2) + padding) &&
		in_y > (y + dim + padding) &&
		in_y < (y + (dim * 2) + padding);
}

bool PlayField::OverLapsYellow(int in_x, int in_y)
{
	return in_x > x &&
		in_x < (x + dim) &&
		in_y > (y + dim + padding) &&
		in_y < (y + (dim * 2) + padding);
}

void PlayField::UpdateTimer()
{
	timer.Update();
}

void PlayField::ResetTimer()
{
	timer.Reset();
}

bool PlayField::TimeOver() const
{
	return timer.GetTime() <= 0;
}

