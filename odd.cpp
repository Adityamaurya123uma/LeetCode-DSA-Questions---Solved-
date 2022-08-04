#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "enter the size";
    cin >> size;
    int array[size];

    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        cout << array[i];
    }
    return 0;
}