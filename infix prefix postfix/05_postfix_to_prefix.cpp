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
string postfixToPrefix(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            string s1(1, postfix[i]);
            s.push(s1);
        }
        else
        {
            //for operator
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string expression = postfix[i] + op2 + op1;
            s.push(expression);
        }
    }
    return s.top();
}
int main()
{
    string postfix, prefix;
    cout << "Enter a POSTFIX Expression: " << endl;
    cin >> postfix;
    cout << "POSTFIX Expression: " << postfix << endl;
    prefix = postfixToPrefix(postfix);
    cout << "PREFIX Expression: " << prefix << endl;

    return 0;
}