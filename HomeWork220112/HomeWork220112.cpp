#include <iostream>

int main()
{
	//int Arr[10];
	//for (int i = 0; i < 10; i += 1)
	//{
	//	Arr[i] = i;
	//}

	{
		int Arr[10] = { 0, };
		int Index = 0;
		while (true)
		{
			// 0 부터 시작해서 0 제외
			// 2 4 6 8 10 12 14 16 18 
			// 배열이 가득찰때까지 짝수로만 채워주세요

			Arr[Index] = Index * 2 + 2;
			Index += 1;

			if (Index > 9) break;
		}

		// 콘솔창에 결과 출력
		for (int i = 0; i < sizeof(Arr) / sizeof(Index); ++i)
		{
			printf("Arr[%d] : %d\n", i, Arr[i]);
		}
		printf("\n");
		
	}

	{
		int Arr[10] = { 0, };
		int Index = 0;
		while (true)
		{
			// 0 부터 시작해서 0 제외
			// 1 3 5 7 9 11 13 15 17 
			// 배열이 가득찰때까지 홀수로만 채워주세요

			Arr[Index] = Index * 2 + 1;
			Index += 1;

			if (Index > 9) break;
		}

		// 콘솔창에 결과 출력
		for (int i = 0; i < sizeof(Arr) / sizeof(Index); ++i)
		{
			printf("Arr[%d] : %d\n", i, Arr[i]);
		}

		int a = 0;
	}

}
