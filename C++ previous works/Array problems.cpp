//Solved Problems array


#1
#include <iostream>
using namespace std;
int main()
{
    int arraysize;
    cout << "how many nubers do you want to compare? : ";
    cin >> arraysize;
    int myarray[arraysize];
    cout << "Enter numbers"<<endl;
    for(int i = 0 ; i < arraysize;i++)
        cin >> myarray[i];
    int a =myarray[0];
    for(int i =1;i<arraysize;i++)
    {
        if(myarray[i]>a)
        a = myarray[i];
    }
    cout <<"The largest number is "<< a;
    return 0;
}

#2
#include <iostream>
using namespace std;
int main()
{
	int arraysize;
    cout << "how many nubers do you want to compare? : ";
    cin >> arraysize;
    int myarray[arraysize];
    cout << "Enter numbers"<<endl;
    for(int i = 0 ; i < arraysize;i++)
        cin >> myarray[i];
    int a ;
    for(int i = 0; i < arraysize ; i++)
    for(int j = 0 ; j< i;j++)
    if( myarray[j] < myarray[i])
    {
        a = myarray[i];
        myarray[i]=myarray[j];
        myarray[j] = a;
    }
    for(int i =0 ; i < 3;i++)
    cout << myarray[i]<<"\t";
    return 0;
}

#3
#include <iostream>
using namespace std;
int main()
{
	int arraysize;
    cout << "how many nubers do you want to compare? : ";
    cin >> arraysize;
    int myarray[arraysize];
    cout << "Enter numbers"<<endl;
    for(int i = 0 ; i < arraysize;i++)
        cin >> myarray[i];
    int a ;
    for(int i = 0; i < arraysize ; i++)
    for(int j = 0 ; j< i;j++)
    if( myarray[j] < myarray[i])
    {
        a = myarray[i];
        myarray[i]=myarray[j];
        myarray[j] = a;
    }
    cout << "how many large number you want?  : ";
    int b;
    cin >> b;
    for(int i =0 ; i < b;i++)
    cout << myarray[i]<<"\t";
    return 0;
}

#4
#include <iostream>

using namespace std;

int main()
{
    int arraysize;
    cout << "how many numbers do you want to compare? : ";
    cin >> arraysize;
    int myarray[arraysize];
    cout << "Enter numbers"<<endl;
    for(int i = 0 ; i < arraysize;i++)
        cin >> myarray[i];
    int temparray[arraysize][2];
    int a =0;
    for(int i =0;i<arraysize;i++)
    {
        temparray[i][0]=myarray[i];
        for(int j =0;j<arraysize;j++)
            if(myarray[i]==myarray[j])
            a +=1;
        temparray[i][1]=a;
        a=0;
    }
    int b ;
    int c;
    for(int i = 0; i < arraysize ; i++)
    for(int j = 0 ; j< i;j++)
    if( temparray[j][1] < temparray[i][1])
    {
        b = temparray[i][0];
        c = temparray[i][1];
        temparray[i][0]=temparray[j][0];
        temparray[i][1]=temparray[j][1];
        temparray[j][0]=b;
        temparray[j][1]=c;
    }
    cout << temparray[0][0];
    return 0;
}

#5
#include <iostream>
using namespace std;

int main()
{
	int arraysize;
    cout << "how many nubers do you want to compare? : ";
    cin >> arraysize;
    int myarray[arraysize];
    cout << "Enter numbers"<<endl;
    for(int i = 0 ; i < arraysize;i++)
        cin >> myarray[i];
    int temparray[arraysize];
    for(int i =0;i<arraysize;i++)
    temparray[i]=myarray[i];
    for(int i = 1;i<arraysize-1;i++)
    myarray[i]*=(temparray[i-1]*temparray[i+1]);
    myarray[0]*=temparray[1]*temparray[arraysize-1];
    myarray[arraysize-1]*=temparray[arraysize-2]*temparray[0];
    for(int i =0;i <arraysize;i++)
    cout << myarray[i]<<"\t";
    return 0;
}

#6

#include <iostream>

using namespace std;

int main()
{
    int arraysize;
    cout << "how many numbers do you want to compare? : ";
    cin >> arraysize;
    int myarray[arraysize];
    cout << "Enter numbers"<<endl;
    for(int i = 0 ; i < arraysize;i++)
        cin >> myarray[i];
    int temparray[arraysize][2];
    int a =0;
    for(int i =0;i<arraysize;i++)
    {
        temparray[i][0]=myarray[i];
        for(int j =0;j<arraysize;j++)
            if(myarray[i]==myarray[j])
            a +=1;
        temparray[i][1]=a;
        a=0;
    }
    int b ;
    int c;
    for(int i = 0; i < arraysize ; i++)
    for(int j = 0 ; j< i;j++)
    if( temparray[j][1] < temparray[i][1])
    {
        b = temparray[i][0];
        c = temparray[i][1];
        temparray[i][0]=temparray[j][0];
        temparray[i][1]=temparray[j][1];
        temparray[j][0]=b;
        temparray[j][1]=c;
    }
    cout << temparray[0][0]<<endl;
    cout << temparray[1][0];
    return 0;
}

#7

#include <iostream>

using namespace std;

