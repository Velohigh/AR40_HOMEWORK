#include "Head.h"
#include <conio.h>

Head::Head()
	: AllBody(NULL), BeforeVector()
{
}

Head::~Head() 
{
}


void Head::Update() 
{

	int Value = _getch();

	switch (Value)
	{
	case 'a':
	case 'A':
		// ȭ��ٱ����� �̵��ϸ� �̵��� �ȵǰ� ���ּ���.
		InScreenMovement({ -1, 0 });
		break;
	case 'd':
	case 'D':
		InScreenMovement({ 1, 0 });
		break;
	case 'w':
	case 'W':
		InScreenMovement({ 0, -1 });
		break;
	case 's':
	case 'S':
		InScreenMovement({ 0, 1 });
		break;
	case 'q':
	case 'Q':
		// �������ΰ��� ��������
		// ������ ����ȴ�.
		Death();
		return;
	default:
		break;
	}

	return;
}



void Head::OverLap(ConsoleObject* _Link)
{
	// ��ġ�� Body�� AllBody ����Ʈ�� �ִ´�!
	AllBody.push_back((Body*)_Link);
	
}