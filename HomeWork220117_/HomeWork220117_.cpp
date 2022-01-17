// HomeWork220117_.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int CountFirst(const char* _Text, int _Start, const char* _FindStr)
{
    for (int i = _Start; 0 != _Text[i]; ++i)
    {
        if (_Text[i] == _FindStr[0] &&  _Text[i+1] == _FindStr[1] && _Text[i+2] == _FindStr[2])
        {
            return i;
        }

    }

    return -1;
}

int CountLast(const char* _Text, int _End, const char* _FindStr)
{

    for (int i = _End; _Text[i] != 0; --i)
    {
        if (_Text[i] == _FindStr[0] && _Text[i + 1] == _FindStr[1] && _Text[i + 2] == _FindStr[2])
        {
            return i;
        }
    }

    return -1;
}


int main()
{
    {
        int Count = CountFirst("aaa eee ttt asdfasd eee", 0, "eee");

        int a = 0;
    }
    {
        int Count = CountLast("aaa eee asdfasd eee", 19, "eee");

        int a = 0;
    }

}
