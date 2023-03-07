//Solved Problems ***

#include <iostream>
#include<iomanip>

using namespace std ;

main()
{
    //Solution B
    cout << "Solution B"<<"\n"<<endl;
    for(int i = 1; i <=5 ;i++)
    {
        for(int k = 1; k< i; k++)
            cout << ' ';
        for(int j =5;j>=i;j--)
            cout << '*';
        cout<<"\n";
    }
    //Solution C
    cout <<"\n" << "Solution C"<<"\n"<<endl;
    for(int i = 1; i <=4 ;i++)
    {
        for(int j =4;j>i;j--)
            cout << ' ';
        for(int k = 1; k<= i; k++)
            cout << " *";
        cout<<"\n";
    }
    for(int i = 1; i <=3 ;i++)
    {
        for(int k = 1; k<= i; k++)
            cout << ' ';
        for(int j =3;j>=i;j--)
            cout << " *";
        cout<<"\n";
    }
    //Solution E
    cout <<"\n" << "Solution E"<<"\n"<<endl;
    for(int i = 1; i <=5 ;i++)
    {
        for(int j =5;j>i;j--)
            cout << ' ';
        for(int k = 1; k<= i; k++)
            cout << '*';
        cout<<"\n";
    }
    //Solution F
    cout <<"\n" << "Solution F"<<"\n"<<endl;
    cout << setw(6)<< cout.fill('*')<<"\n" ;
    for(int i =1;i < 4 ; i++)
    {
        cout << "*" ;
        for(int j = 1 ; j < 4;j++)
            cout<<' ';
        cout << "*" <<"\n";
    }
    cout << setw(5)<<cout.fill('*')<<"\n";
    return 0;
}
