
/*****************************************************************
 *###############################################################*
 *#                                                             #*
 *#    Project: Creating a calculator for accountant using C++  #*
 *#                                                             #*
 *###############################################################*
 *****************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//Function Prototypes
void start();
void menu();
void calc_monthly_in_take(ifstream &);
void grocery_option();
void grocery_in(string, double, float);
void calcMonthlyCost(ifstream &);
void grocery_menu();
void calculation_option();
void calcmenu();
int sum(int, int);
int difference(int, int);
int multiplication(int, int);
float division(int, int);
int quetient(int, int);
float sqr_root_ofNumber(int);

//Structure called Grocery
struct grocery
{
    string itemName;
    double dailyIntake;
    float unitPrice;
    double monthlyIntake;
    float monthlyCost;
};

int main()
{
    start();
    return 0;
}

//Start function
void start()
{
    int option;
    char choice;
    //a do while that display main menu
    do
    {
        menu();
        cout << "Please specify your choice: ";
        cin >> option;
        switch (option)
        {
        case 1:
            grocery_option();
            break;
        case 2:
            calculation_option();
            break;
        case 3:
            cout << "good bye!" << endl;
            exit(0);
            break;
        deafult:
            cout << "Incorrect option" << endl;
            break;
        }
        cout << "Do you want to perform another operation yes(Y/y) no(N/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "Good Bye!" << endl;
}

void menu()
{
    cout << "\n Here are operations for accountant" << endl;
    cout << "\t 1.Read file contents(Enter File Content)" << endl;
    cout << "\t 2.Enter from the keyboard(Calculator)" << endl;
}

//Grocery Part
void grocery_option()
{
    ifstream inFile;
    ofstream oFile;
    int option, amount;
    string itemName;
    double daily_in_take;
    float costs;
    do
    {
        grocery_menu();
        cout << " Enter your option: ";
        cin >> option;
        //Used if rather than switch to have less code
        if (option == 2 || option == 1)
        {
            //the function that makes option 2 diffrent
            if (option == 2)
            {
                oFile.open("grocery.txt");
                oFile.close();
                cout << "How many items you want to enter: ";
                cin >> amount;
                cout << setiosflags(ios::left)
                     << setw(20) << "Item"
                     << setw(20) << "Daily In Take(kg)"
                     << setw(20) << "Unit price per kg" << endl;
                for (int i = 0; i < amount; i++)
                {
                    cin >> itemName >> daily_in_take >> costs;
                    grocery_in(itemName, daily_in_take, costs);
                }
            }
            //file checker
            inFile.open("grocery.txt");
            if (inFile.fail())
            {
                cout << "file not found please enter items manually"<<endl;
                break;
            }
            calc_monthly_in_take(inFile);
            inFile.close();
            inFile.open("grocery_cost.txt");
            calcMonthlyCost(inFile);
            inFile.close();
        }
        else if (option != 3)
            cout << "Incorrect choice, Try again" << endl;
    } while (option != 3);
}
void grocery_menu()
{
    cout << "\n Grocery Calculator \n"
         << "\t 1. Use \"grocery.txt\" File \n"
         << "\t 2. Enter Manually \n"
         << "\t 3. quit " << endl;
}
void grocery_in(string itemName, double daily_in_take, float costs)
{
    ifstream re_data;
    ofstream wr_data;
    re_data.open("grocery.txt");
    re_data.get();
    //check grocerry.txt file
    bool check = re_data.fail() || re_data.eof();
    if (check)
    {
        wr_data.open("grocery.txt");
        wr_data << setiosflags(ios::left)
                << setw(20) << "Item"
                << setw(20) << "Daily In Take(kg)"
                << setw(20) << "Unit price per kg" << endl;
        wr_data.close();
    }
    re_data.close();
    wr_data.open("grocery.txt", ios::app);
    wr_data << setiosflags(ios::left)
            << setw(20) << itemName
            << setw(20) << daily_in_take
            << costs << endl;
    wr_data.close();
}
void calc_monthly_in_take(ifstream &inFile)
{
    string temp;
    string months[]{"January", "February", "March", "April",
                    "May", "June", "July", "August",
                    "September", "October", "November", "December"};
    int sizearray=0, day, month, year, width = 20;
    //code to check file line amount
    while (inFile.peek() != EOF)
    {
        getline(inFile, temp);
        sizearray++;
    }
    sizearray -= 1;
    inFile.clear();
    inFile.seekg(0);
    grocery item_cost[sizearray];
    getline(inFile, temp);
    for (int i = 0; i < sizearray; i++)
        inFile >> item_cost[i].itemName >> item_cost[i].dailyIntake >> item_cost[i].unitPrice;
    //know which month it is for day amount
    cout << "Enter needed month(in number) & year: ";
    cin >> month >> year;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        day = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        day = 30;
        break;
    case 2:
        if (year % 4 == 0)
            day = 29;
        else
            day = 28;
        break;
    }

    for (int i = 0; i < sizearray; i++)
        item_cost[i].monthlyIntake = item_cost[i].dailyIntake * day;
    for (int i = 0; i < sizearray; i++)
        item_cost[i].monthlyCost = item_cost[i].monthlyIntake * item_cost[i].unitPrice;
    //write column content
    ofstream outFile;
    outFile.open("grocery_cost.txt");
    outFile << "The cost for month of " << months[month - 1] << " of year " << year << endl;
    outFile << setiosflags(ios::left)
            << setw(width) << "Item"
            << setw(width) << "Daily In Take(kg)"
            << setw(width) << "Cost"
            << setw(width) << "Monthly Intake"
            << setw(width) << "Monthly Cost" << endl;
    //print column content
    cout << "\n The cost for month of " << months[month - 1] << " of year " << year << endl;
    cout << setiosflags(ios::left)
         << setw(width) << "Item"
         << setw(width) << "Daily In Take(kg)"
         << setw(width) << "Cost"
         << setw(width) << "Monthly Intake"
         << setw(width) << "Monthly Cost" << endl;
    for (int i = 0; i < sizearray; i++)
    {
        //print array to file
        cout << setiosflags(ios::left)
             << setw(width) << item_cost[i].itemName
             << setw(width) << item_cost[i].dailyIntake
             << setw(width) << item_cost[i].unitPrice
             << setw(width) << item_cost[i].monthlyIntake
             << setw(width) << item_cost[i].monthlyCost << endl;
        //write array to file
        outFile << setiosflags(ios::left)
                << setw(width) << item_cost[i].itemName
                << setw(width) << item_cost[i].dailyIntake
                << setw(width) << item_cost[i].unitPrice
                << setw(width) << item_cost[i].monthlyIntake
                << setw(width) << item_cost[i].monthlyCost << endl;
    }
}
void calcMonthlyCost(ifstream &inFile)
{
    string temp, month;
    int year, line=0;
    double total_cost = 0,tempnum;
    //know amount of line
    while (inFile.peek() != EOF)
    {
        getline(inFile, temp);
        line++;
    }
    //deduct last line and first line cause we don't need them
    line -= 2;
    float item_cost[line];
    inFile.clear();
    inFile.seekg(0);
    inFile >> temp >> temp >> temp >> temp >> temp;
    inFile >> month;
    inFile >> temp >> temp;
    inFile >> year;
    inFile >> temp >> temp >> temp >> temp >> temp>>temp>>temp>>temp>>temp;
    for (int i = 0; i < line; i++)
    {
       inFile >>temp >> tempnum
               >> tempnum >> tempnum
               >> item_cost[i];
    }
    for(int i =0; i<line;i++)
        total_cost = total_cost+item_cost[i];
    cout << "Total cost of " << month << " of year "
         << year << " is " << total_cost << endl;
}

//Calculator Part
void calculation_option()
{
    char option;
    int num = 0, total_num;
    do
    {
        calcmenu();
        cout << "Please specify your choice: ";
        cin >> option;
        switch (option)
        {
        case '+':
            cout << "How many numbers you want add: ";
            cin >> total_num;
            num = sum(total_num, num);
            break;
        case '-':
            cout << "How many numbers you want substract: ";
            cin >> total_num;
            num = difference(total_num, num);
            break;
        case '*':
            cout << "How many numbers you want multiply: ";
            cin >> total_num;
            num = multiplication(total_num, num);
            break;
        case '/':
            if (num == 0)
            {
                cout << "Enter dividend: ";
                cin >> num;
            }
            cout << "By what you want to divide: ";
            cin >> total_num;
            num = division(total_num, num);
            break;
        case '%':
            if (num == 0)
            {
                cout << "Enter dividend: ";
                cin >> num;
            }
            cout << "By what you want to divide: ";
            cin >> total_num;
            num = quetient(total_num, num);
            break;
        case '^':
            if (num == 0)
            {
                cout << "Enter number: ";
                cin >> num;
            }
            num = sqr_root_ofNumber(num);
            break;
        case 'c':
            num = 0;
            cout << "cleared \n";
            break;
        default:
            (option != 'q') ? cout << "Incorrect option \n" : cout << " good bye! \n";
            break;
        }
    } while (option != 'q');
}
void calcmenu()
{
    cout << "\n Calculator" << endl;
    cout << "Here are your operations" << endl;
    cout << "\t ' + ' Addition \n"
         << "\t ' - ' Subtraction \n"
         << "\t ' * ' Multiplication \n"
         << "\t ' / ' Division \n"
         << "\t ' % ' Module \n"
         << "\t ' ^ ' Square root \n"
         << "\t ' c ' Clear \n"
         << "\t ' q ' Quit \n";
}
int sum(int total_num, int old_num)
{
    int temp[total_num];
    int count = 0, sum = 0, num;
    do
    {
        cout << "Please enter the number " << count + 1 << " : ";
        cin >> num;
        temp[count] = num;
        count++;
        sum += num;
    } while (count < total_num);
    cout << "You entered: " << temp[0];
    for (int k = 1; k < total_num - 1; k++)
        cout << ", " << temp[k];
    cout << " and " << temp[total_num - 1];
    cout << "\nThe sum of these numbers ";
    if (old_num != 0)
    {
        sum += old_num;
        cout << " on " << old_num;
    }
    cout << " is " << sum << endl;
    return sum;
}
int difference(int total_num, int old_num)
{
    int temp[total_num];
    int count = 0, diff = 0, num;
    do
    {
        cout << "Please enter the number " << count + 1 << " : ";
        cin >> num;
        temp[count] = num;
        count++;
        diff -= num;
    } while (count < total_num);
    cout << "You entered: " << temp[0];
    for (int k = 1; k < total_num - 1; k++)
        cout << ", " << temp[k];
    cout << " and " << temp[total_num - 1];
    cout << "\t the subtract of these numbers ";
    diff += old_num;
    cout << " from " << old_num;
    cout << " is " << diff << endl;
    return diff;
}
int multiplication(int total_num, int old_num)
{
    int temp[total_num];
    int count = 0, mul = 1, num;
    do
    {
        cout << "Please enter the number " << count + 1 << " : ";
        cin >> num;
        temp[count] = num;
        count++;
        mul *= num;
    } while (count < total_num);
    cout << "You entered: " << temp[0];
    for (int k = 1; k < total_num - 1; k++)
        cout << ", " << temp[k];
    cout << " and " << temp[total_num - 1];
    cout << " the multiply of these numbers ";
    if (old_num != 0)
    {
        mul *= old_num;
        cout << " on " << old_num;
    }
    cout << " is " << mul << endl;
    return mul;
}
float division(int div_num, int old_num)
{
    float div = old_num / div_num;
    cout << "The Division of " << old_num << " by "
         << div_num << " is " << div << endl;
    return div;
}
int quetient(int div_num, int old_num)
{
    float rem = old_num % div_num;
    cout << "The Reminder of " << old_num << " by "
         << div_num << " is " << rem << endl;
    return rem;
}
float sqr_root_ofNumber(int num)
{
    // using Heron's method(https://en.m.wikipedia.org/wiki}/Methods_of_computing_square_roots)
    float estimate = 0, temp;
    while ((estimate * estimate) < num)
        estimate += 1;
    temp = estimate - 1;
    temp = estimate - 1 + ((estimate * estimate - temp * temp) / 2);
    if (num < temp)
        estimate = estimate - 1;
    estimate = estimate * 10 * 10;
    do
    {
        temp = estimate;
        estimate = (estimate + num / estimate) / 2;
        temp -= estimate;
    } while (temp > 0.0001);
    cout << "The square root of " << num << " is " << estimate << endl;
    return estimate;
}
