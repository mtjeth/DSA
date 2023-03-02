#include <iostream>

using namespace std;

int main()
{
    int num1 = 10, num2 = 24,temp;
    int* p1 = &num1, * p2 = &num2;
    cout << num1 << "\t" << num2 << endl;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << num1 << "\t" << num2 << endl;

    return 0;
}