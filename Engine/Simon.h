#pragma once

#include "PlayField.h"
#include <vector>
#include <random>

class Simon
{
public:
	Simon();
	void Update();
	void AddMove();
	void Reset();
	bool DisplaySeq(PlayField& playField, int n);
	std::vector<int> Getchoices() const;

private:
	std::vector<int>choices;
	std::mt19937 rng;
	int curChoice = 0;
	int displayCounter = 0;
	static constexpr int display = 30;
	int pauseCounter = 0;
	static constexpr int pause = 5;
	static constexpr int red = 1;
	static constexpr int blue = 2;
	static constexpr int yellow = 3;
	static constexpr int green = 4;
};