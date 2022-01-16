// HomeWork220114_ToInt.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 길이구하는 함수가 필요할듯..
// 자리수에 

int ToInt(const char* _str)
{

	int Temp = 0;

	for (int i = 0; _str[i] != 0; ++i)
	{
		if (_str[i] >= '0' && _str[i] <='9')
		{
			_str[i] -= '0';

		}

	}


}


int main()
{
	int Value = ToInt("15815");
}