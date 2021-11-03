#include<Windows.h>
#include<iostream>
#include "Simulation.h"
#include"Orc.h"
#include"Troll.h"
#include"Goblin.h"
#include"Random.h"

Simulation::Simulation()
{
	player = new Player;
	Random randbrood(1, 3, 1);
	selectbrood(randbrood);
}

void Simulation::play()
{
	player->printstat();
	monster->printstat();
	std::cout << "�÷��̾� vs ���� ��������!" << std::endl;
	Sleep(2000);

	while (player->islive() and monster->islive())
	{
		system("cls");
		attackmonster();
		attackplayer();
		player->printstat();
		monster->printstat();
		Sleep(1000);
	}
	if(player->islive())
		std::cout << "�÷��̾� �¸�!" << std::endl;
	else
		std::cout << "���� �¸�!" << std::endl;

	
}



void Simulation::attackmonster()const
{
	monster->takedamege(player->attack());


}

void Simulation::attackplayer() const
{
	player->takedamege(monster->attack());

}

void Simulation::selectbrood(int const broodnum)
{
	switch (broodnum)
	{
	case 1:
	{
		monster = new Orc;
		break;
	}
	case 2:
	{
		monster = new Troll;
		break;
	}
	case 3:
	{
		monster = new Goblin;
		break;
	}

	}
}
