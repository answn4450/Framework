#include <iostream>
#include <vector>

using namespace std;


int* Numbers;
int Size;
int Capacity;


void pop_back()
{
    if (Size != 0)
        --Size;
}


void push_back(int _value)
{
    if (Size == Capacity)
    {
        int Length = int(Capacity * 0.5f);
        Capacity += Length < 1 ? 1 : Length;
    }

    int* temp = new int[Capacity];

    for (int i = 0; i < Size; ++i)
        temp[i] = Numbers[i];

    delete Numbers;
    Numbers = nullptr;

    Numbers = temp;

    Numbers[Size] = _value;

    ++Size;
}


void insert(int _where, int _value)
{
    if (_where > Size)
        return;
    //++Size;
    
    if (Size == Capacity)
    {
        int Length = int(Capacity * 0.5f);
        Capacity += Length < 1 ? 1 : Length;
    }

    _where -= 1;
    
    for (int i = Size; _where <= i; --i)
    {
        Numbers[i + 1] = Numbers[i];
    }

    Numbers[_where] = _value;
}


void erase(int _where)
{
    if (_where > Size || _where <= 0)
        return;

    --Size;
    _where -= 1;

    for (int i = _where; i <= Size; ++i)
        Numbers[i] = Numbers[i+1];
}


int main(void)
{
    for (int i = 0; i < 10; ++i)
    {
        push_back(i * 10 + 10);
        //cout << "size : " << Size << endl;
        //cout << "capacity : " << Capacity << endl << endl;
    }
    insert(2, 999);
    erase(2);

    for (int i = 0; i < Size; ++i)
        cout << Numbers[i] << endl;
    return 0;
}