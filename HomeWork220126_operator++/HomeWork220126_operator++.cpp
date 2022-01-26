// HomeWork220126.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class MyInt
{
public:
	int Value;

public:
	MyInt()
		: Value(0)
	{}

	MyInt(int _Value)
		: Value(_Value)
	{}

public:
	// 전위 증감 연산자 오버로딩
	MyInt& operator++()
	{
		Value += 1;

		return *this;
	}

	// 후위 증감 연산자 오버로딩
	// 매개변수의 int 의미
	// 매개변수를 받는다는 말이 아니라 다순히 전위와 후위를 구분하기 위한 용도로 사용한다.
	MyInt operator++(int)
	{
		MyInt	Temp(*this);

		Value += 1;

		return Temp;
	}

};

int main()
{
	int Value = 0;
	int Result = 0;

	Result = ++Value;
	Result = 0;
	Result = Value++;


	MyInt MyValue = 0;
	MyInt MyResult = 0;

	MyResult = MyValue;
	printf("%d\n", MyResult.Value);  // 0

	MyResult = ++MyValue;
	printf("%d\n", MyResult.Value);  // 1

	MyResult = MyValue++;
	printf("%d\n", MyResult.Value);  // 1

	MyResult = MyValue;
	printf("%d\n", MyResult.Value);  // 2




	// ++ 쓰지마세요
	//MyResult = ++MyValue;
	//MyResult = 0;
	//MyResult = MyValue++;
}
