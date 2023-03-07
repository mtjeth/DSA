/*
 multiplication table
*/

#include <iostream>

 using namespace std;
 
 int main()
 {
     int vertical_range,horizontal_range;
     cout << "vertical range: " ;
     cin >> vertical_range;
     cout << "horizontal range: ";
     cin >> horizontal_range;
     for(int i = 1; i<=horizontal_range;i++){
         cout << i << "\t";
     }
     cout << "\n\n";
     for(int a = 1; a <= vertical_range;a++){
         for(int b= 1;b<= horizontal_range;b++){
             cout << a*b <<"\t";
         }
         cout << "\n";
     }
     return 0;
 }