#include <iostream>

using namespace std;

int main()
{
    int my_array[]{ 2,51,6,20,47,84,39,67,5,20};
    int size_of_my_array = sizeof( my_array)/4;
    int swap, rank=2;
    for(int i =0;i<size_of_my_array;i++)
        for(int j = i ; j < size_of_my_array;j++)
            if (my_array[i] < my_array[j])
            {
                swap = my_array[i];
                my_array[i] = my_array[j];
                my_array[j] = swap;
            }
    cout << my_array[rank - 1];
    return 0;
}