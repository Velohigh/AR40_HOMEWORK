// HomeWork220114_ToInt.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 길이구하는 함수가 필요할듯..
// 자리수에 

int StringLen(const char* _Text)
{
	int Count = 0;
	for (int i = 0; _Text[i] != 0; ++i)
	{
		++Count;
	}

	return Count;
}

int ToInt(const char* _Text)
{

	int Temp = 0;
	int Value = 1;
	int Mulcount = 0;
	int StringLength = StringLen(_Text);

	Mulcount = StringLength;

	for (int i = 0; i < StringLength; ++i)
	{
		int CurValue = _Text[i] - '0';
		Mulcount = StringLength - i -1;

		while (Mulcount != 0)
		{
			--Mulcount;
			CurValue *= 10;
		}
		Temp += CurValue;

	}

	return Temp;

}


int main()
{
	int Value = ToInt("15815");

	int a = 0;
}