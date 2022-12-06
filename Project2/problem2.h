#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Play
{
private:
	char rock;
	char scissor;
	char papper;
	char play;

public:
	Play(char _rock, char _papper, char _scissor)
	{
		play = _rock;
		rock = _rock;
		scissor = _scissor;
		papper = _papper;
	}

	void setPlay(char _play)
	{
		play = _play;
	}

	bool isRock()
	{
		return play == rock;
	}

	bool isScissor()
	{
		return play == scissor;
	}

	bool isPapper()
	{
		return play == papper;
	}
};

bool is_draw(Play& enemyPlay, Play& myPlay)
{
	if (enemyPlay.isPapper() && myPlay.isPapper())
		return true;
	else if (enemyPlay.isRock() && myPlay.isRock())
		return true;
	else if (enemyPlay.isScissor() && myPlay.isScissor())
		return true;

	return false;
}

bool is_i_won(Play& enemyPlay, Play& myPlay)
{
	if (myPlay.isPapper() && enemyPlay.isRock())
		return true;
	if (myPlay.isRock() && enemyPlay.isScissor())
		return true;
	if (myPlay.isScissor() && enemyPlay.isPapper())
		return true;

	return false;
}

int get_shape_score(Play& myPlay)
{
	if (myPlay.isRock())
		return 1;
	else if (myPlay.isPapper())
		return 2;
	else//scissor
		return 3;
}

int score(Play& enemyPlay, Play& myPlay)
{
	int score = 0;

	if (is_draw(enemyPlay, myPlay))
		score = get_shape_score(myPlay) + 3;
	else if (is_i_won(enemyPlay, myPlay))
		score = get_shape_score(myPlay) + 6;
	else//i lost
		score = get_shape_score(myPlay) + 0;
	
	return score;
}

void solve_2(const std::string &pathinput)
{
	std::ifstream ifile(pathinput.c_str());
	std::string line;

	Play enemyPlay('A', 'B', 'C');
	Play myPlay('X', 'Y', 'Z');
	int myScore = 0;

	while (std::getline(ifile, line))
	{
		std::stringstream str(line);
		char enemy_play, me_play;

		str >> enemy_play;
		str >> me_play;

		enemyPlay.setPlay(enemy_play);
		myPlay.setPlay(me_play);

		myScore += score(enemyPlay, myPlay);
		std::cout << "enemy play: " << enemy_play << ", " << "my play: " << me_play << std::endl;
	}

	std::cout << "Total score " << myScore;
}
