#include "TextScreen.h"
#include <iostream>

TextScreen::TextScreen(int _Width, int _Height, const char* _DefaultValue)
	: PixelData_(nullptr)
	, Size_(0, 0)
	, DefaultPixel_() // 사실 해줄필요가 없다.
{
	// 생성자에서 CreateScreen 호출
	CreateScreen(_Width, _Height, _DefaultValue);
}

TextScreen::~TextScreen() 
{
	for (int i = 0; i < Size_.y_; i++)
	{
		if (nullptr != PixelData_)
		{
			delete[] PixelData_[i];
			PixelData_[i] = nullptr;
		}
	}

	if (nullptr != PixelData_)
	{
		delete[] PixelData_;
		PixelData_ = nullptr;
	}
}

void TextScreen::CreateScreen(int _Width, int _Height, const char* _DefaultValue)
{
	// vector멤버 변수 Size에 입력받은 크기 저장
	Size_.x_ = _Width;
	Size_.y_ = _Height;

	// 입력받은 3바이트 문자 "ㅁ"     char 멤버변수에 저장 
	for (int i = 0; i < 3; i++)
	{
		DefaultPixel_[i] = _DefaultValue[i];
	}
	
	// "ㅁ" 은 2바이트짜리 문자이므로 *2 할당.
	// \n과 0을 추가로 할당할 2바이트 추가.
	int RealWidth = Size_.x_ * 2;
	RealWidth += 2;

	// 이중포인터로, 포인터변수들을 담을 공간을 Heap 영역에 만듬.
	// Heap 영역에 동적할당후, 해당 공간 주소를 char**멤버변수 이중포인터로 받아옴.
	PixelData_ = new char*[Size_.y_];

	// 이중포인터가 들고있는 Heap영역주소가 가리키는 배열(포인터들)을 순회하면서
	// 해당 포인터에, 문자열을 저장할 공간을 할당한 Heap영역의 주소를 반환받음...
	// 즉, 포인터 안에 포인터 안에 공간할당
	for (int i = 0; i < Size_.y_; i++)
	{
		PixelData_[i] = new char[RealWidth];
	}
}


// 각 줄을 "ㅁ"로 채우고 끝에 \n 넣는 함수
void TextScreen::SettingScreen() 
{
	//int RealWidth = Size_.x_ * 2;
	//RealWidth += 1;

	for (int y = 0; y < Size_.y_; y++)
	{
		for (int x = 0; x < Size_.x_; x++)
		{
			for (int i = 0; i < 2; i++)
			{
				PixelData_[y][(x * 2) + i] = DefaultPixel_[i];
			}
		}
		PixelData_[y][(Size_.x_ * 2)] = '\n';
		PixelData_[y][(Size_.x_ * 2) + 1] = 0;
	}

}

// 출력 함수
void TextScreen::PrintScreen() 
{
	system("cls");

	for (int y = 0; y < Size_.y_; y++)
	{
		// char*
		printf_s(PixelData_[y]);
	}
}

// "ㅁ"을 "☆" 로 바꾸는 함수
void TextScreen::SetPixel(ConsoleVector _Pos, const char* _DefaultValue) 
{
	SetPixel(_Pos.x_, _Pos.y_, _DefaultValue);
}

void TextScreen::SetPixel(int _X, int _Y, const char* _DefaultValue) 
{
	// 기본자료형을 사용한 함수에 진짜 내용을 놓고

	for (int i = 0; i < 2; i++)
	{
		PixelData_[_Y][(_X * 2) + i] = _DefaultValue[i];
	}
}