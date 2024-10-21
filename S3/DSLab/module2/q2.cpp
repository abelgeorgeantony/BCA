#include<iostream>
#include<stack>
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

int precedence(char c)
{
	if(c== '^')
		return 3;
	else if(c== '*' || c== '/')
		return 2;
	else if(c == '+' || c== '-')
		return 1;
	else
		return -1;
}

string infixtopostfix(stack<char> s, string infix)
{
	string postfix;
	for(int i=0;i<infix.length();i++)
	{
		if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
		{
			postfix+=infix[i];
		}
		else if(infix[i]=='(')
		{
			s.push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while((s.top()!='(') && (!s.empty()))
			{
				postfix+=s.top();
				s.pop();
			}
			s.pop();
		}
		else if(isOperator(infix[i]))
		{
			if(s.empty())
			{
				s.push(infix[i]);
			}
			else if(precedence(infix[i])>=precedence(s.top()))
			{
				s.push(infix[i]);
			}
			else if(precedence(infix[i])<precedence(s.top()))
			{
				postfix+=s.top();
				s.pop();
				s.push(infix[i]);
			}
		}
	}
	return postfix;
}

int main()
{
	string infix_exp,postfix_exp;
	stack <char> stack;
	cout<<"Enter infix expression: ";
	cin>>infix_exp;
	cout<<"Infix expression: "<<infix_exp<<"\n";
	postfix_exp=infixtopostfix(stack,infix_exp);
	cout<<"Postfix expression: "<<postfix_exp;
	cout<<"\n";
	return 0;
}
