#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 3 - i; j >= 0; j--)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }
    return 0;
}