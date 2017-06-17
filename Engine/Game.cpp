/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	firstScore(600, 490, Text::Order::first),
	secondScore(630, 490, Text::Order::second),
	thirdScore(660, 490, Text::Order::third)
{
	
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	playField.Update();
	firstScore.Update(seqSize);
	secondScore.Update(seqSize);
	thirdScore.Update(seqSize);

	switch (state)
	{
	case notStarted:
		if (wnd.mouse.LeftIsPressed())
		{
			simon.AddMove();
			state = computer;
		}
		break;

	case player1:
		playField.UpdateTimer();
		if (playField.TimeOver())
		{
			newGameCounter = 0;
			state = newGame;
		}

		if (player.UserInput(wnd.mouse, playField, seqSize))
		{
			if (IsMatch())
			{
				seqSize++;
				simon.AddMove();
				state = computer;
			}
			else
			{
				newGameCounter = 0;
				state = newGame;
			}
		}
		break;

	case computer:
		if (pauseCounter++ >= pause)
		{
			if (simon.DisplaySeq(playField, seqSize))
			{
				pauseCounter = 0;
				player.Reset();
				playField.Reset();
				state = player1;
			}
		}
		break;
		
	case newGame:
		if (newGameCounter++ >= startNewGame)
		{
			seqSize = 1;
			playField.Reset();
			playField.ResetTimer();
			simon.Reset();
			simon.AddMove();
			state = computer;
		}
		break;
	}
}

bool Game::IsMatch()
{
	for (int i = 0; i < seqSize; i++)
	{
		if (player.GetChoices()[i] != simon.Getchoices()[i])
		{
			return false;
		}
	}
	return true;
}


void Game::ComposeFrame()
{
	playField.Draw(gfx);
	firstScore.Draw(gfx, seqSize);
	secondScore.Draw(gfx, seqSize);
	thirdScore.Draw(gfx, seqSize);
}
