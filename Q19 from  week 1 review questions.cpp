#include <iostream>

using namespace std;

int print(int *p, int i)
{
    int sum ;
    if (i != 0)
        sum = *p + print(p + 1, i - 1);
    else
        sum = *p;
    return sum;
}

int main()
{
    int my_array[]{ 2,51,6,20,47,84,39,67,5,20 };
    int size = sizeof(my_array)/4 ;
    int total = print(&my_array[0], size - 1);
    cout << total; 
    return 0;
}