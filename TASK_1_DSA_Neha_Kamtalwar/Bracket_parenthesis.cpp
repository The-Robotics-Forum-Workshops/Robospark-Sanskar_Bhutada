#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool Pair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}
bool BalancedParantheses(string exp)
{
	stack<char>  S;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(S.empty() || !Pair(S.top(),exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true:false;
}

int main()
{
	
	
	string expression;
	cout<<"Enter an expression:  "; 
	cin>>expression;
	
	if(BalancedParantheses(expression))
		cout<<"Parantheses are Balanced\n";
	
	else
		cout<<"Parantheses are not Balanced\n";
}