void menu();
bool check(int );

int main()
{
    int m=0,n=0,a,sum=0,sum_row=0,sum_column=0;
    int myarray[m][n],temparray[n][m];
    char checker;
    
    do
    {
        menu();
        cout << "what operation you want to do ? ";
        cin >>a;
        switch(a)
        {
            case 1:
            cout << "Enter m amount of rows :";
            cin >> m;
            cout << "Enter n amount of column : ";
            cin >>n;
            for(int i =0;i<m;i++)
            {
                cout << "Enter row " << i+1<<" elements" << endl;
                for(int j =0;j<n;j++)
                cin >> myarray[i][j];
            }
            break;
            case 2:
            if(check(m) || check(n))
            {
                cout << "No matrix entered"<<endl;
                break;
            }
            for(int i =0;i<m;i++)
            {
                for(int j =0;j<n;j++)
                cout << myarray[i][j] << "\t";
                cout << endl;
            }
            break;
            case 3:
            if(check(m) || check(n))
            {
                cout << "No matrix entered"<<endl;
                break;
            }
            for(int i =0;i<m;i++)
            {
                for(int j =0;j<n;j++)
                sum += myarray[i][j];
            }
            cout << "The sum of the matrix is "<< sum<<endl;
            break;
            case 4:
            if(check(m) || check(n))
            {
                cout << "No matrix entered"<<endl;
                break;
            }
            for(int i =0;i<m;i++)
            {
                for(int j =0;j<n;j++)
                sum_row += myarray[i][j];
                cout<<"The sum of row " << i+1<<"is "<<sum_row<< endl;
            }
            break;
            case 5:
            if(check(m) || check(n))
            {
                cout << "No matrix entered"<<endl;
                break;
            }
            for(int i =0;i<n;i++)
            {
                for(int j =0;j<m;j++)
                sum_column += myarray[j][i];
                cout<<"The sum of column " << i+1<<"is "<<sum_column<< endl;
            }
            break;
            case 6:
            if(check(m) || check(n))
            {
                cout << "No matrix entered"<<endl;
                break;
            }
            for(int j =0;j<n;j++)
            {
                for(int i =0;i<m;i++)
                cout << myarray[i][j] << "\t";
                cout << endl;
            }
            break;
            deafult :
            cout << "Not entered correct number " <<endl;
            break;
        }
        cout << "Do you want to do another operation? (Y/y): ";
        cin >> checker;
    }while((checker == 'y') || (checker == 'Y'));
    cout << "Thank you for using matric operations"<<endl;
    return 0;
}

void menu()
{
    cout << "Matric operations"<<endl;
    cout<<"1. To input elements into matrix of size m x n "<< "\n";
     cout<<"2. To display elements of matrix of size m x n" << "\n";
     cout<<"3. Sum of all elements of matrix of size m x n" << "\n";
   cout<<"4. To display row-wise sum of matrix of size m x n" << "\n";
   cout<<"5. To display column-wise sum of matrix of size m x n" << "\n";
  cout<<"6. To create transpose of matrix B of size n x m"<<endl;
  
}

bool check(int z)
{
    if(z == 0)
    return true;
    else
    return false;
}

#8
#include <iostream>
using namespace std;

int main()
{
    int m,n;
    cout << "Enter amount of rows and columns of matrix the respectively : ";
    cin >> m >>n;
    int myarray[m][n];
    for(int i =0;i<m;i++)
            {
                cout << "Enter row " << i+1<<" elements" << endl;
                for(int j =0;j<n;j++)
                cin >> myarray[i][j];
            }
    for(int i = 0; i < m ;i++)
    {
        for(int k = 0; k<=i ; k++)
            cout << ' ';
        for(int j =i;j<n;j++)
            cout << myarray[i][j];
        cout<<"\n";
    }
    return 0;
}


#9

#include <iostream>

using namespace std ;

int main()
{
    int n = 3,l=3,m=3,k=3;
    int mularray[n][m];
    cout << "Matrix multiplication"<<endl;
    cout << "Enter amount of rows and columns of matrix A respectively : ";
    cin >> n >>l;
    int A[n][l];
    for(int i =0;i<n;i++)
            {
                cout << "Enter row " << i+1<<" elements" << endl;
                for(int j =0;j<l;j++)
                cin >> A[i][j];
            }
    cout << "Enter amount of rows and columns of matrix B respectively : ";
    cin >> k >> m;
    int B[k][m];
    for(int i =0;i<k;i++)
            {
                cout << "Enter row " << i+1<<" elements" << endl;
                for(int j =0;j<m;j++)
                cin >> B[i][j];
            }
    if(k != l)
    {
        cout << "This two matrix can't be multiplied" <<endl;
    return 0;
    }
    else
    {
        cout<<"The multiplication result is "<<endl;
    for(int i = 0;i<n;i++)
    for(int j =0;j<m;j++){
    mularray[i][j]=0;
    for(int z =0; z < l;z++)
    mularray[i][j] += (A[i][z]*B[z][j]);
    }
    for(int i =0;i<n;i++)
            {
                for(int j =0;j<m;j++)
                cout << mularray[i][j] << "\t";
                cout << endl;
            }
    }
    return 0;
}