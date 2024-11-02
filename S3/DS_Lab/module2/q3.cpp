#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

bool isOperator(char c)
{
	if(c=='+' || c=='-' ||c=='*' || c=='/' || c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}
int postfixeval(string postfix)
{
	stack <int> s;
	int num;
	for(int i=0;i<postfix.length();i++)
	{
		if(isdigit(postfix[i]))
		{
			s.push(postfix[i]-'0');
		}
		else if(postfix[i]==' ')
		{
			continue;
		}
		else if(isOperator(postfix[i]))
		{
			int a=s.top();
			s.pop();
			int b=s.top();
			s.pop();
			switch(postfix[i])
			{
				case '+':
					s.push(a+b);
					break;
				case '-':
					s.push(b-a);
					break;
				case '*':
					s.push(a*b);
					break;
				case '/':
					s.push(b/a);
					break;
				case '^':
					s.push(pow(a,b));
					break;
			}
		}
	}
	return s.top();
}

int main()
{
	string postfix_exp;
	cout<<"Enter postfix expression: ";
	getline(cin,postfix_exp);
	cout<<"\nValue of expression: ";
	cout<<postfixeval(postfix_exp);
    return 0;
}

