//Sort and Search

#include <iostream>
using namespace std;

void menu();
void linearsearch(int [],int,int);
void binarysearch(int [],int,int);
void insertionsort(int [],int);
void selectionsort(int [],int);
void bubblesort(int [],int );
void printarraypointer(int *,int );

int main()
{
    int myarraysize ;
    int userinput;
    menu();
    cout << "Enter choice : ";
    cin >> userinput;
    cout << "Enter size of array : ";
    cin >> myarraysize;
    int myarray[myarraysize];
    int value;
    int *ptr = &myarray[0];
    cout<<"Enter elements of the array"<<endl;
    for(int i =0;i<myarraysize;i++)
    cin >> myarray[i];
    switch(userinput)
    {
        case 1:
        cout << "Which element index are you looking for ? ";
        cin >> value;
        linearsearch(myarray,myarraysize,value);
        break;
        case 2:
        cout << "Which element index are you looking for ? ";
        cin >> value;
        binarysearch(myarray,myarraysize ,value);
        break;
        case 3:
        insertionsort(myarray,myarraysize);
        break;
        case 4:
        selectionsort(myarray,myarraysize);
        break;
        case 5:
        bubblesort(myarray,myarraysize);
        break;
        case 6:
        printarraypointer(ptr,myarraysize);
        break;
        deafult:
        cout << "Invalid Input";
    }
    return 0;
}

void menu()
{
    cout << "Here are your options : \n";
    cout << "\t 1.Linear Search \n";
    cout << "\t 2.Bubble Search(works for sorted index) \n";
    cout << "\t 3.Inseartion Sort \n";
    cout << "\t 4.Selection Sort\n";
    cout << "\t 5.Bubble Sort \n";
    cout << "\t 6.Print Array Elements Using Pointer" << endl;
}

void linearsearch(int list[],int size,int key)
{
    cout << "Using Linear Search"<<endl;
    int result=-1 ;
    for(int i =0; i < size;i++)
    if(list[i]==key){
    result = i;
    break;}
    (result > -1) ? cout<<"your inserted element  "<< key<<" is found  at index "<< result <<endl : cout<<"your inserted element "<< key<<" is not found" <<endl;
}

void binarysearch(int list[],int size,int key)
{
    cout << "Using Binary Search"<<endl;
    int left = 0,right=size-1,midpt,result;
    while(left <= right)
    {
        midpt = (list[right]+list[left])/2;
        if(list[midpt]==key)
        {
            result = midpt;
            break;
        }
        else if(key> list[midpt])
        left = midpt+1;
        else
        right = midpt-1;
    }
    if(list[midpt] != key)
    result = -1;
    (result > -1) ? cout<<"your inserted element  "<< key<<" is found  at index "<< result <<endl : cout<<"your inserted element "<< key<<" is not found" <<endl;
}
void insertionsort(int list[],int size)
{
    int swap;
    for(int i =1;i<size;i++)
    while(list[i] < list[i-1])
    {
        swap = list[i];
        list[i] = list[i-1];
        list[i-1] = swap;
        i --;
    }
    cout << "Using Insertion sort"<<endl;
    for(int i=0;i< size;i++)
    cout << list[i] <<" \t";
}
void selectionsort(int list[],int size)
{
    int a;
    int b;
    for(int i= 0;i <size;i++)
    {
        a=list[i];
    for(int j = i+1;j<size;j++)
    if(list[j]<a)
    {
    a=list[j];
    b = j;
    }
    list[b]=list[i];
    list[i]=a;
    }
    cout << "Using Selection sort"<<endl;
    for(int i=0;i< size;i++)
    cout << list[i] <<" \t";
}
void bubblesort(int list[],int size)
{
    int a;
    for(int i =1;i<size;i++)
    for(int k=0;k<i;k++)
        if(list[i]<list[k])
        {
            a = list[i];
            list[i] = list[k];
            list[k]=a;
            }
    cout << "Using Bubble sort"<<endl;
    for(int i=0;i< size;i++)
    cout << list[i] <<" \t";
}
void printarraypointer(int *ptr,int size)
{
    for(int i =0 ;i<size;i++)
    cout << *(ptr+i)<<"\t";
}