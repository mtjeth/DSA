#include<iostream>

using namespace std;

struct node
{
	char opr;
	struct node* next;
}*head=NULL;

string changer(string);
void push(char);
char pop();
bool isempty();
char top();
int priority(char);
int type(char);

int main()
{
	cout << "Given Infix examples are:- \n\t A.\t(A+B)/C-D/F*E \n\t B.\t A/B*C/D+D*F-(L+K) \n\t C.\t (A+B)*C-(D-E)*(F+G)" << endl;
	cout << "There postfix is:- ";
	cout << "\n\t A.\t" << changer("(A+B)/C-D/F*E");
	cout << "\n\t B.\t" << changer("A/B*C/D+D*F-(L+K)");
	cout << "\n\t C.\t" << changer("(A+B)*C-(D-E)*(F+G)");

}

string changer(string infix)
{
	string postfix;
	infix += ')';
	push('(');
	postfix = "";
	for(int i=0;i<infix.length();i++)
	{
		switch (type(infix[i]))
		{
		case 1:
			postfix += infix[i];
			break;
		case 3:
			if (infix[i] == '(')
			{
				push('(');
			}
			else
			{
				while (!isempty() && top() != '(')
				{
					postfix += pop();
				}
				if (top() == '(')
					pop();
			}

			break;
		case 2:
			if (head==NULL || top() == '(')
			{
				push(infix[i]);
				postfix += ' ';
			}
			else
			{
				while (!isempty() && (top() != '(') && priority(infix[i]) <= priority(top()))
					postfix += pop();
				push(infix[i]);
				if (priority(infix[i]) > priority(top()))
				{
					push(infix[i]);
					postfix += ' ';
				}
			}
			break;
		case 4:
			break;
		default:
			cout << "conversion error";
			exit(0);
			break;
		}
	}
	while (!isempty())
	{
		if (top() == '(')
			 pop();
		else
			postfix +=pop();
	}
	return postfix;
}

void push(char opr)
{
	struct node* newnode = new node;
	newnode->opr = opr;
	newnode->next = head;
	head = newnode;
}
char pop()
{
	if (head == NULL)
	{
		cout << "Stack Underflow" << endl;
		exit(0);
	}
	char temp = head->opr;
	head = head->next;
	return temp;
}
char top()
{
	if(head == NULL)
	{
		cout << "Empty stack access";
		exit(0);
	}
	return head->opr;
}
bool isempty()
{
	if (head == NULL)
		return true;
	return false;
}
int priority(char opr)
{
	switch (opr)
	{
	case '+':
	case '-':
		return 1;
		break;
	case '*':
	case '/':
		return 2;
		break;
	case '^':
		return 3;
		break;
	default:
		cout << "Priority error";
		exit(0);
		break;
	}
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
