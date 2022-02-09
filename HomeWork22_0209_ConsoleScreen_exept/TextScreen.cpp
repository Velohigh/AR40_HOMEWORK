#include "TextScreen.h"
#include <iostream>

TextScreen::TextScreen(int _Width, int _Height, const char* _DefaultValue)
	: PixelData_(nullptr)
	, Size_(0, 0)
	, DefaultPixel_() // ��� �����ʿ䰡 ����.
{
	// �����ڿ��� CreateScreen ȣ��
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
	// vector��� ���� Size�� �Է¹��� ũ�� ����
	Size_.x_ = _Width;
	Size_.y_ = _Height;

	// �Է¹��� 3����Ʈ ���� "��"     char ��������� ���� 
	for (int i = 0; i < 3; i++)
	{
		DefaultPixel_[i] = _DefaultValue[i];
	}
	
	// "��" �� 2����Ʈ¥�� �����̹Ƿ� *2 �Ҵ�.
	// \n�� 0�� �߰��� �Ҵ��� 2����Ʈ �߰�.
	int RealWidth = Size_.x_ * 2;
	RealWidth += 2;

	// ���������ͷ�, �����ͺ������� ���� ������ Heap ������ ����.
	// Heap ������ �����Ҵ���, �ش� ���� �ּҸ� char**������� ���������ͷ� �޾ƿ�.
	PixelData_ = new char*[Size_.y_];

	// ���������Ͱ� ����ִ� Heap�����ּҰ� ����Ű�� �迭(�����͵�)�� ��ȸ�ϸ鼭
	// �ش� �����Ϳ�, ���ڿ��� ������ ������ �Ҵ��� Heap������ �ּҸ� ��ȯ����...
	// ��, ������ �ȿ� ������ �ȿ� �����Ҵ�
	for (int i = 0; i < Size_.y_; i++)
	{
		PixelData_[i] = new char[RealWidth];
	}
}


// �� ���� "��"�� ä��� ���� \n �ִ� �Լ�
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

// ��� �Լ�
void TextScreen::PrintScreen() 
{
	system("cls");

	for (int y = 0; y < Size_.y_; y++)
	{
		// char*
		printf_s(PixelData_[y]);
	}
}

// "��"�� "��" �� �ٲٴ� �Լ�
void TextScreen::SetPixel(ConsoleVector _Pos, const char* _DefaultValue) 
{
	SetPixel(_Pos.x_, _Pos.y_, _DefaultValue);
}

void TextScreen::SetPixel(int _X, int _Y, const char* _DefaultValue) 
{
	// �⺻�ڷ����� ����� �Լ��� ��¥ ������ ����

	for (int i = 0; i < 2; i++)
	{
		PixelData_[_Y][(_X * 2) + i] = _DefaultValue[i];
	}
}