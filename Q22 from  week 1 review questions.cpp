#include <iostream>

using namespace std;

int main()
{
    int my_array[]{ 2,51,6,20,47,84,39,67,5,20 };
    int size = sizeof(my_array)/4,even=0,odd=0 ;
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            even++;
        else
            odd++;
    }
    cout << "Amount of Even : " << even << endl;
    cout << "Amount of Odd : " << odd << endl;
    return 0;
}