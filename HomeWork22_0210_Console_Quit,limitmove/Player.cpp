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
		// ȭ��ٱ����� �̵��ϸ� �̵��� �ȵǰ� ���ּ���.
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
		// �������ΰ��� ��������
		// ������ ����ȴ�.
		return -1;
		break;
	default:
		break;
	}
	

}

