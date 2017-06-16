#include "Simon.h"

Simon::Simon()
	:
	rng(std::random_device()())
{
}

void Simon::Update()
{
	
}

void Simon::AddMove()
{		
	std::uniform_int_distribution<int>dist(1, 4);
	int choice = dist(rng);
	choices.push_back(choice);	
}

void Simon::Reset()
{
	choices.clear();
}

bool Simon::DisplaySeq(PlayField & playField, int n)
{
	if (displayCounter++ >= display)
	{
		if (pauseCounter++ >= pause)
		{
			if (curChoice < n)
			{
				switch (choices[curChoice])
				{
				case 1:
					playField.Flash(red);
					displayCounter = 0;
					break;
				case 2:
					playField.Flash(blue);
					displayCounter = 0;
					break;
				case 3:
					playField.Flash(yellow);
					displayCounter = 0;
					break;
				case 4:
					playField.Flash(green);
					displayCounter = 0;
					break;
				}
				curChoice++;
			}
			else
			{
				curChoice = 0;
				displayCounter = 0;
				return true;
			}
			pauseCounter = 0;
		}
	}
	return false;
}

std::vector<int> Simon::Getchoices() const
{
	return choices;
}

