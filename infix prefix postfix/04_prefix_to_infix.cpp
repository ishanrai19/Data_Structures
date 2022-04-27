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
string prefixToInfix(string prefix)
{
    stack<string> s;
    for (int i = (prefix.length() - 1); i >= 0; i--)
    {
        if (isOperand(prefix[i]))
        {
            string s1(1, prefix[i]);
            s.push(s1);
        }
        else
        {
            //for operator
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string expression = '(' + op1 + prefix[i] + op2 + ')';
            s.push(expression);
        }
    }
    return s.top();
}
int main()
{
    string infix, prefix;
    cout << "Enter a PREFIX Expression: " << endl;
    cin >> prefix;
    cout << "PREFIX Expression: " << prefix << endl;
    infix = prefixToInfix(prefix);
    cout << "INFIX Expression: " << infix << endl;

    return 0;
}