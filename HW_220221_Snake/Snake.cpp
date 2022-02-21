// Snake.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Engine/ConsoleScreen.h"
#include <conio.h>
#include "Head.h"
#include "Body.h"
#include <vector>
#include "Engine/ConsoleRandom.h"
#include "GlobalGameLogic.h"

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(221);

	ConsoleScreen::GetInst().CreateScreen(10, 10, "□");

	ConsoleObject* NewHead = new Head();
	NewHead->Init({ 5, 5 }, "★");


	ConsoleObject* NewBody = GlobalGameLogic::CreateBodyLogic(NewHead);

	while (true)
	{
		if (nullptr == NewBody)
		{
			NewBody = GlobalGameLogic::CreateBodyLogic(NewHead);
		}

		ConsoleScreen::GetInst().RenderStart();

		NewBody->Render();
		NewHead->Render();

		ConsoleScreen::GetInst().RenderEnd();

		NewBody->Update();
		NewHead->Update();

		if (true == NewHead->GetIsDeath())
		{

			break;
		}

		
		if (NewHead->OverLapCheck(NewBody))  // 겹치는지 체크
		{
			NewHead->OverLap(NewBody);       // 겹치면 Body에 Dead = true
			if (nullptr != NewBody)			 
			{
				delete NewBody;
				NewBody = nullptr;
			}
		}
	}

	ConsoleScreen::Destroy();
	if (nullptr != NewHead)
	{
		delete static_cast<Head*>(NewHead);
		NewHead = nullptr;
	}

	if (nullptr != NewBody)
	{
		delete static_cast<Body*>(NewBody);
		NewBody = nullptr;
	}


}
