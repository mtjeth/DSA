#include <iostream>

using namespace std;

struct node
{
    string opr;
    struct node *next;
} *head = NULL;

int priority(char op)
{
    if (op == '^')
        return 3;
    if (op == '/' || op == '*')
        return 2;
    if (op == '+' || op == '-')
        return 1;
}

int type(char variable)
{
    if ((variable >= 'A' && variable <= 'Z') || (variable >= 'a' && variable <= 'z') || (variable >= '0' && variable <= '9'))
        return 1;
    else if (variable == '+' || variable == '-' || variable == '*' || variable == '/' || variable == '^')
        return 2;
    else if (variable == '(' || variable == ')')
        return 3;
    else if (variable == ' ')
        return 4;
    else
    {
        cout << "Unknown variable";
        exit(0);
        return 0;
    }
}

void push(string opr)
{
    struct node *newnode = new node;
    newnode->opr = opr;
    newnode->next = head;
    head = newnode;
}
string pop()
{
    if (head == NULL)
    {
        cout << "Stack Underflow" << endl;
        exit(0);
    }
    string temp = head->opr;
    head = head->next;
    return temp;
}

void reverser(string *str)
{
    string rev = "";
    for (int i = (*str).length() - 1; i >= 0; i--)
        rev += (*str)[i];
    (*str) = rev;
}

string changer(string prefix)
{
    string temp, a;
    reverser(&prefix);
    for (int i = 0; i < prefix.length(); i++)
    {
        if (type(prefix[i]) == 1)
        {
            a = prefix[i];
            push(a);
        }
        else if (type(prefix[i]) == 2)
        {
            temp = '(';
            temp += pop();
            temp += (prefix[i]);
            temp += pop();
            temp += ')';
            push(temp);
            temp = "";
        }
        else if (type(prefix[i]) == 4)
            continue;
    }
    string infix = pop();
    return infix;
}

int main()
{
    cout << "Given Prefix examples are:- \n\t A.\t *-A/BC-/AKL \n\t B.\t +*AB*CD \n\t C.\t *+AB*CD" << endl;
    cout << "There infix is:- ";
    cout << "\n\t A.\t" << changer("*-A/BC-/AKL");
    cout << "\n\t B.\t" << changer("+*AB*CD");
    cout << "\n\t C.\t" << changer("*+AB*CD");
}
