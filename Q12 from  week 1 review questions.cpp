#include <iostream>

using namespace std;

int main()
{
    int num1 = 10, num2 = 24;
    int* p1 = &num1, * p2 = &num2;
    cout << *p1 + *p2;

    return 0;
}