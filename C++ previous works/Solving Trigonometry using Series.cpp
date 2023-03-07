
//Solving Trigonometry using Series

#include <iostream>
#include <cmath>
#define angletorad 3.14159265/180

using namespace std;
int factorial(int y)
{
    int w = 1;
    for(int i=y;i>1;i--){
        w *= i;
    }
    return w;
}
double power(double a,int b)
{
    double c;
    c = a;
    for(int i =1;i<b;i++)
        c *= a;
    if (b == 0)
        return 1;
    else
        return c;
}

void intrinsic(float x)
{
    cout << "sin of " << x << " using Intrinsic series is " << sin(x*angletorad) << endl;
}

void truncated(float x,double n)
{
    double series = 0;
    int coun=1;
    double f=power(x*angletorad,(2*coun-1))/factorial(2*coun-1) ;
    while(f > n){
        series= series + (power(-1,(coun - 1))*f);
        coun ++;
        f = power(x*angletorad,(2*coun-1))/factorial(2*coun-1);
    } ;
    cout << "sin of " << x << " using Truncated series is " << series << " and needed term amount was "<< coun<< endl;
}

int main()
{
    float x;
    double n;
    cout << "Enter value of X : ";
    cin >> x;
    cout << "Needed Accuracy :" ;
    cin >> n;
    intrinsic(x);
    truncated(x,n);
    return 0;
}
