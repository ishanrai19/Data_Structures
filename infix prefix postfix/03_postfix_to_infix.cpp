#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
string postfixToInfix(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            string s1(1, postfix[i]);
            /* string s1=postfix[i];
            invalid conversion*/
            s.push(s1);
        }
        else
        {
            //for operator
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string expression = '(' + op2 + postfix[i] + op1 + ')';
            s.push(expression);
        }
    }
    return s.top();
}
int main()
{
    string infix, postfix;
    cout << "Enter a POSTFIX Expression: " << endl;
    cin >> postfix;
    cout << "POSTFIX Expression: " << postfix << endl;
    infix = postfixToInfix(postfix);
    cout << "INFIX Expression: " << infix << endl;

    return 0;
}