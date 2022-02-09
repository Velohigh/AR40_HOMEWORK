#include "Player.h"
#include <conio.h>

Player::Player(TextScreen* _Screen, const char* _Text)
	: Screen_(_Screen)
	, Pos_(_Screen->GetSize().GetHalfVector())
	, Text_()
{
	if (nullptr == _Screen)
	{
		assert(false);
	}

	for (int i = 0; i < 3; i++)
	{
		Text_[i] = _Text[i];
	}

	// Pos_ = ;
}

Player::~Player() 
{
}


void Player::Update() 
{
	// Pos_.x_ += 1; // Pos_.y_ += 0;
	//   'a'

	// 키보드 입력을 받아서 그값을 저장
	int Value = _getch();

	switch (Value)
	{
	case 'a':
	case 'A':
		Pos_.x_ -= 1;
		break;
	case 'd':
	case 'D':
		Pos_.x_ += 1;
		break;
	case 'w':
	case 'W':
		Pos_.y_ -= 1;
		break;
	case 's':
	case 'S':
		Pos_.y_ += 1;
		break;
	default:
		break;
	}
	
	// 맵밖으로 벗어나면 터지게 설정
	if (Screen_->GetSize().x_ <= Pos_.x_ || Pos_.x_ < 0
		|| Screen_->GetSize().y_ <= Pos_.y_ || Pos_.y_ < 0)
	{
		assert(false);
	}

}

void Player::Render() 
{
	Screen_->SetPixel(Pos_, Text_);
}