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
string prefixToPostfix(string prefix)
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
            string expression = op1 + op2 + prefix[i];
            s.push(expression);
        }
    }
    return s.top();
}
int main()
{
    string postfix, prefix;
    cout << "Enter a PREFIX Expression: " << endl;
    cin >> prefix;
    cout << "PREFIX Expression: " << prefix << endl;
    postfix = prefixToPostfix(prefix);
    cout << " POSTFIX Expression: " << postfix << endl;

    return 0;
}