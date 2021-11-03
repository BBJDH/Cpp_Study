#pragma once
#include"Player.h"
#include"Monster.h"
class Simulation final
{
public:
	Simulation();
	void play();
private:
	void attackmonster()const;
	void attackplayer()const;
	void selectbrood(int const broodnum);
	Player* player;
	Monster* monster;
};

