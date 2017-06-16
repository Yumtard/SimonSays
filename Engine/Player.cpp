#include "Player.h"

bool Player::UserInput(Mouse & mouse, PlayField & playField, int n)
{
	if (numChoices < n)
	{
		while (!mouse.IsEmpty())
		{
			const Mouse::Event e = mouse.Read();

			if (e.GetType() == Mouse::Event::Type::LPress)
			{
				if (playField.OverLapsRed(mouse.GetPosX(), mouse.GetPosY()))
				{
					HandleClick(playField, red);
				}
				else if (playField.OverLapsBlue(mouse.GetPosX(), mouse.GetPosY()))
				{
					HandleClick(playField, blue);
				}
				else if (playField.OverLapsYellow(mouse.GetPosX(), mouse.GetPosY()))
				{
					HandleClick(playField, yellow);
				}
				else if (playField.OverLapsGreen(mouse.GetPosX(), mouse.GetPosY()))
				{
					HandleClick(playField, green);
				}
			}
		}
		return false;
	}
	return true;

}

std::vector<int> Player::GetChoices() const
{
	return choices;
}

void Player::Reset()
{
	choices.clear();
	numChoices = 0;
}

void Player::HandleClick(PlayField& playField, int color)
{
	playField.Reset();
	playField.ResetTimer();
	playField.Flash(color);
	choices.push_back(color);
	numChoices++;
}
