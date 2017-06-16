#include "Timer.h"

void Timer::Draw(Graphics & gfx)
{
	gfx.DrawRect(x, y, bgWidth, height, Colors::Gray);
	gfx.DrawRect(x + padding, y + padding, maxTime, height - (padding * 2), darkGray);
	gfx.DrawRect(x + padding, y + padding, timeWidth, height - (padding * 2), Colors::Green);
}

void Timer::Update()
{
	timeWidth--;
}

void Timer::Reset()
{
	timeWidth = maxTime;
}

int Timer::GetTime() const
{
	return timeWidth;
}
