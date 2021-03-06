#include <iostream>
#include <assert.h>
#include <crtdbg.h>

using DataType = int;

class GameArray
{
private:
    int Size_;
    DataType* ArrData_;

public:
    int GetSize()
    {
        return Size_;
    }

    DataType& operator[](int _Index)
    {
        if (Size_ <= _Index)
        {
            assert(false);
        }

        return ArrData_[_Index];
    }

    inline void operator=(const GameArray& _Other)
    {
        // 대입받은 배열이 더 큰 경우 : Arr[5] = Arr[10]
        if (_Other.Size_ >= this->Size_)
        {
            ReSize(_Other.Size_);

            for (size_t i = 0; i < this->Size_; i++)
            {
                this->ArrData_[i] = _Other.ArrData_[i];
            }
        }

        // 대입받은 배열이 작은 경우 : Arr[10] = Arr[5]
        else if (_Other.Size_ < this->Size_)
        {
            for (size_t i = 0; i < this->Size_; i++)
            {
                this->ArrData_[i] = _Other.ArrData_[i];

            }
        }
        return;
    }

    inline void AllValueSetting(const DataType& Data)
    {
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = Data;
        }
    }


    inline void Release()
    {
        if (nullptr != ArrData_)
        {
            delete[] ArrData_;
            ArrData_ = nullptr;
        }
    }

    void ReSize(unsigned int _Size)
    {
        Release();
        ArrData_ = new DataType[_Size];
        Size_ = _Size;
    }

public:
    GameArray(unsigned int _Size)
        : ArrData_(nullptr)
        , Size_(0)
    {
        ReSize(_Size);
    }

    ~GameArray()
    {
        Release();
    }
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    GameArray NewArray = GameArray(10);
    GameArray NewArray2 = GameArray(5);
    //GameArray NewArray2 = GameArray(20);

    int Size = sizeof(GameArray);

    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        NewArray[i] = i;
    }

    for (size_t i = 0; i < NewArray2.GetSize(); i++)
    {
        NewArray2[i] = i;
    }

    // NewArray.AllValueSetting(0);

    NewArray = NewArray2;


    // NewArray2.ReSize(20);

    for (size_t i = 0; i < NewArray2.GetSize(); i++)
    {
        std::cout << NewArray2[i] << std::endl;
    }



    //int Arr[10];
    //int Arr2[10];

    //for (size_t i = 0; i < 10; i++)
    //{
    //    Arr[i] = Arr2[i];
    //}

    std::cout << "Hello World!\n";
}

