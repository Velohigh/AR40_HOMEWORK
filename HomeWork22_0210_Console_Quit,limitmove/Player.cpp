#include "Player.h"
#include <conio.h>
#include "ConsoleGlobalInst.h"

Player::Player(TextScreen* _Screen, const char* _Text)
	: ConsoleObject(_Screen, _Text, _Screen->GetSize().GetHalfVector())
{
}

Player::~Player() 
{
}


int Player::Update() 
{
	// GlobalValue::AllMonsters

	// AllMonsters[2];

	// Pos_.x_ += 1; // Pos_.y_ += 0;
	//   'a'
	int Value = _getch();

	switch (Value)
	{
	case 'a':
	case 'A':
		// 화면바깥으로 이동하면 이동이 안되게 해주세요.
		if(GetPos().x_ > 0)
		SetMove({-1, 0});
		break;
	case 'd':
	case 'D':
		if(GetPos().x_ < MainScreen.GetSize().x_ -1)
		SetMove({ 1, 0 });
		break;
	case 'w':
	case 'W':
		if(GetPos().y_ > 0)
		SetMove({ 0, -1 });
		break;
	case 's':
	case 'S':
		if (GetPos().y_ < MainScreen.GetSize().y_ -1)
		SetMove({ 0, 1 });
		break;
	case 'q':
	case 'Q':
		// 무슨일인가가 벌어져서
		// 게임이 종료된다.
		return -1;
		break;
	default:
		break;
	}
	

}

